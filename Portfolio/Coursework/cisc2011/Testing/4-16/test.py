import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def Perspective(X, a, u, c):
    #X is a 3 by N array


    print( (u.T@(X - a)).shape )

#    return Px # a 3 by N array 

N = 100
t = np.linspace(0,6*np.pi,N).reshape(N,1)
r = np.sqrt(1+t)
H = 0.1*np.array([ r*np.cos(t), r*np.sin(t), 0.5*t ]).reshape((3,N))
#print(H.shape)

a = np.array([2, 2, -0.5]).reshape((3,1))

u = np.array([1, 1, 1]).reshape((3,1))
u = u/np.linalg.norm(u)

v = np.array([1, 0, -1]).reshape((3,1))
v = v/np.linalg.norm(v)

w = np.array([1, -2, 1]).reshape((3,1))
w = w/np.linalg.norm(w)

c = 1.5

s = np.linspace(-5,5,20)
t = np.linspace(-5,5,20)
s, t = np.meshgrid(s,t)

uTu = u.T@u #length of u squared
x0  = c*u/uTu #a point on the plane  

X = x0[0] + s*v[0] + t*w[0]
Y = x0[1] + s*v[1] + t*w[1]
Z = x0[2] + s*v[2] + t*w[2]

Perspective(H, a, u, c)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot(H[0,:],H[1,:],H[2,:])

ax.plot_surface(X,Y,Z,color = 'gray', alpha=0.5)
ax.scatter(a[0], a[1], a[2])
ax.quiver(x0[0],x0[1],x0[2],u[0],u[1],u[2],length=1.0)
ax.quiver(x0[0],x0[1],x0[2],v[0],v[1],v[2],length=1.0)
ax.quiver(x0[0],x0[1],x0[2],w[0],w[1],w[2],length=1.0)

ax.set_xlim(-2,2)
ax.set_ylim(-2,2)
ax.set_zlim(-2,2)
ax.set_aspect(1)
plt.show()

