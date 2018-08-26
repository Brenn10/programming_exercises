/*
* MIT License
*
* Copyright (c) 2018 Brennan Cain
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "LinkedList.h"

LinkedList::LinkedList() {
  head=nullptr;
  tail=nullptr;
  size=0;
}

LinkedList::LinkedList(T** arr) : LinkedList(){
  for(int i =0; i < sizeof(arr)/sizeof(T);++i) {
    this->push_back(*arr[i]);
  }
}

LinkedList::LinkedList(const List &l) : LinkedList() {
  for(int i=0; i < l->size();++i) {
    this->pop_back(l->at(i));
  }
}

T LinkedList::peek_front() {
  if(head) {
    return this->head->data;
  }
  else {
    return nullptr;
  }
}

T LinkedList::peek_back() {
  if(tail) {
    return this->tail->data;
  }
  else {
    return nullptr;
  }
}

T LinkedList::at(int i) {
  if(i<this->size() and head) {
    DLLNode_t curr=head;
    for(int u = 0; u < i; u++) {
      curr=curr->child;
    }
  }
}

bool LinkedList::push_front(T data) {
  if(head) {
    DLLNode_t *newHead();
    newHead->child=head;
    head->parent=newHead;
    head=newHead;
  } else {
    head = new DLLNode_t();
  }
  head->data=data;
  ++this->size;
}
