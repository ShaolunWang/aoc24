#include <string>
#include <vector>
class Day2 {
public:
  explicit Day2(std::string in_filename) : filename{std::move(in_filename)} {};
  void parse();
  int solve_pt1();
  int solve_pt2();

  /**
   * @brief custom comparison for is_sorted
   * @return true if sorted + safe
   */
  static bool safetyCompgt(const int &a, const int &b);
  static bool safetyComplt(const int &a, const int &b);
  std::vector<std::vector<int>> get_levels() const { return all_reports; }

private:
  std::string filename;
  std::vector<std::vector<int>> all_reports;
};
