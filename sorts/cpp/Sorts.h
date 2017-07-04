#ifndef SORTS_H
#define SORTS_H
class Sorts
{
  public:
    static void insertion(int* L,int len);
    static void selection(int* L,int len);
    static void merge(int* L,int len);
    static void heap(int* L,int len);
    static void quick(int* L,int len);
    static void bubble(int* L,int len);
    static void comb(int* L,int len);
    static void radix(int* L,int len,int n=10);
  private:
    static void swap(int* L, int a,int b);
    static void mergeTwoArrays(int* L, int l, int m, int r);
    static void merge(int* L,int l,int r);
    static void siftDown(int* L, int i, int len);
    static void heapify(int* L, int len);
    static int partition(int* L,int s,int e);
    static void quick(int* L, int s,int e);
    static int log_b(int x, int b);
};
#endif
