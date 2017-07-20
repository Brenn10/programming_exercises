#include <string>


#ifndef BSC_LINKED_LIST_H
#define BSC_LINKED_LIST_H

template<class T>
struct Node {
  T data;
  struct Node<T> *parent;
  struct Node<T> *child;
};

template<class T>
class LinkedList {
public:
  void addFront(T data);
  void addBack(T data);
  T popFront();
  T popBack();
  T pop(int index);
  bool remove(T data);
  int find(T data);
  std::string toString();
  bool empty();
private:
  struct Node<T> *head;
  struct Node<T> *tail;
};
#endif
