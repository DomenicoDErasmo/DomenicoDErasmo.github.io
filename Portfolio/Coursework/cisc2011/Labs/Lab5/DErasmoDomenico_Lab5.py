import numpy
import time
import GaussianElimination as test

# Testing bfile
A = numpy.array([[-4.0,9.0,12.0],[1.0,3.0,-2.0],[2.0,1.0,1.0]])
b = numpy.zeros((1,1),dtype=float)
print(test.Solve(A,b,"bfile = d"))

# Testing Afile
A = numpy.zeros((1,1),dtype=float)
b = numpy.array([[12.0],[7.0],[2.0]])
print(test.Solve(A,b,"Afile = C"))

# Testing xfile
A = numpy.array([[-4.0,9.0,12.0],[1.0,3.0,-2.0],[2.0,1.0,1.0]])
b = numpy.array([[12.0],[7.0],[2.0]])
print(test.Solve(A,b,"xfile = x"))

# Testing the master list
# Initialize A
A = numpy.zeros((0),dtype=float)
with open("A.txt") as file:
    for line_number, line in enumerate(file,1):
        A.resize(line_number)
        A[line_number-1] = line
A_bounds = int(numpy.sqrt(line_number))
A = numpy.reshape(A, (A_bounds, A_bounds))

# Initialize b
b = numpy.zeros((100),dtype=float)
with open("b.txt") as file:
    for line_number, line in enumerate(file,1):
        b.resize(line_number)
        b[line_number-1] = line
print(test.Solve(A,b, "timing"))

