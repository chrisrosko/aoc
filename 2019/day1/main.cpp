#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>

int part_one(std::vector<int> const & input) {
  int result = 0;
  for(auto const& e: input) 
    result += (e / 3) - 2;
  
  return result;
}

int part_two(std::vector<int> const & input) {
  int result = 0;
  for (auto const& e : input) {
    int curr_val = e;
    while (true) {
      int fuel_mass = (curr_val / 3) - 2;
      if ( fuel_mass > 0) {
        result += fuel_mass;
        curr_val = fuel_mass;
      }
      else break;
    }
  }
  return result;
}

int main(int argc, char const *argv[])
{
  std::ifstream fs("/home/christian/git/aoc/2019/day1/input.json");
  std::vector<int> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  std::cout << part_two(input) << std::endl;
  return 0;
}
