import numpy as np

# The v1, v2, and v3 span R^3 with probability of (basically) 1
# We can check by det(Q)
Q = np.random.random((3,3)) 

print("Starting matrix:")
print(Q)

u = Q[:,0]
v = Q[:,1]
w = Q[:,2]

# Gram-Schmidt Process
u /= np.linalg.norm(u)
v -= v.dot(u) * u
v /= np.linalg.norm(v)
w -= w.dot(u) * u  + w.dot(v) * v
w /= np.linalg.norm(w)

Q[:,0] = u
Q[:,1] = v
Q[:,2] = w

print("New orthonormal matrix dotted with its transpose:")
print(Q@Q.T)

U = u.copy().reshape(3,1)
V = v.copy().reshape(3,1)
W = w.copy().reshape(3,1)

# Rotation with theta = 0
print("Rotation with theta = 0:")
print(U@U.T + V@V.T + W@W.T)

th = np.pi/200
co = np.cos(th)
si = np.sin(th)

A = U @ U.T + co * (V @ V.T) - si * (V @ W.T) + si * (W @ W.T) + co * (W @ W.T)

print("Rotation of", th, "radians:")
print(A)
