#include "Node.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
  public:
    void add(int element);
    int remove();
  private:
    void add(int data, int *node);
    struct Node* head;
};

#endif
