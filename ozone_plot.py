
import numpy as np
import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.tools as tls
 
X = [0,3,6,9,12,15,18,21,24,27,30,35]
Y = [11.54,12.96,13.59,14.63,15.26,15.30,15.11,15.91,16.1,16.3,16.2,15.8]


plt.scatter(X, Y, s=70, c='red', marker='.')
plt.plot(X,Y)
#change axes ranges
plt.xlim(0,30)
plt.ylim(11,16)
plt.xticks(np.linspace(0, 30, 11, endpoint=True))
plt.yticks(np.linspace(11, 17,11, endpoint=True))

plt.title('Plot of Ozone Sensor Values')
plt.xlabel('TIME IN MIN.')
plt.ylabel('OZONE VALUE IN PPB')


plt.show()
