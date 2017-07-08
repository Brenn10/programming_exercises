#include "Node.h"
#include <string>
#include <sstream>

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
  public:
    BinaryTree();
    void add(int element);
    bool find(int element);
    bool remove(int element);
    std::string toString();
  private:
    std::string toString(Node* node);
    void add(int data, Node* node);
    bool find(int element, Node *node);
    bool remove(int element, Node* parent,Node* current);
    struct Node* head;
};

#endif
