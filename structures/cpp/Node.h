#ifndef DS_NODE_H
#define DS_NODE_H

struct Node
{
  struct Node* parent;
  struct Node* leftChild;
  struct Node* rightChild;
  int data;
};

#endif
