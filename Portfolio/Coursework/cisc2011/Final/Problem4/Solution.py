import numpy as np
print("Part 1:")

A = np.random.random((4,4)) 

# Setting up column vectors
w = A[:,0]
x = A[:,1]
y = A[:,2]
z = A[:,3]

# Gram-Schmidt Orthogonalization
w /= np.linalg.norm(w)
x -= x.dot(w) * w
x /= np.linalg.norm(x)
y -= y.dot(x) * x + y.dot(w) * w
y /= np.linalg.norm(y)
z -= z.dot(y) * y + z.dot(x) * x + z.dot(w) * w
z /= np.linalg.norm(z)

# Checking
print("A: ")
print(A)
print("Checking for orthogonality:")
print(A.T@A)

print("Part 2:")

# Building the matrix
B = np.zeros((100,100))
B[0,0] = 2; B[0,1] = -1
for i in range(1,99):
    B[i,i] = 2; B[i,i-1] = -1; B[i,i+1] = -1
B[99,99] = 2; B[99,98] = -1

# I feel somewhat guilty for using a built-in function instead of coming up with an algorithm myself. Have I sinned?
eigvals, eigenvectors = np.linalg.eig(B)
min_eigval = eigvals[0]
col = 0
for i in range(eigvals.shape[0]):
    if eigvals[i] < min_eigval:
        min_eigval = eigvals[i]
        col = i,

print("Eigenvalues are:")
print(eigvals)
print ("The minimum eigenvalue is " + str(min_eigval))
print("This eigenvalue's vector is:")
print(eigenvectors[:,col])


import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# I am graphing the vector projected into 3-space because graphing a 100-dimensional vector sounds crazy complex
projected_min_eigenvector = eigenvectors[0:3, col]
print("The eigenvector projected to 3-space is " + str(projected_min_eigenvector))

# 3D Graph setup
fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot3D([0, eigenvectors[0, col]], [0, eigenvectors[1, col]], [0, eigenvectors[2, col]])
plt.show()
