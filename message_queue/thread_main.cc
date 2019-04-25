#include "thread_pool.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void func(int a) {
  std::cout << "a = " << a << std::endl;
}

int main(int argc, char* argv[]) {
  ThreadPool<int> thread_pool(20, func);

  return 0;
}
