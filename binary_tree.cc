#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct node {
  int data;
  node* left;
  node* right;
} Node, *pNode;

void InsertNode(pNode* head, int data) {
  if (NULL == *head) {
    *head = new Node;
    (*head)->data = data;
    (*head)->left = NULL;
    (*head)->right = NULL;
  } else {
    if (data <= (*head)->data) {
      InsertNode(&(*head)->left, data);
    } else {
      InsertNode(&(*head)->right, data);
    }
  }
}

void PrintNode(pNode node) {
  if (nullptr != node) {
    std::cout << node->data << " ";
  }
}

// 前序递归遍历
void PreOrder(pNode root) {
  if (nullptr != root) {
    PrintNode(root);
    PreOrder(root->left);
    PreOrder(root->right);
  }
}

void MiddleOrder(pNode root) {
  if (nullptr != root) {
    MiddleOrder(root->left);
    PrintNode(root);
    MiddleOrder(root->right);
  }
}

void PostOrder(pNode root) {
  if (nullptr != root) {
    PostOrder(root->left);
    PostOrder(root->right);
    PrintNode(root);
  }
}

pNode BuildTree() {
  int data;
  pNode head = NULL;
  scanf("%d", &data);
  while (0 != data) {
    InsertNode(&head, data);
    scanf("%d", &data);
  }

  return head;
}

int main(int argc, char* argv[]) {
  pNode head;
  std::cout << "请输入一串整数，以空格分开，0 表示输入结束:" << std::endl;
  head = BuildTree();
  std::cout << "前序遍历二叉树:" << std::endl;
  PreOrder(head);
  std::cout << std::endl;
  std::cout << "中序遍历二叉树:" << std::endl;
  MiddleOrder(head);
  std::cout << std::endl;
  std::cout << "后续遍历二叉树:" << std::endl;
  PostOrder(head);
  std::cout << std::endl;

  return 0;
}

