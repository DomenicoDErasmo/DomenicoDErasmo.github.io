import matplotlib.pyplot as plt
x = [ i/20.0 for i in range(-20, 21)] #some x values between -1 and 1
y1 = []
y2 = []
for i in range(len(x)):
    y1.append(x[i]*x[i]) #some sample y-values: a parabola
    y2.append(3*x[i] + 1) #further sample y-values: a line
plt.plot(x,y1,'k') #a black curve
plt.plot(x,y2,'b') #a blue curve
plt.plot(x,y2,'r+') #red plus markers
plt.show()

import random
x = []
y = []
for i in range(1000):
    x.append(random.random()-0.5)
    y.append(random.random()-0.5)
plt.plot(x,y,'y+')
plt.axhline(0, color='black') #adds a horizontal axis
plt.axvline(0, color='black') #...a vertical axis
plt.show()

