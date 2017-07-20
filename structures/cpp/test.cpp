#include <LinkedList.h>
#include "LinkedList.cpp"
#include <iostream>
using namespace std;

int main()
{
  LinkedList<int> ll = LinkedList<int>();
  cout <<"Created"<<endl;
  ll.addFront(1);
  ll.addFront(2);
  ll.addBack(5);
  cout << ll.find(5)<<endl;
  cout << ll.toString()<<endl;
}
