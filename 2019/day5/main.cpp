#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <intcode_computer.h>

int64_t part_one(std::vector<int64_t> input) {
  IntCodeComputer ic(input.size(), default_output(), const_input(1));

  ic.install_program(input);

  ic.run();

  return ic.output_stack_back();
}

int64_t part_two(std::vector<int64_t> input) {
  IntCodeComputer ic(input.size(), default_output(), const_input(5));

  ic.install_program(input);

  ic.run();

  return ic.output_stack_back();
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day5/input.json");
  std::vector<int64_t> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  int64_t p1 = part_one(input);
  int64_t p2 = part_two(input);

  std::cout << "----------------------------" << std::endl;

  std::cout << "part one: " << p1 << std::endl;
  std::cout << "part two: " << p2 << std::endl;

  return 0;
}
