#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

struct Point {
  int x;
  int y;
};

void line(int x0, int y0, int x1, int y1,
          std::function<bool(int, int)> set_px) {
  bool steep = false;
  if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
    std::swap(x0, y0);
    std::swap(x1, y1);
    steep = true;
  }
  if (x0 > x1) {
    std::swap(x0, x1);
    std::swap(y0, y1);
  }
  int dx = x1 - x0;
  int dy = y1 - y0;
  int derror = std::abs(dy) * 2;
  int error = 0;
  int y = y0;
  for (int x = x0; x <= x1; x++) {
    if (steep) {
      if (set_px(y, x)) return;
    } else {
      if (set_px(x, y)) return;
    }
    error += derror;
    if (error > dx) {
      y += (y1 > y0 ? 1 : -1);
      error -= dx * 2;
    }
  }
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day10/input.json");
  std::vector<std::string> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  std::vector<Point> points;

  for (int o_index = 0; o_index < input.size(); o_index++) {
    auto& l = input.at(o_index);
    for (int i_index = 0; i_index < l.size(); i_index++) {
      if (l.at(i_index) == '#') points.push_back({i_index, o_index});
    }
  }

  auto p0 = points[0];
  int count = 0;

  auto set_px = [&](int x, int y) -> bool {
    std::cout << "x: " << x << "y: " << y << std::endl;
    if (input.at(y).at(x) != '.') {
      ++count;
      input.at(y).at(x) = 'x';
      return true;
    }
    return false;
  };
  for (int index = 1; index < points.size(); index++) {
    line(p0.x, p0.y, points[index].x, points[index].y, set_px);
    // std::cout << count << std::endl;
    for (auto const& l : input) std::cout << l << std::endl;
    std::cout << std::endl << std::endl;
  }

  return 0;
}
