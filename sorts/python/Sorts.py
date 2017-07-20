import math
import random
## Swap two values without a tmp variable
#
# @param L List to do action on
# @param a Index 1
# @param b Index 2
def _swap(L,a,b):
    if(L[a]!=L[b]):
        L[a]=L[a]+L[b]
        L[b]=L[a]-L[b]
        L[a]=L[a]-L[b]

## Apply Insertion sort to List
#
# @param L List to be sorted
def insertion(L):
    #from beginning+1 to teh end
    for i in range(1,len(L)):
        j=i
        #find where the current item fits
        while j>0 and L[j-1]>L[i]:
            j-=1
        if(i!=j):
            L.insert(j,L[i])
            del L[i+1]

## Apply selection sort to List
#
# @param L List to be sorted
def selection(L):
    for i in range(len(L)-1):
        min=i
        for j in range(i+1,len(L)):
            if(L[j]<L[min]):
                min=j
        _swap(L,i,min)

## Apply merge sort to List
#
# @param L List to be sorted
def merge(L):
    if(len(L)!=1):
        m=len(L)//2
        a=L[:m]
        b=L[m:]
        merge(a)
        merge(b)
        i = 0
        while(len(a)>0 and len(b)>0):
            L[i]= (a.pop(0) if a[0]<b[0] else b.pop(0))
            i+=1
        while(len(a)>0):
            L[i]=a.pop(0)
            i+=1
        while(len(b)>0):
            L[i]=b.pop(0)
            i+=1

## move item at index i to its proper position
#
# @param L List to be sorted
# @param i index of item to sift down
def sift_down(L,i):
    length=len(L)-1
    t=i
    l=i*2+1
    r=i*2+2
    if(l<=length):
        if(L[l]>L[t]):
            t=l
    if(r<=length):
        if(L[r]>L[t]):
            t=r
    if(t!=i):
        _swap(L,t,i)
        sift_down(L,t,length)

## builds heap
#
# @param L list to be heapified
def build_heap(L):
    for i in range((len(L)-1)//2,-1,-1):
        sift_down(L,i)

## Heap Sorts
#
# @param List to be sorted
def heap(L):
    build_heap(L)
    end = len(L)-1
    while(end > 0):
        _swap(L,0,end)
        end-=1
        sift_down(L,0,end)

##Partition given list between indicies s and e
#
# @param L List to be partitioned
# @param s start index
# @param e end index
#
# @return index dividing the two partitions
def partition(L,s,e):
    p = L[e]
    i = s-1

    for j in range(s,e+1):
        if(L[j]<=p):
            i+=1
            if(j!=i):
                _swap(L,i,j)
    return i

## Quick sort the list
#
# Set both the start and end indicies to -1 to signify launching the sort
#
# @param L list to be sorted
# @param s start index of the partition
# @param e end index o fthe partition
def quick(L,s=-1,e=-1):
    if(s==-1 and e==-1):
        quick(L,0,len(L)-1)
    else:
        if(s<e):
            m = partition(L,s,e)
            quick(L,s,m-1)
            quick(L,m+1,e)

## Bubble sort
#
# @param L list to be sorted
def bubble(L):
    done = False
    e=len(L)-1
    while not done:
        done = True
        for i in range(e):
            if(L[i]>L[i+1]):
                done = False
                _swap(L,i,i+1)
        e-=1

## Comb sort
#
# @param L list to be sorted
def comb(L):
    shrink = 1.3;
    gap = int(len(L)/shrink)
    while gap>1:
        for i in range(len(L)-gap):
            if(L[i]>L[i+gap]):
                _swap(L,i,i+gap)
        gap=int(gap/shrink)
    bubble(L)

## Radix sort
#
# @param L List to be sorted
# @param bins number of bins to use
def radix(L,bins=10):
    bucket = [[] for i in range(bins)]
    sig = int(math.log(max(L),bins))

    for i in range(sig+1):

        #bucketify
        for item in L:
            which_bucket=int(item/(pow(bins,i)))%bins
            bucket[which_bucket].append(item)
        #debucketify
        index =0
        for bin in range(bins):
            while bucket[bin]:
                L[index]=bucket[bin].pop(0)
                index+=1
