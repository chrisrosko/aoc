#include <fstream>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <map>
#include <boost/algorithm/string.hpp>

class Node;
using NodeMap = std::map<std::string, std::shared_ptr<Node>>;

class Node {
 public:
  Node(std::string const& id);

  Node* find(std::function<bool(Node*)> find_func);
  Node* find(std::function<bool(Node*)> find_func, int& depth);
  Node& add_child(Node* child);

  Node* parent() { return parent_; }
  std::string id() { return id_; }

 private:
  Node* parent_;
  std::vector<Node*> children_;
  std::string id_;
};

Node::Node(std::string const& id) : id_(id), parent_(nullptr) {}

Node* Node::find(std::function<bool(Node*)> find_func) {
  if (find_func(this))
    return this;
  else {
    for (auto const c : children_) {
      auto find = c->find(find_func);
      if (find) return find;
    }
  }
  return nullptr;
}

Node* Node::find(std::function<bool(Node*)> find_func, int& depth) {
  if (find_func(this))
    return this;
  else {
    ++depth;
    for (auto const c : children_) {
      auto find = c->find(find_func, depth);
      if (find) return find;
    }
    --depth;
  }
  return nullptr;
}

Node& Node::add_child(Node* child) {
  child->parent_ = this;
  children_.push_back(child);
  return *this;
}

int part_one(NodeMap const& node_map) {
  int sum = 0;

  for (auto const& e : node_map) {
    auto parent = e.second->parent();
    int inner = 0;
    while (parent != nullptr) {
      parent = parent->parent();
      ++inner;
    }
    sum += inner;
  }
  return sum;
}

int part_two(NodeMap const& node_map) {
  int sum = 0;
  auto you = node_map.at("YOU");

  Node* find = nullptr;

  auto next_orbit = you->parent();
  while (!find) {
    next_orbit = next_orbit->parent();
    int depth = 0;
    find = next_orbit->find([](Node* n) { return n->id() == "SAN"; }, depth);
    if (find) {
      sum += depth;
      break;
    }
    ++sum;
  }
  return sum;
}

int main(int argc, char const* argv[]) {
  std::ifstream fs("/home/zr0395/workspace/git/aoc/2019/day6/input.json");
  std::vector<std::string> input;
  {
    cereal::JSONInputArchive ar(fs);
    ar(input);
  }

  NodeMap node_map;
  std::vector<std::pair<std::string, std::string>> adjacencies;
  for (auto const& str : input) {
    std::vector<std::string> ids;
    boost::split(ids, str, boost::is_any_of(")"));
    node_map.insert({ids[0], std::make_shared<Node>(ids[0])});
    node_map.insert({ids[1], std::make_shared<Node>(ids[1])});
    adjacencies.push_back(std::make_pair(ids[0], ids[1]));
  }

  for (auto const& p : adjacencies) {
    auto a = node_map.at(p.first);
    auto b = node_map.at(p.second);
    a->add_child(b.get());
  }

  std::cout << part_one(node_map) << std::endl;
  std::cout << part_two(node_map) << std::endl;

  return 0;
}
