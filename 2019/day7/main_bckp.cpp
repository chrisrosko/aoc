#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <algorithm>

using Tape = std::vector<int>;
using IO = std::list<int>;
using OpFunc = std::function<void(int, std::string const&, Tape&, int&, IO&)>;

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

// OPERATIONS

void multiply(int curr_pos, std::string const& mode_str, Tape& tape,
              int& pointer, IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  tape.at(out) = a * b;
  pointer += 4;
}

void add(int curr_pos, std::string const& mode_str, Tape& tape, int& pointer,
         IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  tape.at(out) = a + b;
  pointer += 4;
}

void in(int curr_pos, std::string const&, Tape& tape, int& pointer, IO& io) {
  int a = get_input(true, curr_pos + 1, tape);
  int in = io.front();
  tape.at(a) = in;
  io.pop_front();
  pointer += 2;
}

void jump_if_true(int curr_pos, std::string const& mode_str, Tape& tape,
                  int& pointer, IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  if (a != 0)
    pointer = b;
  else
    pointer += 3;
}

void jump_if_false(int curr_pos, std::string const& mode_str, Tape& tape,
                   int& pointer, IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  if (a == 0)
    pointer = b;
  else
    pointer += 3;
}

void less_than(int curr_pos, std::string const& mode_str, Tape& tape,
               int& pointer, IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  if (a < b)
    tape.at(out) = 1;
  else
    tape.at(out) = 0;
  pointer += 4;
}

void equal(int curr_pos, std::string const& mode_str, Tape& tape, int& pointer,
           IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  int b = get_input(mode(mode_str, 1), curr_pos + 2, tape);
  int out = get_input(true, curr_pos + 3, tape);
  if (a == b)
    tape.at(out) = 1;
  else
    tape.at(out) = 0;
  pointer += 4;
}

void out(int curr_pos, std::string const& mode_str, Tape& tape, int& pointer,
         IO& io) {
  int a = get_input(mode(mode_str, 0), curr_pos + 1, tape);
  io.push_back(a);
  pointer += 2;
}

// OPERATIONS MAP

std::map<int, OpFunc> OP_MAP = {
    {1, add},          {2, multiply},      {3, in},        {4, out},
    {5, jump_if_true}, {6, jump_if_false}, {7, less_than}, {8, equal}};

class Amp {
 public:
  Amp(Tape const& tape, IO& io);
  bool run();

 private:
  IO& io_;
  Tape tape_;
  int pointer_;
};

Amp::Amp(Tape const& tape, IO& io) : tape_(tape), io_(io), pointer_(0) {
  auto op_code = get_op_code(std::to_string(tape_.at(pointer_)));
  OP_MAP.at(op_code.code)(pointer_, op_code.mode, tape_, pointer_, io_);
}

bool Amp::run() {
  while (pointer_ < tape_.size()) {
    auto op_code = get_op_code(std::to_string(tape_.at(pointer_)));
    if (op_code.code == 99) return true;
    OP_MAP.at(op_code.code)(pointer_, op_code.mode, tape_, pointer_, io_);
    if (op_code.code == 4) {
      return false;
    }
  }
  return false;
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day7/input.json");
  std::vector<int> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  IO io = {5, 6, 7, 8, 9};

  int max = 0;

  do {
    IO nio = io;
    nio.push_back(0);

    for (auto const& i : nio) std::cout << i << ",";
    std::cout << std::endl;

    std::vector<Amp> amps = {
        {input, nio}, {input, nio}, {input, nio}, {input, nio}, {input, nio}};

    bool ended = false;

    while (!ended) {
      for (auto& amp : amps) {
        ended = amp.run();
      }
    }

    max = std::max(max, nio.back());
    std::cout << nio.back() << std::endl;
  } while (std::next_permutation(io.begin(), io.end()));

  std::cout << max << std::endl;
  return 0;
}
