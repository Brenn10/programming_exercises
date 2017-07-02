#include <iostream>
#include "Sorts.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int seq[5]={5,4,3,2,1};
  Sorts::merge(seq,5);
  for(int i =0; i < 5;i++)
  {
    cout << seq[i]<<endl;
  }
  return 0;
}
