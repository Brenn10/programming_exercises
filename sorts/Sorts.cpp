#include "Sorts.h"
#include <iostream>

using namespace std;

void Sorts::insertion(int* L,int len)
{
  //from 1 to end
  for(int i=1;i<len;i++)
  {
    int j = i;
    //go from current to begiining and swap while the current is greater tean the previous
    while (L[j-1]>L[j]) {
      //tmp-less swap
      L[j]=L[j]+L[j-1];
      L[j-1]=L[j]-L[j-1];
      L[j]=L[j]-L[j-1];
      j--;
      if(j==0)
      {
        break;
      }
    }
  }
}

void Sorts::selection(int* L,int len)
{
  //go through each except the last
  for(int i = 0; i < len-1;i++)
  {
    int min =i;
    //go through the rest of the array and find the min
    for(int j = i+1; j < len; j++)
    {
      if(L[j] < L[min])
      {
        min=j;
      }
    }

    if(min!=i)
    {
      //tmp-less swap
      L[i]=L[i]+L[min];
      L[min]=L[i]-L[min];
      L[i]=L[i]-L[min];
    }

  }
}

void Sorts::merge(int* L,int len)
{
  Sorts::merge(L,0,len-1);
}

void Sorts::merge(int* L,int l, int r)
{
  if(l<r)
  {
    int m = (l+r)/2;

    Sorts::merge(L,l,m);
    Sorts::merge(L,m+1,r);

    Sorts::mergeTwoArrays(L,l,m,r);
  }
}

void Sorts::mergeTwoArrays(int* L,int l, int m, int r)
{
  int lenR=r-m;
  int lenL=m-l+1;
  //create tmp arrays
  int tmpL[lenL],tmpR[lenR];

  for(int i =0; i < lenL;i++)
  {
    tmpL[i]=L[i+l];
  }
  for(int i =0; i < lenR;i++)
  {
    tmpR[i]=L[i+m+1];
  }

  int iR=0,iL=0,i =0;
  while(iR<lenR and iL<lenL)
  {
    if(tmpR[iR]<tmpL[iL])
    {
      L[i+l]=tmpR[iR];
      iR++;
    }
    else
    {
      L[i+l]=tmpL[iL];
      iL++;
    }
    i++;
  }
  while(iR<lenR)
  {
    L[i+l]=tmpR[iR];
    iR++;
    i++;
  }
  while(iL<lenL)
  {
    L[i+l]=tmpL[iL];
    iL++;
    i++;
  }
}
