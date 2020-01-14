import numpy as np
import matplotlib.pyplot as plt

# Makes a random 2x10 array of coordinate values from -1 to 1
# Reason for this order: when we multiply Ax, we need the row dimension of x to equal the column dimension of A
# Random goes from 0 to 1, the "- 0.5" makes it -0.5 to 0.5, the "2 *" makes it -1 to 1
X = 2 * (np.random.random((2,10))- 0.5)

# Angle to rotate around
theta = np.pi/60

# Rotation matrix for theta = pi/6
A = np.array([[np.cos(theta), -np.sin(theta)], [np.sin(theta), np.cos(theta)]])

# Transformation
Ax = A@X

plt.plot(X[0,:] , X[1,:], 'r+')
plt.plot(Ax[0,:] , Ax[1,:], 'b+')
plt.plot(0, 0, "ko")
plt.axis("square")
plt.xticks([])
plt.yticks([])
plt.show()

plt.clf()

new_theta = theta
# plots 60 rotations of pi/60 radians and clears so that the path is "animated"
for i in range(60):

    # magnitude appraoches 0 with a scalar < 1
    Ax = A@Ax
    new_theta += theta
    plt.plot(X[0,:] , X[1,:], 'r+')
    plt.plot(Ax[0,:] , Ax[1,:], 'b+')
    plt.plot([0,1], [0,0], 'k')
    plt.plot([0, np.cos(new_theta)], [0, np.sin(new_theta)], 'k')
    plt.plot(0, 0, 'ko')
    plt.axis("square")
    plt.draw()
    plt.xlim(-2,2)
    plt.ylim(-2,2)
    plt.pause(0.5)
    plt.clf() 
