# MIT License
#
# Copyright (c) 2018 Brennan Cain
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
import Sorts

import sys
import random

def testInsertion(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.insertion(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testSelection(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.selection(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testMerge(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.merge(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testHeap(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.heap(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testQuick(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.quick(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testBubble(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.bubble(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testComb(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.comb(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True
def testRadix(n,mn,mx):
    L = random.sample(range(mn, mx), n)
    Sorts.radix(L)
    for i in range(len(L)-2):
        if(L[i]>L[i+1]):
            return False
    return True

if __name__ == '__main__':
    n=int(sys.argv[1])
    mn=0
    mx=n*2
    print("Insertion: \t%s" %("Success" if testInsertion(n,mn,mx) else "Failure"))
    print("Selection: \t%s" %("Success" if testSelection(n,mn,mx) else "Failure"))
    print("Merge: \t\t%s" %("Success" if testMerge(n,mn,mx) else "Failure"))
    print("Heap: \t\t%s" %("Success" if testHeap(n,mn,mx) else "Failure"))
    print("Quick: \t\t%s" %("Success" if testQuick(n,mn,mx) else "Failure"))
    print("Bubble: \t%s" %("Success" if testBubble(n,mn,mx) else "Failure"))
    print("Comb: \t\t%s" %("Success" if testComb(n,mn,mx) else "Failure"))
    print("Radix: \t\t%s" %("Success" if testRadix(n,mn,mx) else "Failure"))
