
import numpy as np
import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.tools as tls
 
X = [0,3,6,9,12,15,18,21,24,27,30]
Y = [1900,481,1612,586,4343,3400,400,898,2179,650,1117]


plt.scatter(X, Y, s=70, c='blue', marker='o')
plt.plot(X,Y)
#change axes ranges
plt.xlim(0,30)
plt.ylim(200,4900)
plt.xticks(np.linspace(0, 30, 11, endpoint=True))
plt.yticks(np.linspace(0, 4900,9, endpoint=True))

plt.title('Plot of CO2 Sensor Values')
plt.xlabel('TIME IN MIN.')
plt.ylabel('CO2 VALUE IN PPM')


plt.show()
