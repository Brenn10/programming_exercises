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
#include <math.h>
#include <iostream>

using namespace std;

void Sorts::swap(int* L, int a, int b)
{
  //tmpless swap
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
    //go from current to begining and swap while the current is greater tean the previous
    while (L[j-1]>L[j]) {
      Sorts::swap(L,j-1,j);
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
  //call the recursive sort
  Sorts::merge(L,0,len-1);
}

void Sorts::merge(int* L,int l, int r)
{
  //if not 1 item
  if(l<r)
  {
    //find middle
    int m = (l+r)/2;

    //call sort on each half
    Sorts::merge(L,l,m);
    Sorts::merge(L,m+1,r);

    //combine the resulting sorted arrays
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

  //if left child in bounds,and bigger than current
  if(l<=len)
    if(L[l]>L[t])
      t=l;
  //if right child in bounds and bigger than current
  if(r<=len)
    if(L[r]>L[t])
      t=r;
  //if either were bigger, swap and sift on that item, propagate down
  if(t!=i)
  {
    Sorts::swap(L,t,i);
    Sorts::siftDown(L,t,len);
  }

}

void Sorts::heapify(int* L, int len)
{
  //build heap
  for(int i = (len-1)/2; i>=0;i--)
  {
    Sorts::siftDown(L,i,len-1);
  }
}

void Sorts::heap(int* L, int len)
{
  //build the heap
  Sorts::heapify(L,len);
  /*
  While the heap is a thing, take the top element(at index 0), swap with the
  last element in the heap's array allotment, then reduce the size to exclude
  the largest item which is at the end, sift the head down because it is smol

  */
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
  //select item at end as the pivot point
  int pivot = L[e];
  int i = s-1;
  /*
  split given section into two sections where everything on the left is lower
  than the pivot point
  */
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
  //divide and conquer, if partition len>1, split and sort
  if(s<e)
  {
    int m = Sorts::partition(L,s,e);
    Sorts::quick(L,s,m-1);
    Sorts::quick(L,m+1,e);
  }
}

void Sorts::quick(int* L,int len)
{
  //call recursive sort
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
    //go from the start to finish swapping if next is lower
    for(int i=0; i <last;i++)
    {
      if(L[i]>L[i+1])
      {
        Sorts::swap(L,i,i+1);
        finished=false;
      }
    }
    //after each pass, last is biggest so reduce size
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

    //dump buckets back to the array
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
  //gives log with base b through change of base formula
  return int(log(x)/log(b));
}
