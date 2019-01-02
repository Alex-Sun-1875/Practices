#include <iostream>
#include <vector>

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (nullptr == str || rows <= 0 || cols <= 0)
            return false;
        bool* flag = new bool[rows*cols]();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                if (isHasPath(matrix, rows, cols, str, flag, i, j))
                    return true;
        }
        return false;
    }

    bool isHasPath(char* matrix, int rows, int cols, char* str,
                   bool* flag, int curx, int cury) {
        if ('\0' == *str)
            return true;
        if (cury = cols) {
            curx++;
            cury = 0;
        }
        if (-1 == cury) {
            curx--;
            cury = cols - 1;
        }
        if (curx < 0 || curx >= rows)
            return false;
        if (flag[curx*cols+cury] || *str != matrix[curx*cols+cury])
            return false;
        flag[curx*cols+cury] = true;
        bool sign = isHasPath(matrix, rows, cols, str+1, flag, curx-1, cury) ||
                    isHasPath(matrix, rows, cols, str+1, flag, curx+1, cury) ||
                    isHasPath(matrix, rows, cols, str+1, flag, curx, cury-1) ||
                    isHasPath(matrix, rows, cols, str+1, flag, curx, cury+1);
        flag[curx*cols+cury] = false;
        return sign;
    }
};


int main(int argc, char* argv[]) {
  bool* flag = new bool[7];
  for (int i = 0; i < 7; ++i) {
    std::cout << flag[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
