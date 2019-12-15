#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>

namespace utils {
bool is_file(std::string const& path) {
  std::ifstream f(path);
  return f.good();
}

std::string pathname(std::string const& pathname) {
  std::string path_str = std::getenv("UTIL_PATH");
  // std::vector<std::string> paths;
  // boost::split(paths, path_str,boost::is_any_of(":"));
  // for(auto const& path : paths) {
  //   if (is_file(path))
  //     return path;
  // }
  // throw std::runtime_error("path not found in env: " + pathname);
}
int main(int argc, char const* argv[]) {
  std::cout << "halllllllllllllooooo" << std::endl;
  return 0;
}

}  // namespace utils