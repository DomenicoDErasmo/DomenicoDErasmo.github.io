import GaussianElimination as test
import numpy

# Initialize dummy A
A = numpy.zeros((0),dtype=float)
with open("C.txt") as file:
    for line_number, line in enumerate(file,1):
        A.resize(line_number)
        A[line_number-1] = line
A_bounds = int(numpy.sqrt(line_number))
A = numpy.reshape(A, (A_bounds, A_bounds))

# Initialize b
b = numpy.zeros((0),dtype=float)
#with open("b.txt") as file:
#    for line_number, line in enumerate(file,1):
#        b.resize(line_number)
#        b[line_number-1] = line

# Initialize F
#F = numpy.array([[-4.0,9.0,12.0],[0.0,5.25,1.0],[0.0,0.0,2.45098039216]])
F = numpy.array([[-4.0,9.0,12.0],[1.0,5.25,1.0],[0.0,0.0,2.45098039216]])

# Initialize e
#e = numpy.array([[12.0],[10.0],[-2.47619047619]])
e = numpy.array([[12.0],[8.68783673469],[-2.47619047619]])

#print(test.BackSub(F,e))
print(test.Solve(F,e,"timing"))
#print(test.Solve(A,b,"bfile = d"))
