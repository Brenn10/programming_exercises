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

#ifndef BSC_LINKEDLIST_H
#define BSC_LINKEDLIST_H

#include "List.h"

template<class T>
class LinkedList : public List
{
  public:
    LinkedList();
    LinkedList(T** arr);
    LinkedList(List l);

    T peek_front();
    T peek_back();
    T at(int index);

    bool push_front(T data);
    bool push_back(T data);

    bool insert(T data, int index);

    T pop_front();
    T pop_back();

    T remove(int index);

    bool contains(T data);

    void shuffle();
    void sort();

    int size();
  private:
    struct DLLNode_t {
      T data;
      DLLNode_t* parent;
      DLLNode_t* child;
    };

    DLLNode_t *head;
    DLLNode_t *tail;
    int size;

};
#endif
