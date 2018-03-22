#!/usr/bin/python3

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
