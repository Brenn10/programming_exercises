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
