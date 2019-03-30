
import numpy as np
import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.tools as tls
 
X = [0,3,6,9,12,15,18,21,24,27,30,35]
Y = [0,55,165,688,212,307,1300,890,131,10,477,287]


plt.scatter(X, Y, s=70, c='green', marker='d')
plt.plot(X,Y)

#change axes ranges
plt.xlim(0,30,4)
plt.ylim(0,1500)

plt.xticks(np.linspace(0, 30, 11, endpoint=True))
plt.yticks(np.linspace(0, 1500,11, endpoint=True))
plt.title('Plot of VOC Sensor Values')
plt.xlabel('TIME IN MIN.')
plt.ylabel('VOC VALUE IN PPB')


plt.show()
