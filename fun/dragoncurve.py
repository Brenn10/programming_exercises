#!/usr/bin/python3

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
import numpy as np
import matplotlib.pyplot as plt
import sys
import time

M1=[np.array([0,1]),np.array([0,0]),np.array([1,0])]


for i in range(int(sys.argv[1])):
	print("I=%i"%i)
	for u in range(len(M1)):
		M1[u]=(M1[u]-[0,1]).dot([[.5,-.5],[.5,.5]])+[0,1]
	for i in M1[-2::-1]:
		M1.append(i.dot([[0,-1],[1,0]]))

plt.plot([V[0] for V in M1],[V[1] for V in M1])
plt.margins(.05,.05)
plt.show()
