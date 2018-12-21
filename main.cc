#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;

typedef std::pair<char, int> Pair;

bool compare_for_cout(const Pair& lhs, const Pair& rhs) {
  if (lhs.second > rhs.second)
    return lhs.second > rhs.second;

}

bool compare_for_val(const Pair& lhs, const Pair& rhs) {
  if ((lhs.second == rhs.second) && (lhs.first > rhs.first))
    return lhs.first > rhs.first;
}

int main(int argc, char* argv[]) {
  std::string str;
  std::vector<Pair> pair_vec;
  while (!getline(cin, str)) {
  }

  for (auto c : str) {
    if (c != ' ') {
      auto it = std::find_if(pair_vec.begin(), pair_vec.end(), [&](const Pair& item) -> bool { return item.first == c; });
      if (it != pair_vec.end()) {
        (*it).second += 1;
      } else {
        pair_vec.push_back(Pair(c, 1));
      }
    }
  }

  for (auto it : pair_vec) {
    std::cout << it.first << ", " << it.second << std::endl;
  }


  // std::sort(pair_vec.begin(),pair_vec.end(), compare_for_val);
  std::sort(pair_vec.begin(),pair_vec.end(), compare_for_cout);

  std::cout << std::endl;
  for (auto it : pair_vec) {
    std::cout << it.first << ", " << it.second << std::endl;
  }

  std::cout << std::endl;

  return 0;
}
