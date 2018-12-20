#include <iostream>

void bubble_sort(int* arr, int count) {
  int i, j;
  for (i = 0; i < count; ++i) {
    for (j = count - 1; j > i; --j) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  int arr[] = {5, 7, 1, 3, 4, 6, 2, 9, 8, 0};
  bubble_sort(arr, 10);
  for (auto i : arr) {
    std::cout << i << std::endl;
  }
  return 0;
}
