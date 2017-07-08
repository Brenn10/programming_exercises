#include "BinaryTree.h"
#include "Node.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
BinaryTree::BinaryTree()
{
  head=NULL;
}

void BinaryTree::add(int data)
{
  if(!head)
  {
    Node *tmp = new Node();
    tmp->leftChild=NULL;
    tmp->rightChild=NULL;
    tmp->data=data;
    head=tmp;
  }
  else
  {
    add(data,head);
  }
}

void BinaryTree::add(int data,Node *node)
{
  if(data>node->data)
  {
    if(!node->rightChild)
    {
      struct Node *tmp = new Node();
      tmp->data=data;
      tmp->leftChild=NULL;
      tmp->rightChild=NULL;
      node->rightChild=tmp;
    }
    else
    {
      add(data,node->rightChild);
    }
  }
  else
  {
    if(!node->leftChild)
    {
      struct Node *tmp = new Node();
      tmp->data=data;
      tmp->leftChild=NULL;
      tmp->rightChild=NULL;
      node->leftChild=tmp;
    }
    else
    {
      add(data,node->leftChild);
    }
  }
}

bool BinaryTree::find(int element)
{
  if(!head)
  {
    return false;
  }
  else
  {
    find(element,head);
  }
}

bool BinaryTree::find(int element,Node *node)
{
  if(element<node->data)
  {
    if(node->leftChild)
      return find(element,node->leftChild);
    else
      return false;
  }
  else if (element > node->data)
  {
    if(node->rightChild)
      return find(element,node->rightChild);
    else
      return false;
  }
  else
  {
    return true;
  }
}

bool BinaryTree::remove(int element)
{
  if(!head)
  {
    return false;
  }
  else
  {
    remove(element,head)
  }
}
bool BinaryTree::remove(int element,Node* parent,Node* current)
{
  //if node is null, failure
  if(!current)
  {
    return false;
  }
  else if(element==current->data)
  {
    //no children
    if(!current->rightChild and !current->leftChild)
    {
      if(parent)
      {
        if(current->data>parent->data)
          parent->leftChild=NULL;
        if(current->data<parent->data)
          parent->rightChild=NULL;)
        delete current;
      }
      else
      {
        head=NULL;
      }
      //sets to null s parent no longer has a child
      delete current;
    }
    //2 children
    else if(current->rightChild and current->leftChild)
    {
      Node* parent = current
      Node* tmp = current->rightChild;

      while(tmp->leftChild)
      {
        parent = tmp;
        tmp = tmp->leftChild;
      }

      int val = tmp->data;
      remove(val , parent)

      current->data=val;
    }
    //1 child
    else if(current->rightChild)
    {
      if(parent)
      {
        if(current==parent->leftChild)
          parent->leftChild=current->rightChild;
        if(current==parent->rightChild)
          parent->rightChild=current->rightChild;)
        delete current;
      }
      else
      {
        head=NULL;
      }
    }
    else if(current->leftChild)
    {
      if(parent)
      {
        if(current==parent->leftChild)
          parent->leftChild=current->rightChild;
        if(current==parent->rightChild)
          parent->rightChild=current->rightChild;)
        delete current;
      }
      else
      {
        head=NULL;
      }
    }
  }
}


string BinaryTree::toString()
{
  if(head==NULL)
  {
    return "{}";
  }
  else
  {
    stringstream ss;
    ss <<"{"<< toString(head) <<"}";
    return ss.str();
  }
}

string BinaryTree::toString(Node* node)
{
  stringstream ss;
  if(node->leftChild!=NULL)
    ss << toString(node->leftChild) << ",";
  ss << node->data;
  if(node->rightChild!=NULL)
    ss <<","<< toString(node->rightChild);
  return ss.str();
}
