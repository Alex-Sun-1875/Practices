// 创建二叉树以及中序遍历
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct node {
  int element;
  struct node* left;
  struct node* right;
} Node, *pNode;

void InsertNode(pNode* head, int data) {
  // std::cout << "func: " << __FUNCTION__ << ", 1111" << std::endl;
  if (NULL == *head) {
    // std::cout << "func: " << __FUNCTION__ << ", 2222" << std::endl;
    *head = new Node;
    (*head)->element = data;
    (*head)->left = NULL;
    (*head)->right = NULL;
  } else {
    // std::cout << "func: " << __FUNCTION__ << ", 3333" << std::endl;
    if (data <= (*head)->element) {
      // std::cout << "func: " << __FUNCTION__ << ", 4444" << std::endl;
      InsertNode(&((*head)->left), data);
    } else {
      // std::cout << "func: " << __FUNCTION__ << ", 5555" << std::endl;
      InsertNode(&((*head)->right), data);
    }
  }
}

pNode CreateTree() {
  pNode head = NULL;
  int data;
  scanf("%d", &data);
  while (0 != data) {
    InsertNode(&head, data);
    scanf("%d", &data);
  }

  return head;
}

// 中序遍历二叉树
void PrintTree(pNode head) {
  // std::cout << "func: " << __FUNCTION__ << ", 1111" << std::endl;
  if (NULL != head) {
    PrintTree(head->left);
    printf("%d ", head->element);
    PrintTree(head->right);
  }
}

int main(int argc, char* argv[]) {
  pNode head;
  printf("请输入一串整数，空格隔开，0表示输入结束\n");
  head = CreateTree();
  printf("中序遍历二叉树\n");
  PrintTree(head);
  printf("\n");

  return 0;
}


// poker 排序，次数大的放前面，次数一样按从大到小排序
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;

typedef std::pair<char, int> Pair;

bool compare_for_cout(const Pair& lhs, const Pair& rhs) {
  return lhs.second > rhs.second;
}

bool compare_for_val(const Pair& lhs, const Pair& rhs) {
  if (lhs.second == rhs.second)
    return lhs.first > rhs.first;
  else
    return lhs.second > rhs.second;
}

bool compare(const Pair& lhs, const Pair& rhs) {
  if (lhs.second == rhs.second) {
    return lhs.first > rhs.second;
  } else {
    return lhs.second > rhs.second;
  }
}

int main(int argc, char* argv[]) {
  std::string str;
  std::vector<Pair> pair_vec;
  while (!getline(cin, str)) {
  }

  for (auto c : str) {
    if (c != ' ') {
      auto it = std::find_if(pair_vec.begin(), pair_vec.end(), [&](const Pair& item) -> bool { return item.first == c; });
      if (it != pair_vec.end()) {
        (*it).second += 1;
      } else {
        pair_vec.push_back(Pair(c, 1));
      }
    }
  }

  for (auto it : pair_vec) {
    std::cout << it.first << ", " << it.second << std::endl;
  }


  std::sort(pair_vec.begin(),pair_vec.end(), compare_for_val);
  std::sort(pair_vec.begin(),pair_vec.end(), compare_for_cout);
  // std::sort(pair_vec.begin(), pair_vec.end(), compare);

  for (auto it : pair_vec) {
    for (int i = 0; i < it.second; ++i) {
      std::cout << it.first << " ";
    }
  }

  std::cout << std::endl;

  return 0;
}

// 不用第三方变量交换两个数字
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

// 计算从1-2+3-4+5...n
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
