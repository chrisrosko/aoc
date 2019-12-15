#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <algorithm>

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day8/input.json");
  std::string input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  std::vector<std::vector<std::string>> layers;

  for (auto iter = input.begin(); iter != input.end();) {
    std::vector<std::string> layer;
    for (size_t index = 0; index < 6; ++index) {
      std::string str(iter, iter + 25);
      layer.push_back(str);
      iter += 25;
    }
    layers.push_back(layer);
  }

  int tmp_min = 9999999;
  int tmp_index = 0;
  int index = 0;
  for (auto const& layer : layers) {
    int sum = 0;
    for (auto const& str : layer) {
      int n = std::count(str.begin(), str.end(), '0');
      sum += n;
    }
    if (sum < tmp_min) {
      tmp_min = sum;
      tmp_index = index;
    }
    ++index;
  }

  std::cout << "min: " << tmp_min << " found at: " << tmp_index << std::endl;

  std::vector<std::string> layer = layers.at(15);

  int ones = 0;
  int twos = 0;
  for (auto const& str : layer) {
    ones += std::count(str.begin(), str.end(), '1');
    twos += std::count(str.begin(), str.end(), '2');
  }

  std::cout << ones * twos << std::endl;

  std::vector<std::string> result = layers.at(0);

  int count = 0;
  for (size_t index = 0; index < 25; index++) {
    for (auto& layer : layers) {
      for (size_t inner = 0; inner < 6; inner++) {
        if (result.at(inner).at(index) == '2')
          result.at(inner).at(index) = layer.at(inner).at(index);
      }
    }
  }

  std::ofstream ofs("day8/result.ppm",
                    std::fstream::out | std::fstream::binary);
  ofs << "P4\n" << 25 << " " << 6 << std::endl;
  for (auto const& r : result) {
    for (auto const& c : r) {
      ofs << c - '0';
    }
    ofs << std::endl;
  }
}