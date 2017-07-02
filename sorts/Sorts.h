#ifndef SORTS_H
#define SORTS_H
class Sorts
{
  public:
    static int len(int* L,int len);
    static void insertion(int* L,int len);
    static void selection(int* L,int len);
    static void merge(int* L,int len);
    static void heap(int* L,int len);
    static void quick(int* L,int len);
    static void bubble(int* L,int len);
    static void shell(int* L,int len);
    static void comb(int* L,int len);
    static void counting(int* L,int len);
    static void bucket(int* L,int len);
    static void radix(int* L,int len);
  private:
    static void mergeTwoArrays(int* L, int l, int m, int r);
    static void merge(int* L,int l,int r);
};
#endif
