#include <intcode_computer.h>

#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <functional>

using namespace std::placeholders;

Output default_output() {
  return [](int64_t out) { std::cout << out << std::endl; };
}

Input default_input() {
  return [] {
    int64_t i = 0;
    std::cout << "requesting user input: ";
    std::cin >> i;
    return i;
  };
}

Input const_input(int64_t in) {
  return [=] { return in; };
}

Output output_to(int64_t* out) {
  return [=](int64_t o) { *out = o; };
}

Input input_from(int64_t* in) {
  return [=] { return *in; };
}

MODE get_mode(int64_t param_pos, Modes modes) {
  return MODE(modes.at(param_pos) - '0');
}

std::string min_sz_str(int64_t input) {
  std::stringstream ss;
  ss << std::setw(32) << std::setfill('0') << input;
  return ss.str();
}

Modes get_modes(int64_t input) {
  std::string str = min_sz_str(input);
  Modes m = str.substr(0, str.size() - 2);
  std::reverse(m.begin(), m.end());
  return m;
}

int64_t get_opcode(int64_t input) {
  std::string str = min_sz_str(input);
  return std::stoi(str.substr(str.size() - 2, str.size() - 1));
}

IntCodeComputer::IntCodeComputer(size_t init_mem_size, Output out, Input in)
    : pointer_(0),
      rel_base_(0),
      mem_(init_mem_size, 0),
      input_(in),
      output_(out) {}

IntCodeComputer::IntCodeComputer(size_t init_mem_size)
    : pointer_(0),
      rel_base_(0),
      mem_(init_mem_size, 0),
      input_(default_input()),
      output_(default_output()) {}

void IntCodeComputer::install_program(Memory const& mem) {
  for (size_t index = 0; index < mem.size(); index++) {
    if (index >= mem_.size())
      throw std::runtime_error("not enough memory, aborting!");
    mem_.at(index) = mem.at(index);
  }
}

int64_t IntCodeComputer::get_value(MODE mode, Pointer pointer) {
  int64_t addr = 0;
  switch (mode) {
    case MODE_POSITIONAL:
      addr = mem_.at(pointer);
      return mem_.at(addr);
      break;
    case MODE_IMMEDIATE:
      return mem_.at(pointer);
      break;
    case MODE_RELATIVE:
      addr = mem_.at(pointer);
      addr = rel_base_ + addr;
      return mem_.at(addr);
      break;
  }
  throw std::runtime_error("unknown mode, aborting!");
}

void IntCodeComputer::set_value(int64_t val, MODE mode, Pointer pointer) {
  int64_t addr = 0;
  switch (mode) {
    case MODE_POSITIONAL:
    case MODE_IMMEDIATE:
      addr = mem_.at(pointer);
      break;
    case MODE_RELATIVE:;
      addr = rel_base_ + mem_.at(pointer);
      break;
  }
  mem_.at(addr) = val;
}

bool IntCodeComputer::run(int64_t op_to_pause_at) {
  while (pointer_ < mem_.size()) {
    int64_t input = mem_.at(pointer_);
    // std::cout << "INPUT: " << input << std::endl;
    int64_t op_code(get_opcode(input));
    Modes modes(get_modes(input));
    // std::cout << "OP_CODE: " << op_code << std::endl;
    // std::cout << "MODES: " << modes << std::endl;
    switch (op_code) {
      case 1:
        add(modes);
        break;
      case 2:
        multiply(modes);
        break;
      case 3:
        in(modes);
        break;
      case 4:
        out(modes);
        break;
      case 5:
        jump_if_true(modes);
        break;
      case 6:
        jump_if_false(modes);
        break;
      case 7:
        less_than(modes);
        break;
      case 8:
        equal(modes);
        break;
      case 9:
        set_relative_base(modes);
        break;
      case 99:
        return true;
        break;
      default:
        throw std::runtime_error("unknown opcode " + std::to_string(op_code) +
                                 ", aborting!");
        break;
    }
    if (op_code == op_to_pause_at) {
      return false;
    }
  }
  return true;  // reached memory end
}

void IntCodeComputer::multiply(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  int64_t b = get_value(get_mode(1, modes), pointer_ + 2);
  set_value(a * b, get_mode(2, modes), pointer_ + 3);
  pointer_ += 4;
}

void IntCodeComputer::add(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  int64_t b = get_value(get_mode(1, modes), pointer_ + 2);
  set_value(a + b, get_mode(2, modes), pointer_ + 3);
  pointer_ += 4;
}

void IntCodeComputer::jump_if_true(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  int64_t b = get_value(get_mode(1, modes), pointer_ + 2);
  if (a != 0)
    pointer_ = b;
  else
    pointer_ += 3;
}

void IntCodeComputer::jump_if_false(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  int64_t b = get_value(get_mode(1, modes), pointer_ + 2);
  if (a == 0)
    pointer_ = b;
  else
    pointer_ += 3;
}

void IntCodeComputer::less_than(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  int64_t b = get_value(get_mode(1, modes), pointer_ + 2);
  if (a < b)
    set_value(1, get_mode(2, modes), pointer_ + 3);
  else
    set_value(0, get_mode(2, modes), pointer_ + 3);
  pointer_ += 4;
}

void IntCodeComputer::equal(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  int64_t b = get_value(get_mode(1, modes), pointer_ + 2);
  if (a == b)
    set_value(1, get_mode(2, modes), pointer_ + 3);
  else
    set_value(0, get_mode(2, modes), pointer_ + 3);
  pointer_ += 4;
}

void IntCodeComputer::set_relative_base(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  rel_base_ += a;
  pointer_ += 2;
}

void IntCodeComputer::in(Modes const& modes) {
  int64_t in = 0;
  if (istack_.size() == 0) {
    in = input_();
  } else {
    in = istack_.front();
    istack_.pop_front();
  }
  set_value(in, get_mode(0, modes), pointer_ + 1);
  pointer_ += 2;
}

void IntCodeComputer::out(Modes const& modes) {
  int64_t a = get_value(get_mode(0, modes), pointer_ + 1);
  ostack_.push_back(a);
  output_(a);
  pointer_ += 2;
}

void IntCodeComputer::push_input_stack(int64_t input) {
  istack_.push_back(input);
}
int64_t IntCodeComputer::output_stack_back() { return ostack_.back(); }