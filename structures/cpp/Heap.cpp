#include "Heap.h"
#include "Node.h"

Heap::Heap() {
  head=NULL;
}
void Heap::add(int data)
{
  if(head==NULL)
  {
    Node *tmp;
    (*tmp).parent=NULL;
    (*tmp).leftChild=NULL;
    (*tmp).rightChild=NULL;
    (*tmp).data=data;
    head=&tmp;
  }
  else
  {
    
  }
}
