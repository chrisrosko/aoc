#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <intcode_computer.h>

int run_computer(int a, int b, Memory program) {
  IntCodeComputer ic(program.size());

  program.at(1) = a;
  program.at(2) = b;

  ic.install_program(program);

  ic.run();

  return ic.mem()[0];
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day2/input.json");
  std::vector<int64_t> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  // part one
  int p1 = run_computer(12, 2, input);

  int p2a = 0;
  int p2b = 0;
  // part two
  for (size_t outer = 0; outer < 100; outer++) {
    for (size_t inner = 0; inner < 100; inner++) {
      if (run_computer(outer, inner, input) == 19690720) {
        p2a = outer;
        p2b = inner;
      }
    }
  }

  std::cout << "part one: " << p1 << std::endl;

  std::cout << "part two: " << p2a << p2b << std::endl;

  return 0;
}
