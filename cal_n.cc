#include <iostream>

int add(int n) {
  if (0 == n%2) {
    return (n/2)*(-1);
  } else {
    return (n/2)*(-1) + n;
  }
}

int main(int argc, char* argv[]) {
  std::cout << "add(5) = " << add(5) << ", add(3) = " << add(3) << std::endl;

  return 0;
}
