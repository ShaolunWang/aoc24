#include "day1.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <numeric>
#include <print>
#include <sstream>
#include <string>

void Day1::parse() {

  // parsing
  std::ifstream rfile(filename);

  if (rfile.is_open()) {
    std::string line;
    while (std::getline(rfile, line)) {
      std::istringstream stream(line);
      int a, b;
      stream >> a >> b;
      left.push_back(a);
      right.push_back(b);
    }

    rfile.close();
  }

  std::ranges::sort(left);
  std::ranges::sort(right);
  // NOTE: size must equal
  assert(left.size() == right.size());
}

int Day1::solve_pt1() {

  std::vector<int> res_pt1;
  // zip them together &  diff lambda function
  std::ranges::transform(
      left, right, std::back_inserter(res_pt1),
      [](const auto &aa, const auto &bb) { return std::abs(aa - bb); });

  int pt1 = std::accumulate(res_pt1.begin(), res_pt1.end(), 0);
  return pt1;
}
int Day1::solve_pt2() {
  int res = 0;
  for (int x : left) {
    auto count = std::count(right.cbegin(), right.cend(), x);
    res += x * static_cast<int>(count);
  }
  return res;
}
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
TEST_CASE("Testing the solutions") { // NOLINT
  Day1 d1("test/day1_test.txt");
  d1.parse();
  CHECK(d1.solve_pt1() == 11);
  CHECK(d1.solve_pt2() == 31);
}

int main(int argc, char *argv[]) {
  Day1 d1("input/day1.txt");
  d1.parse();
  doctest::Context(argc, argv).run();
  std::println("==============================================================="
               "================");
  std::println("[Answers]");
  std::println("{}", std::to_string(d1.solve_pt1()));
  std::println("{}", std::to_string(d1.solve_pt2()));
  return 0;
}
