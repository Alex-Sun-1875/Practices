#include "smart_ptr2.h"

void func(SmartPtr<std::string> str) {
  SmartPtr<std::string> s = str;
  std::cout << "str = " << *s << std::endl;
}

int main(int argc, char* argv[]) {
  std::string* str = new std::string("hello world!!!");
  SmartPtr<std::string> ref_str(str);
  func(ref_str);

  return 0;
}
