import DErasmoDomenico_Lab3mod as mymod
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d

def graph_vectors(v1, v2, start_point, function):
    fig = plt.figure()
    axes = fig.add_subplot(111, projection = '3d')
    v3 = function(v1, v2)
    x_starts, y_starts, z_starts = zip(start_point, start_point, start_point)
    x_coords, y_coords, z_coords = zip(v1, v2, v3)
    print ("x_coords are", x_coords, "y_coords are", y_coords, "z_coords are", z_coords)
    axes.set_xlim3d(min(x_coords) * 0.95, max(x_coords) * 1.05)
    axes.set_ylim3d(min(y_coords) * 0.95, max(y_coords) * 1.05)
    axes.set_zlim3d(min(z_coords) * 0.95, max(z_coords) * 1.05)
    axes.quiver(x_starts, y_starts, z_starts, x_coords, y_coords, z_coords)
    plt.show()

def graph_lincomb(vector_list, scalar_list, start_point):
    fig = plt.figure()
    axes = fig.add_subplot(111, projection = '3d')
    v4 = mymod.lincomb(vector_list, scalar_list)
    x_starts, y_starts, z_starts = zip(origin, origin, origin, origin)
    x_coords, y_coords, z_coords = zip(vector_list[0], vector_list[1], vector_list[2], v4)
    print ("x_coords are", x_coords, "y_coords are", y_coords, "z_coords are", z_coords)
    axes.set_xlim3d(min(x_coords) * 0.95, max(x_coords) * 1.05)
    axes.set_ylim3d(min(y_coords) * 0.95, max(y_coords) * 1.05)
    axes.set_zlim3d(min(z_coords) * 0.95, max(z_coords) * 1.05)
    axes.quiver(x_starts, y_starts, z_starts, x_coords, y_coords, z_coords)
    plt.show()

def graph_scaled(vector, scalar, start_point):
    fig = plt.figure()
    axes = fig.add_subplot(111, projection = '3d')
    v2 = mymod.scale(vector, scalar)
    x_starts, y_starts, z_starts = zip(start_point, start_point)
    x_coords, y_coords, z_coords = zip(vector, v2)
    print ("With scalar", scalar,"x_coords are", x_coords, "y_coords are", y_coords, "z_coords are", z_coords)
    axes.set_xlim3d(min(x_coords) * 0.95, max(x_coords) * 1.05)
    axes.set_ylim3d(min(y_coords) * 0.95, max(y_coords) * 1.05)
    axes.set_zlim3d(min(z_coords) * 0.95, max(z_coords) * 1.05)
    axes.quiver(x_starts, y_starts, z_starts, x_coords, y_coords, z_coords)
    plt.show()

v1 = [2,1,6]; v2 = [5, 4, 2]; origin = [0,0,0]
vector_list = [[1,3,4], [2,5,6], [-1,-4,-3]]; scalar_list = [3, -1, 2]
print("The length of v1 is", mymod.length(v1))
print("The dot product of v1 and v2 is", mymod.dot(v1, v2))
print("The angle between v1 and v2 in radians is", mymod.angle(v1, v2, 'r'))
print("The angle between v1 and v2 in degrees is", mymod.angle(v1, v2, 'd'))

print("The sum of two vectors\n")
graph_vectors(v1, v2, origin, mymod.sum)
print("The difference of two vectors\n")
graph_vectors(v1, v2, origin, mymod.diff)
print("Scaling one vector to a scalar\n")
graph_scaled(vector_list[0], scalar_list[0], origin)
print("Projecting one vector onto another\n")
graph_vectors(v1, v2, origin, mymod.proj)
print("The orthogonal component of one vector with respect to another\n")
graph_vectors(v1, v2, origin, mymod.perp)
print("The reflection of one vector across another\n")
graph_vectors(v1, v2, origin, mymod.refl)
print("The linear combination of the vectors and scalars")
graph_lincomb(vector_list, scalar_list, origin)
