#include <string>
#include <utility>
#include <vector>

class Day1 {
public:
  explicit Day1(std::string in_filename) : filename{std::move(in_filename)} {};
  void parse();
  int solve_pt1();
  int solve_pt2();

private:
  std::vector<int> left, right;
  std::string filename;
};
