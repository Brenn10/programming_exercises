#include <LinkedList.h>
#include <string>
#include <sstream>
#include <cassert>
#include <iostream>
template<class T>
void LinkedList<T>::addFront(T data)
{
  if(head)
  {
    Node<T> *tmp= new Node<T>();

    tmp->parent=NULL;
    tmp->child=head;
    tmp->data=data;

    head->parent=tmp;
    head=tmp;
  }
  else
  {
    Node<T> *tmp = new Node<T>();

    tmp->parent=NULL;
    tmp->child=NULL;
    tmp->data=data;

    head=tmp;
    tail=tmp;
  }
}

template<class T>
void LinkedList<T>::addBack(T data)
{
  if(tail)
  {
    Node<T> *tmp= new Node<T>();

    tmp->parent=tail;
    tmp->child=NULL;
    tmp->data=data;

    tail->child=tmp;
    tail=tmp;
  }
  else
  {
    Node<T> *tmp = new Node<T>();

    tmp->parent=NULL;
    tmp->child=NULL;
    tmp->data=data;

    head=tmp;
    tail=tmp;
  }
}

template<class T>
T LinkedList<T>::popFront()
{
  assert(head);
  T tmp=head->data;
  if(head->child)
  {
    head=head->child;
    head->parent=NULL;
  }
  else
  {
    head=NULL;
    tail=NULL;
  }
  return tmp;
}

template<class T>
T LinkedList<T>::popBack()
{
  assert(tail);
  T tmp = tail->data;
  if(tail->parent)
  {
    tail=tail->parent;
    tail->child=NULL;
  }
  else
  {
    head=NULL;
    tail=NULL;
  }
  return tmp;
}

template<class T>
T LinkedList<T>::pop(int index)
{
  assert(head!=NULL);
  Node<T> *curr = head;
  while(curr->child and index>0)
  {
    curr=curr->child;
    index--;
  }
  if(index>1)
  {
    throw "IndexOutOfBounds";
  }

  T tmp=curr->data;

  //if is not last
  if(curr->child)
    curr->child->parent=curr->parent;
  else
    tail==curr->parent;

  //if is not first
  if(curr->parent)
    curr->parent->child=curr->child;
  else
    head=curr->child;
  return tmp;
}

template<class T>
bool LinkedList<T>::remove(T data)
{
  Node<T> *curr=head;
  while(curr)
  {
    if(curr->data==data)
      break;
    else
      curr=curr->child;
  }
  if(curr)
  {
    //if is not last
    if(curr->child)
      curr->child->parent=curr->parent;
    else
      tail==curr->parent;

    //if is not first
    if(curr->parent)
      curr->parent->child=curr->child;
    else
      head=curr->child;
    return true;
  }
  return false;
}

template<class T>
int LinkedList<T>::find(T data)
{
  Node<T> *curr = head;
  int index=0;
  while(curr)
  {
    if(curr->data==data)
    {
      return index;
    }
    curr=curr->child;
    index++;
  }
  return -1;
}

template<class T>
std::string LinkedList<T>::toString()
{
  std::stringstream ss;
  ss << "[";
  Node<T> *top = head;
  while(top)
  {
    if(top!=head)
    {
      ss<<",";
    }
    ss << top->data;
    top=top->child;
  }
  ss<<"]";
  return ss.str();
}

template<class T>
bool LinkedList<T>::empty()
{
  return (!head);
}
