#include "Sorts.h"
#include <math.h>
#include <iostream>

using namespace std;

void Sorts::swap(int* L, int a, int b)
{
  L[a] = L[a]+L[b];
  L[b] = L[a]-L[b];
  L[a] = L[a]-L[b];
}
void Sorts::insertion(int* L,int len)
{
  //from 1 to end
  for(int i=1;i<len;i++)
  {
    int j = i;
    //go from current to begiining and swap while the current is greater tean the previous
    while (L[j-1]>L[j]) {
      //tmp-less swap
      Sorts::swap(L,j,j-1);
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
      Sorts::swap(L,i,min);
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
  //get lengths of both new arrays
  int lenR=r-m;
  int lenL=m-l+1;

  //create tmp arrays and copy
  int tmpL[lenL],tmpR[lenR];

  for(int i =0; i < lenL;i++)
  {
    tmpL[i]=L[i+l];
  }
  for(int i =0; i < lenR;i++)
  {
    tmpR[i]=L[i+m+1];
  }

  //while neither is empty
  int iR=0,iL=0,i =0;
  while(iR<lenR and iL<lenL)
  {
    //if the left lowest is lower then right
    if(tmpR[iR]<tmpL[iL])
    {
      L[i+l]=tmpR[iR];
      iR++;
    }
    //if they are equal or right is lower
    else
    {
      L[i+l]=tmpL[iL];
      iL++;
    }
    i++;
  }

  //Left is empty so empty right
  while(iR<lenR)
  {
    L[i+l]=tmpR[iR];
    iR++;
    i++;
  }
  //right is empty so empty left
  while(iL<lenL)
  {
    L[i+l]=tmpL[iL];
    iL++;
    i++;
  }
}

void Sorts::siftDown(int* L, int i, int len)
{
  int t = i;//largest element
  int l = i*2+1;//left child
  int r = i*2+2;//right child

  if(l<=len)
    if(L[l]>L[t])
      t=l;
  if(r<=len)
    if(L[r]>L[t])
      t=r;
  if(t!=i)
  {
    Sorts::swap(L,t,i);
    Sorts::siftDown(L,t,len);
  }

}

void Sorts::heapify(int* L, int len)
{
  for(int i = (len-1)/2; i>=0;i--)
  {
    Sorts::siftDown(L,i,len-1);
  }
}

void Sorts::heap(int* L, int len)
{
  Sorts::heapify(L,len);
  int end = len-1;
  while(end>0)
  {
    Sorts::swap(L,0,end);

    end-=1;
    Sorts::siftDown(L,0,end);
  }
}

int Sorts::partition(int* L,int s, int e)
{
  int pivot = L[e];
  int i = s-1;
  for(int j = s; j <=e; j++)
  {
    if(L[j]<=pivot)
    {
      i++;
      if(j!=i)
      {
        Sorts::swap(L,i,j);
      }
    }
  }
  return i;
}

void Sorts::quick(int* L, int s,int e)
{
  if(s<e)
  {
    int m = Sorts::partition(L,s,e);
    Sorts::quick(L,s,m-1);
    Sorts::quick(L,m+1,e);
  }
}

void Sorts::quick(int* L,int len)
{
  Sorts::quick(L,0,len-1);
}

void Sorts::bubble(int* L, int len)
{
  //if no swaps in last iteration, done
  bool finished=false;

  //last unit to look at, after each pass, last is greatest so shrink
  int last = len-1;
  while( not finished )
  {
    finished=true;
    for(int i=0; i <last;i++)
    {
      if(L[i]>L[i+1])
      {
        Sorts::swap(L,i,i+1);
        finished=false;
      }
    }
    last--;
  }
}

void Sorts::comb(int* L, int len)
{
  double shrink = 1.3;

  //until gap = 1, do normal comb sort
  for(int gap = len/shrink;gap>1;gap/=shrink)
  {
    for(int i = 0; i + gap < len; i++)
    {
      if(L[i]>L[i+gap])
      {
        Sorts::swap(L,i,i+gap);
      }
    }
  }

  //when gap==1, this becomes bubble, so call bubble
  Sorts::bubble(L,len);
}

void Sorts::radix(int* L, int len,int n)
{
  int max=0;
  for(int i =1; i < len; i++)
  {
    if(L[i]>L[max])
      max=i;
  }
  int bucket[n][len+1];
  int sig = Sorts::log_b(L[max],n);

  //start from least and go to most significant figure
  for( int j=0; j <=sig; j++)
  {
    //get buckets ready, 0th index is the count in bucket

    for(int i =0; i <= n; i++)
    {
      bucket[i][0]=0;
    }

    //bucketify
    for(int i =0; i < len; i++)
    {
      int buck = int(L[i]/(pow(n,j)))%n;
      int index = bucket[buck][0];
      bucket[buck][index+1] = L[i];
      bucket[buck][0]+=1;
    }

    //empty buckets back to the array
    int buck=0,ind=1;
    for(int i =0; i < len; i++)
    {
      if(ind == bucket[buck][0]+1)
      {
        ind=1;
        buck++;
      }
      L[i]=bucket[buck][ind];
      ind+=1;
    }
  }
}

int Sorts::log_b(int x,int b)
{
  return int(log(x)/log(b));
}
