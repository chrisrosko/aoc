#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <intcode_computer.h>

int main(int argc, char const *argv[]) {
  std::ifstream fs("/home/zr0395/workspace/git/aoc/2019/day9/input.json");
  std::vector<int64_t> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  IntCodeComputer ic(input.size() * 10);

  ic.install_program(input);

  ic.run();

  return 0;
}
