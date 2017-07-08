#include "BinaryTree.h"
#include "iostream"
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {
  BinaryTree tree;
  srand(time(NULL));
  for(int i =0 ; i < 100;i++)
  {
    int num = rand();
    cout << num << endl;
    tree.add(num);
  }
  cout<<tree.toString()<<endl;
  return 0;
}