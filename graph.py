
import numpy as np
import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.tools as tls
 
X = [0,3,6,9,12,15,18,21,24,27,30,35]
Y = [62,63.5,65,67.3,69,70.7,71,72.6,73.8,74,77,0]


plt.scatter(X, Y, s=70, c='greem', marker='*')

#change axes ranges
plt.xlim(0,35,4)
plt.ylim(60,80)

plt.title('Plot of Ozone sensor')
plt.xlabel('TIME IN MIN.')
plt.ylabel('OZONE VALUE IN PPM')


plt.show()
