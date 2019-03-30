
import numpy as np
import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.tools as tls
 
X = [0,3,6,9,12,15,18,21,24,27,30,35]
Y = [66,69,75,70,69,119,102,90,166,74,135,80]


plt.scatter(X, Y, s=70, c='red', marker='s')
plt.plot(X,Y)
#change axes ranges
plt.xlim(0,30)
plt.ylim(50,180)
plt.xticks(np.linspace(0, 30, 11, endpoint=True))
plt.yticks(np.linspace(50, 180,11, endpoint=True))

plt.title('Plot of Methane Sensor Values')
plt.xlabel('TIME IN MIN.')
plt.ylabel('OZONE VALUE IN PPM')


plt.show()
