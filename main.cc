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
