#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;

int main(int argc, char* argv[]) {
  std::string str;
  std::map<char, int> char_cout_map;
  while (!getline(cin, str)) {
  }

  for (auto c : str) {
    if (c != ' ') {
      if (char_cout_map.end() == (std::map<char, int>::iterator it = char_cout_map.find(c))) {
        it->first = c;
        it->second = 1;
      } else {
        it->second += 1;
      }
    }
  }

  std::cout << std::endl;

  return 0;
}
