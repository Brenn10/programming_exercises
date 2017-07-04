#include "BinaryTree.h"
#include "Node.h"

using namespace std;

void BinaryTree::add(int data)
{
  if(head==NULL)
  {
    Node *tmp;
    (*tmp).parent=NULL;
    (*tmp).leftChild=NULL;
    (*tmp).rightChild=NULL;
    head=tmp;
  }
  else
  {
    add(data,head);
  }
}

void BinaryTree::add(int data,int *node)
{
  if(data>(*node).data)
  {
    if((*node).rightChild==NULL)
    {
      Node *tmp;
      (*tmp).parent=&node;
      (*tmp).leftChild=NULL;
      (*tmp).rightChild=NULL;
      (*node).rightChild=tmp;
    }
    else
    {
      add(data,(*node).rightChild);
    }
  }
  else
  {
    if((*node).leftChild==NULL)
    {
      Node *tmp;
      (*tmp).parent=&node;
      (*tmp).leftChild=NULL;
      (*tmp).rightChild=NULL;
      (*node).leftChild=tmp;
    }
    else
    {
      add(data,(*node).leftChild);
    }
}
