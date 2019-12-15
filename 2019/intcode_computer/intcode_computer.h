#ifndef INTCODE_COMPUTER_INTCODE_COMPUTER
#define INTCODE_COMPUTER_INTCODE_COMPUTER

#include <vector>
#include <list>
#include <string>
#include <functional>

using Memory = std::vector<int64_t>;
using Stack = std::list<int64_t>;
using Pointer = int64_t;
using Modes = std::string;
using Output = std::function<void(int64_t)>;
using Input = std::function<int64_t()>;

Output default_output();
Input default_input();
Input const_input(int64_t in);
Output output_to(int64_t* out);
Input input_from(int64_t* in);

enum MODE { MODE_POSITIONAL = 0, MODE_IMMEDIATE = 1, MODE_RELATIVE = 2 };

class IntCodeComputer {
 public:
  IntCodeComputer(size_t init_mem_size);

  IntCodeComputer(size_t init_mem_size, Output out, Input in);

  bool run(int64_t op_to_pause_at = -1);

  void install_program(Memory const& mem);

  void push_input_stack(int64_t input);

  int64_t output_stack_back();

  Output& output() { return output_; }
  void input(Input const& in) { input_ = in; }

  Memory const& mem() const { return mem_; }

 private:
  int64_t get_value(MODE mode, Pointer pointer);
  void set_value(int64_t val, MODE mode, Pointer pointer);

  void multiply(Modes const&);
  void add(Modes const&);

  void jump_if_true(Modes const&);
  void jump_if_false(Modes const&);

  void less_than(Modes const&);
  void equal(Modes const&);

  void set_relative_base(Modes const&);

  void in(Modes const&);
  void out(Modes const&);

  Output output_;
  Input input_;

  Memory mem_;
  Pointer pointer_;
  Stack istack_;
  Stack ostack_;
  int64_t rel_base_;
};

#endif /* INTCODE_COMPUTER_INTCODE_COMPUTER */
