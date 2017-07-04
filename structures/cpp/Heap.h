#include "Heap.h"
#include "Node.h"

#ifndef HEAP_H
#define HEAP_H

class Heap
{
  public:
    void add(int element);
    int remove();
  private:
    Node* head;
};

#endif
