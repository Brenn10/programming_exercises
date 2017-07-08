#include "Sorts.h"
#include "iostream"
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {
  int a[100];
  for(int i =0 ; i < 100;i++)
  {
    int num = rand();
    a[i]=num;
  }
  Sorts::insertion(a,100);
  for(int i =1; i < 100; i++)
  {
    if(a[i]<a[i-1])
      cout <<"FAILURE"<<endl;
  }
  return 0;
}
