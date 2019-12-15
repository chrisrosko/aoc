#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>


constexpr float PI = 3.14159265359;

bool cmpf(float a, float b, float epsilon = 0.005f)
{
    return (fabs(a - b) < epsilon);
}

struct Point {
  int x;
  int y;
  bool operator= (Point const& other) const {
    return x == other.x and y == other.y;
  };
};

float angle(Point const& source, Point const& target) {
  float angle = std::atan2(target.y - source.y, target.x - source.x) * 180 / PI;
  if (angle < 0)
    return 360 + angle;
  return angle;
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/zr0395/workspace/git/aoc/2019/day10/input.json");
  std::vector<std::string> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  std::vector<Point> asteroids;

  for (int y = 0; y < input.size(); ++y) {
    auto line = input.at(y);
    for (int x = 0; x < line.size(); ++x)
      if (line.at(x) == '#')
        asteroids.push_back({x,y});
  }

  int count = 0;
  for(auto const& source : asteroids)
    std::vector<float> visible;
    for(auto const& target : asteroids)
      if(source != target){
        float angle = angle(source, target);
      }

  return 0;
}
