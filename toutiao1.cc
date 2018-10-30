#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
  int n, k;
  std::cout << "请输入字符个数和差值: " << std::endl;
  std::cin >> n >> k;

  std::cout << "请输入 " << n << " 个数字" << std::endl;
  std::vector<int> vec;
  for (int i = 0; i < n; ++i) {
    int j;
    std::cin >> j;
    vec.push_back(j);
  }

  std::sort(vec.begin(), vec.end());

  std::vector<int>::iterator it = std::unique(vec.begin(), vec.end());
  std::vector<int> no_dup_vec(vec.begin(), it);

  it = no_dup_vec.begin();
  int count = 0;
  for (; it != no_dup_vec.end(); ++it) {
    if (no_dup_vec.end() != find(it, no_dup_vec.end(), *it + k))
      count++;
  }

  std::cout << "count = " << count << std::endl;

  return 0;
}
