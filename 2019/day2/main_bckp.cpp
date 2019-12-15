#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>

void multiply(int in_a, int in_b, int out, std::vector<int>& tape) {
  tape.at(out) = tape.at(in_a) * tape.at(in_b);
}

void add(int in_a, int in_b, int out, std::vector<int>& tape) {
  tape.at(out) = tape.at(in_a) + tape.at(in_b);
}

std::map<int, std::function<void(int in_a, int in_b, int out,
                                 std::vector<int>& tape)>>
    OP_CODE_MAP = {{1, add}, {2, multiply}};

int process_tape(int in_a, int in_b, std::vector<int> tape) {
  tape.at(1) = in_a;
  tape.at(2) = in_b;
  for (size_t index = 0; index < tape.size(); index += 4) {
    int opcode = tape.at(index);
    if (opcode == 99)
      break;
    else
      OP_CODE_MAP.at(opcode)(tape.at(index + 1), tape.at(index + 2),
                             tape.at(index + 3), tape);
  }
  return tape.at(0);
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day2/input.json");
  std::vector<int> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  // part one
  std::cout << process_tape(12, 2, input) << std::endl;

  // part two
  for (size_t outer = 0; outer < 100; outer++) {
    for (size_t inner = 0; inner < 100; inner++) {
      if (process_tape(outer, inner, input) == 19690720)
        std::cout << outer << " : " << inner << std::endl;
    }
  }
  return 0;
}
