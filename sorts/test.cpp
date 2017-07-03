#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sorts.h"

using namespace std;

int main(int argc, char const *argv[]) {

  //generate numbers
  srand(time(0));
  const int len = 100;
  int a[len];
  for(int i = 0 ; i < len; i++)
    a[i]=rand();


  //sort and print
  Sorts::quick(a,len);
  cout <<endl;
  for(int i =0; i < len;i++)
  {
    cout << a[i]<<endl;
  }


  bool success=true;
  for(int i =1; i < len;i++)
  {
    if(a[i]<a[i-1])
      success=false;
  }

  cout <<"Success:"<<(success?"Good":"bad")<<endl;
  return 0;
}
