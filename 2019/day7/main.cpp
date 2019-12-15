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

class Amp {
 public:
  Amp(Memory program, Stack init_input_stack);
  void connect_output_to(Amp& other);

  bool run(int64_t return_at_op_code = -1);

  int64_t amp_out() { return amp_out_; }

 private:
  IntCodeComputer ic_;
  int64_t amp_out_;
};

Amp::Amp(Memory program, Stack init_input_stack)
    : ic_(program.size(), output_to(&amp_out_), default_input()), amp_out_(0) {
  ic_.install_program(program);
  for (auto const& i : init_input_stack) ic_.push_input_stack(i);
}

bool Amp::run(int64_t return_at_op_code) { return ic_.run(return_at_op_code); }

void Amp::connect_output_to(Amp& other) {
  other.ic_.input(input_from(&amp_out_));
}

int64_t part_one(Memory input, std::vector<int64_t> input_vals) {
  int64_t max = 0;

  do {
    std::vector<Amp*> amps = {
        new Amp(input, {input_vals[0], 0}), new Amp(input, {input_vals[1]}),
        new Amp(input, {input_vals[2]}), new Amp(input, {input_vals[3]}),
        new Amp(input, {input_vals[4]})};

    amps[0]->connect_output_to(*amps[1]);
    amps[1]->connect_output_to(*amps[2]);
    amps[2]->connect_output_to(*amps[3]);
    amps[3]->connect_output_to(*amps[4]);

    bool stop = false;

    for (auto& amp : amps) {
      amp->run();
    }

    max = std::max(max, amps[4]->amp_out());
  } while (std::next_permutation(input_vals.begin(), input_vals.end()));

  return max;
}

int64_t part_two(Memory input, std::vector<int64_t> input_vals) {
  int64_t max = 0;

  do {
    std::vector<Amp*> amps = {
        new Amp(input, {input_vals[0], 0}), new Amp(input, {input_vals[1]}),
        new Amp(input, {input_vals[2]}), new Amp(input, {input_vals[3]}),
        new Amp(input, {input_vals[4]})};

    amps[0]->connect_output_to(*amps[1]);
    amps[1]->connect_output_to(*amps[2]);
    amps[2]->connect_output_to(*amps[3]);
    amps[3]->connect_output_to(*amps[4]);
    amps[4]->connect_output_to(*amps[0]);

    bool stop = false;
    while (!stop)
      for (auto& amp : amps) {
        stop = amp->run(4);
      }

    max = std::max(max, amps[4]->amp_out());
  } while (std::next_permutation(input_vals.begin(), input_vals.end()));

  return max;
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/christian/git/aoc/2019/day7/input.json");
  std::vector<int64_t> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  std::cout << "part one: " << part_one(input, {0, 1, 2, 3, 4}) << std::endl;
  std::cout << "part two: " << part_two(input, {5, 6, 7, 8, 9}) << std::endl;

  return 0;
}
