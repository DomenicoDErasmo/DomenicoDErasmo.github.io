import GaussianElimination as test
import numpy

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
