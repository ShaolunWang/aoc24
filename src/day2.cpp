#include "day2.h"
#include <algorithm>
#include <fstream>
#include <print>
#include <sstream>
#include <vector>

bool Day2::safetyCompgt(const int &a, const int &b) {
  bool check = (b - a >= 1) && (b - a <= 3);
  return check;
}
bool Day2::safetyComplt(const int &a, const int &b) {
  bool check = (a - b >= 1) && (a - b <= 3);
  return check;
}

void Day2::parse() {
  std::ifstream rfile(filename);
  if (rfile.is_open()) {
    std::string line;
    // for each line
    while (std::getline(rfile, line)) {
      std::vector<int> levels;
      std::istringstream stream(line);
      std::string token;
      // for each int - split by delim ' '
      while (std::getline(stream, token, ' ')) {
        if (!token.empty()) {
          levels.push_back(std::stoi(token));
        }
      }
      all_reports.push_back(levels);
    }
  }
}

int Day2::solve_pt1() {
  int count = 0;
  for (std::vector<int> report : all_reports) {
    bool is_safe = true;
    bool is_monotone_inc{false};
    if (report.size() == 2 && (safetyComplt(report[0], report[1]) ||
                               (safetyCompgt(report[0], report[1])))) {
      count++;
      continue;
    } else if (report.size() > 2) {
      if (report[0] > report[1]) {
        is_monotone_inc = true;
      }
    }
    // here is where we actually iterate through the mat
    for (size_t i = 1; i < report.size(); i++) {
      if (is_monotone_inc) {
        is_safe = is_safe && safetyCompgt(report[i], report[i - 1]);
      } else {
        is_safe = is_safe && safetyComplt(report[i], report[i - 1]);
      }
      if (!is_safe) {
        break;
      }
    }
    if (is_safe) {

      count++;
    }
  }
  return count;
}
int Day2::solve_pt2() {

  int count = 0;
  for (std::vector<int> report : all_reports) {
    int bad_level_counter{0};
    bool is_safe = true;
    bool is_monotone_inc{false};
    if (report.size() == 2 && (safetyComplt(report[0], report[1]) ||
                               (safetyCompgt(report[0], report[1])))) {
      count++;
      continue;
    } else if (report.size() > 2) {
      if (report[0] > report[1]) {
        is_monotone_inc = true;
      }
    }
    // iterate through the  level
    for (size_t i = 1; i < report.size(); i++) {
      if (is_monotone_inc) {
        is_safe = is_safe && safetyCompgt(report[i], report[i - 1]);
      } else {
        is_safe = is_safe && safetyComplt(report[i], report[i - 1]);
      }
      if (!is_safe) {
        if (bad_level_counter == 1) {
          break;
        }
        // left end:
        if (i < report.size() - 2) {
          // try removing i - 1
          if (is_monotone_inc) {
            is_safe = safetyComplt(report[i + 1], report[i - 1]);
          } else {
            is_safe = safetyCompgt(report[i + 1], report[i - 1]);
          }
        } else {
          is_safe = true;
        }

        if (is_safe) {
          bad_level_counter++;
          i = i + 2;
        } else {
          break;
        }
      }
    }

    // is the level safe?
    if (is_safe) {
      std::print("{}, {}\n", report[0], report[1]);
      count++;
    }
  }
  return count;
}
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
TEST_CASE("Testing the solutions") { // NOLINT
  Day2 d2("test/day2_test.txt");
  d2.parse();
  std::vector<std::vector<int>> in = {
      {7, 6, 4, 2, 1}, {1, 2, 7, 8, 9}, {9, 7, 6, 2, 1},
      {1, 3, 2, 4, 5}, {8, 6, 4, 4, 1}, {1, 3, 6, 7, 9},
  };
  CHECK(d2.get_levels() == in);
  CHECK(d2.solve_pt1() == 2);
  CHECK(d2.solve_pt2() == 4);
}

int main() {
  doctest::Context().run();
  Day2 d2("input/day2.txt");
  d2.parse();

  std::println("==============================================================="
               "================");
  std::println("[Answers]");
  std::print("{}\n", d2.solve_pt1());
//  std::print("{}\n", d2.solve_pt2());
};
