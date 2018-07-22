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

#ifndef BSC_SORTS_H
#define BSC_SORTS_H
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
