#include <iostream>

void first(string& m, string& s) {
  m = s;
  s = s + s;
}

void second(string& m, string& s) {
  s = s + m;
}

int main(int argc, char* argv) {
  int i;
  std::cout << "请输入字符串长度:";
  std::cin >> i;
  std::cout << std::endl;
}
