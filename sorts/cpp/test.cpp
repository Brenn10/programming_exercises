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

#include "Sorts.h"
#include "iostream"
#include <ctime>
#include <cstdlib>
using namespace std;
bool testInsertion(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::insertion(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testSelection(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::selection(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testMerge(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::merge(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testHeap(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::heap(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testQuick(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::quick(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testBubble(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::bubble(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testComb(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::comb(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
bool testRadix(int items) {
  int a[items];
  for(int i =0 ; i < items;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::radix(a,items);
  for(int i =1; i < items; i++)
  {
    if(a[i]<a[i-1])
      return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  if(argc<2) {
    cout << "Needs at least one argument"<<endl;
    return -1;
  }
  int items = atoi(argv[1]);


  if(testInsertion(items)) {
    cout << "Insertion: \tSuccess" << endl;
  } else {
    cout << "Insertion: \tFailed" << endl;
  }
  if(testSelection(items)) {
    cout << "Selection: \tSuccess" << endl;
  } else {
    cout << "Selection: \tFailed" << endl;
  }
  if(testMerge(items)) {
    cout << "Merge: \t\tSuccess" << endl;
  } else {
    cout << "Merge: \t\tFailed" << endl;
  }
  if(testHeap(items)) {
    cout << "Heap: \t\tSuccess" << endl;
  } else {
    cout << "Heap: \t\tFailed" << endl;
  }
  if(testQuick(items)) {
    cout << "Quick: \t\tSuccess" << endl;
  } else {
    cout << "Quick: \t\tFailed" << endl;
  }
  if(testBubble(items)) {
    cout << "Bubble: \tSuccess" << endl;
  } else {
    cout << "Bubble: \tFailed" << endl;
  }
  if(testComb(items)) {
    cout << "Comb: \t\tSuccess" << endl;
  } else {
    cout << "Comb: \t\tFailed" << endl;
  }
  if(testRadix(items)) {
    cout << "Radix: \t\tSuccess" << endl;
  } else {
    cout << "Radix: \t\tFailed" << endl;
  }
  return 0;
}
