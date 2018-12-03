#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[]) {
  int a = 10;
  int b = 20;

  a = a + b;
  b = a - b;
  a = a - b;

  std::cout << "a = " << a << ", b = " << b << std::endl;

  return 0;
}
