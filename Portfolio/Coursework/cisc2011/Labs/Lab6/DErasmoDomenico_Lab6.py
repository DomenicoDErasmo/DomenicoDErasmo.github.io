import numpy as np
import matplotlib.pyplot as plt
import matplotlib.collections as coll

class Projection:

    def __init__ (self):
        """
        Default constructor for Projection class
        """

    def SetFocus(self, input_focus):
        self.focus = np.ravel(input_focus)
    
    def SetDirection(self, input_direction):
        self.direction = np.ravel(input_direction)

    def SetParameter(self, input_parameter):
        self.parameter = input_parameter

    def SetHorizontal(self, input_horizontal):
        self.horizontal = np.ravel(input_horizontal)

    def Get3DCoordinates(self, point):
        """
        Finds the coordinates on the plane in 3D.
        """

        point_row = point.reshape(point.shape[0])
        plane_point = (((self.direction.dot(point_row) - self.parameter) * self.focus) + ((self.parameter - self.direction.dot(self.focus)) * point_row)) / self.direction.dot(point_row - self.focus)
        print(point,"'s projected coordinates in 3-space are", plane_point)
        return plane_point
        

    def ProjectSinglePoint(self, point):
        """
        Returns coordinates for the point on the plane. This requires using the horizontal and a perpendicular, coplanar vector as the axes and expressing the vector as a
            linear combination of those two vectors.
        """

        projected_point = np.ndarray(shape = (2,1))
        vertical = np.cross(self.horizontal, self.direction)
        vertical /= np.linalg.norm(vertical)
        
        projected_point[0,0] = point.dot(self.horizontal)
        projected_point[1,0] = point.dot(vertical)

        return projected_point

    def PerspectiveProjection(self, object_coordinates):
        """
        Calculate the projection for x, where x is a 3xN ndarray containing the coordinates 
            of the object in three-dimensional space. (N = 8 for 8 points, for example)
        Outputs projected_points, where projected_points is a 2xN ndarray, the Cartesian coordinates of the projection
            within the image plane.
        """

        plane_points = np.ndarray(shape = (3, object_coordinates.shape[1]));
        projected_points = np.ndarray(shape = (2, object_coordinates.shape[1]));
        
        for point_index in range(object_coordinates.shape[1]):
            plane_points[:, point_index] = self.Get3DCoordinates(object_coordinates[:, point_index])
            projected_points[:, point_index] = np.ravel(self.ProjectSinglePoint(plane_points[:, point_index]))

        return projected_points;


def InitializeFocus():
    """
    Initializes the camera hole position (3x1 ndarray)
    """
    
    focus = np.ndarray(shape = (3,1))
    for dim in range(focus.shape[0]):
        focus[dim, 0] = float(input("Enter the {}-coordinate for the camera hole: ".format(dim + 1)))
    return focus

def InitializeDirection():
    """
    Initializes the unit direction that the camera is viewing in (3x ndarray)
    """

    direction = np.ndarray(shape = (3,1))
    for dim in range(direction.shape[0]):
        direction[dim, 0] =  float(input("Enter the {}-coordiate for the direction: ".format(dim + 1)))
    direction /= np.linalg.norm(direction)
    return direction

def InitializeParameter():
    """
    Initializes the parameter that forms the perspective plane.
    """
 
    parameter = float(input("Enter the parameter for the plane: "))
    return parameter

def InitializeHorizontal():
    """
    Initializes the unit right-pointing horizontal.
    """
    horizontal = np.ndarray(shape = (3,1))
    for dim in range(horizontal.shape[0]):
        horizontal[dim, 0] =  float(input("Enter the {} -coordiate for the horizontal: ".format(dim + 1)))
    horizontal /= np.linalg.norm(horizontal)
    return horizontal
    
def InitializeProjection(camera):
    """
    Initializes the Projection object, calling the above functions to initialize the Projection object.
    """

    camera.SetFocus(InitializeFocus())
    camera.SetDirection(InitializeDirection())
    camera.SetParameter(InitializeParameter())
    camera.SetHorizontal(InitializeHorizontal())

def CreateCube():
    """
    Creates the cube used as the test subject in #4
    """

camera = Projection()

print("See the attached document for parameters that fulfil #2 of the lab")

InitializeProjection(camera)
object_coordinates = np.ndarray(shape = (3,1))
object_coordinates[:,0] = np.ravel(np.array([[0.5],[0.5],[2]]))

coordinate_matrix = Projection.PerspectiveProjection(camera, object_coordinates)
plt.plot(coordinate_matrix[0,:], coordinate_matrix[1,:], 'rx')
plt.show()

print("Now plotting a cube in 2D for Question #4")

def ConnectLines2D(coordinate_matrix, first_point, second_point):
    
    x1 = coordinate_matrix[0, first_point]
    x2 = coordinate_matrix[0, second_point]
    y1 = coordinate_matrix[1, first_point] 
    y2 = coordinate_matrix[1, second_point]
    plt.plot([x1, x2], [y1, y2], 'b-') 

def InitializeProjectedCube(coordinate_matrix):

    ConnectLines2D(coordinate_matrix, 0, 1)
    ConnectLines2D(coordinate_matrix, 0, 2)
    ConnectLines2D(coordinate_matrix, 0, 4)
    ConnectLines2D(coordinate_matrix, 1, 3)
    ConnectLines2D(coordinate_matrix, 1, 5)
    ConnectLines2D(coordinate_matrix, 2, 3)
    ConnectLines2D(coordinate_matrix, 2, 6)
    ConnectLines2D(coordinate_matrix, 3, 7)
    ConnectLines2D(coordinate_matrix, 4, 5)
    ConnectLines2D(coordinate_matrix, 4, 6)
    ConnectLines2D(coordinate_matrix, 5, 7)
    ConnectLines2D(coordinate_matrix, 6, 7)
    

cube_coordinates = np.array([[0.,0.,0.,0.,1.,1.,1.,1.],[0.,0.,1.,1.,0.,0.,1.,1.],[0.,1.,0.,1.,0.,1.,0.,1.]])

print("Case 1: camera faces parallel to the x-axis")
camera.SetFocus(np.array([4,.5,.5]))
camera.SetDirection(np.array([-1.,0.,0.]))
camera.SetParameter(-2)
camera.SetHorizontal(np.array([0.,1.,0.]))
coordinate_matrix = Projection.PerspectiveProjection(camera, cube_coordinates)

InitializeProjectedCube(coordinate_matrix)
plt.show()

print("Case 2: camera views from within the first octant")
camera.SetFocus(np.array([4,2,3]))
camera.SetDirection(np.array([-4.,-2.,-3.]))
camera.SetParameter(-9.5)
camera.SetHorizontal(np.array([-0.5,1.,0.]))
coordinate_matrix = Projection.PerspectiveProjection(camera, cube_coordinates)

InitializeProjectedCube(coordinate_matrix)
plt.show()

print("Case 3: camera hole at origin")
camera.SetFocus(np.array([0.,0.,0.]))
camera.SetDirection(np.array([1.,1.,1.]))
camera.SetParameter(-3)
camera.SetHorizontal(np.array([-1.,1.,0.]))
coordinate_matrix = Projection.PerspectiveProjection(camera, cube_coordinates)

InitializeProjectedCube(coordinate_matrix)
plt.show()

print("Now plotting a cube in 3D for Question #5")

from mpl_toolkits.mplot3d import Axes3D

def ConnectLines3D(coordinate_matrix, first_point, second_point):
    
    x1 = coordinate_matrix[0, first_point]
    x2 = coordinate_matrix[0, second_point]
    y1 = coordinate_matrix[1, first_point] 
    y2 = coordinate_matrix[1, second_point]
    z1 = coordinate_matrix[2, first_point]
    z2 = coordinate_matrix[2, second_point]
    plt.plot([x1, x2], [y1, y2], [z1, z2], 'b-') 

def InitializeCube(coordinate_matrix):

    ConnectLines3D(coordinate_matrix, 0, 1)
    ConnectLines3D(coordinate_matrix, 0, 2)
    ConnectLines3D(coordinate_matrix, 0, 4)
    ConnectLines3D(coordinate_matrix, 1, 3)
    ConnectLines3D(coordinate_matrix, 1, 5)
    ConnectLines3D(coordinate_matrix, 2, 3)
    ConnectLines3D(coordinate_matrix, 2, 6)
    ConnectLines3D(coordinate_matrix, 3, 7)
    ConnectLines3D(coordinate_matrix, 4, 5)
    ConnectLines3D(coordinate_matrix, 4, 6)
    ConnectLines3D(coordinate_matrix, 5, 7)
    ConnectLines3D(coordinate_matrix, 6, 7)

fig = plt.figure()
axes = fig.add_subplot(111, projection='3d')

InitializeCube(cube_coordinates)
plt.show()
