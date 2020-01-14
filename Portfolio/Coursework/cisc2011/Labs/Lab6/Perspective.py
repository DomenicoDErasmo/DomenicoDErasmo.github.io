import numpy as np
import pyplot as plt

class Projection:

    def __init__ (self, focus, direction, parameter):
        self.focus = focus
        self.direction = direction
        self.parameter = parameter

    def ProjectionOntoPlane (self, point):
        return ((self.direction.dot(point) - self.parameter) * self.focus + (self.parameter - self.direction.dot(self.focus)) * point) / ((self.direction.dot(point - self.focus))

#TODO: FIX THIS
pa = np.array([0.0,0.0,0.0]); pb = np.array([0.0,0.0,1.0]); pc = np.array([0.0,1.0,0.0]); pd = np.array([0.0,1.0,1.0]) 
pe = np.array([1.0,0.0,0.0]); pf = np.array([1.0,0.0,1.0]); pg = np.array([1.0,1.0,0.0]); ph = np.array([1.0,1.0,1.0])

point_list = [pa, pb, pc, pd, pe, pf, pg, ph]

projected_point_list = []

Projection A(np.array([6.0,4.0,5.0]), np.array([2.0, 3.0, 2.0]), parameter = 10

for point in point_list:
    projected_point_list.append(A.ProjectionOntoPlane(point))

plt.graph(projected_point_list)
plt.show()
