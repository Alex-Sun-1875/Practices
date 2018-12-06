#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
  return a < b;
}

int main() {
  std::vector<int> myvec{3, 2, 5, 7, 3, 2};
  std::vector<int> lbvec(myvec);

  std::sort(myvec.begin(), myvec.end(), cmp);
  std::cout << "predicate function:" << std::endl;
  for (auto i : myvec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });
  std::cout << "lambda expression:" << std::endl;
  for (auto i : lbvec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
