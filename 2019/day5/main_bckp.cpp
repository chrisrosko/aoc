#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>

using Tape = std::vector<int>;
using OpFunc = std::function<void(int, std::string const&, Tape&, int&)>;

struct OpCode {
  std::string mode;
  int code;
};

OpCode get_op_code(std::string const& input) {
  std::stringstream ss;
  ss << std::setw(32) << std::setfill('0') << input;
  std::string str = ss.str();

  return {str.substr(0, str.size() - 2),
          std::stoi(str.substr(str.size() - 2, str.size() - 1))};
}

bool mode(std::string const& mode_str, int param_pos) {
  std::bitset<32> bits(mode_str);
  return bits.test(param_pos);
}

int get_input(bool is_immediate, int pos, Tape& tape) {
  if (is_immediate)
    return tape.at(pos);
  else {
    int addr = tape.at(pos);
    return tape.at(addr);
  }
}

void multiply(int curr_pos, std::string const& mode_str, Tape& tape,
              int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  tape.at(out) = a * b;
  pointer += 4;
}

void add(int curr_pos, std::string const& mode_str, Tape& tape, int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  tape.at(out) = a + b;
  pointer += 4;
}

void in(int curr_pos, std::string const&, Tape& tape, int& pointer) {
  int a = get_input(true, curr_pos + 1, tape);
  int in = 0;
  std::cout << "Enter input: ";
  std::cin >> in;
  tape.at(a) = in;
  pointer += 2;
}

void jump_if_true(int curr_pos, std::string const& mode_str, Tape& tape,
                  int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  if (a != 0)
    pointer = b;
  else
    pointer += 3;
}

void jump_if_false(int curr_pos, std::string const& mode_str, Tape& tape,
                   int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  if (a == 0)
    pointer = b;
  else
    pointer += 3;
}

void less_than(int curr_pos, std::string const& mode_str, Tape& tape,
               int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  if (a < b)
    tape.at(out) = 1;
  else
    tape.at(out) = 0;
  pointer += 4;
}

void equal(int curr_pos, std::string const& mode_str, Tape& tape,
           int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  if (a == b)
    tape.at(out) = 1;
  else
    tape.at(out) = 0;
  pointer += 4;
}

void out(int curr_pos, std::string const& mode_str, Tape& tape, int& pointer) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  std::cout << "output: " << a << std::endl;
  pointer += 2;
}

std::map<int, OpFunc> OP_MAP = {
    {1, add},          {2, multiply},      {3, in},        {4, out},
    {5, jump_if_true}, {6, jump_if_false}, {7, less_than}, {8, equal}};

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/zr0395/git/aoc/2019/day5/input.json");
  std::vector<int> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  int pointer = 0;
  while (pointer < input.size()) {
    auto op_code = get_op_code(std::to_string(input.at(pointer)));
    if (op_code.code == 99) break;
    OP_MAP.at(op_code.code)(pointer, op_code.mode, input, pointer);
  }

  return 0;
}
