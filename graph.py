
import numpy as np
import matplotlib.pyplot as plt
 
X = [0,10,7,13,21,3,8,9,25,30,24,30,20,8,5,16,27,24,33,29,31,9]
Y = [32,34,32,32.3,31.2,32.7,34,34.6,33.8,34.1,30.1,32,34,31,32.5,31.6,32.8,34.8,34.2,33.67,34.3,30.8]


plt.scatter(X, Y, s=70, c='red', marker='^')

#change axes ranges
plt.xlim(0,35)
plt.ylim(0,50)

plt.xlabel('TIME IN MIN.')
plt.ylabel('OZONE VALUE IN PPB')


plt.show()