import numpy
import time

# Takes an upper triangular matrix U and a solution vector b, returning the solution
def BackSub(U, b):
    
    # Initialization
    x = numpy.zeros((b.size, 1), dtype=float)

    for row_index in range(b.size - 1,-1,-1):
        x[row_index] = b[row_index]
        for col_index in range(row_index + 1, b.size, 1):
            x[row_index] = x[row_index] - U[row_index][col_index] * x[col_index]
        x[row_index] = x[row_index] / U[row_index][row_index]
        
    return x

# This works but I have no need to implement it because the below function doesn't work.
def GetColumnMax(matrix, column):
    max_index = 0 
    for index in range(matrix.shape[0]):
        if numpy.absolute(matrix[index][column]) > numpy.absolute(matrix[max_index][column]):
            max_index = index
    return max_index

# This doesn't work sadly. I had a fever while deciding to procrastinate so I'll take the L on this one. Sorry Prof.
def PivotRows(matrix, row_a, row_b):
    if row_a != row_b:
        dummy = matrix
        matrix[row_a] = matrix[row_b]
        matrix[row_b] = dummy[row_a]

# Takes an mxn matrix A and a nx1 solution vector b, returning the augmented matrix [A|b]
def GetEchelonForm(A, b):

    # Initialization
    U = A
    weight = numpy.zeros((A.shape[0], A.shape[0]))
    augmentedMatrix = numpy.zeros((A.shape[0], A.shape[0] + 1))

    for col_index in range(U.shape[0] - 2):
        for row_index in range(col_index + 1, U.shape[0] - 1):
            weight[row_index][col_index] = U[row_index][col_index] / U[col_index][col_index]
            for position in range(col_index + 1, U.shape[0] - 1):
                U[row_index][position] = U[row_index][position] - weight[row_index][col_index] * U[col_index][position]
            b[[row_index]] = b[[row_index]] - weight[row_index][col_index] * b[[col_index]]
    
    # Initializes the augmented matrix
    augmentedMatrix = numpy.column_stack((U,b))
    print(augmentedMatrix)

    return augmentedMatrix


# Takes an mxn matrix A and a nx1 solution vector b, returning the augmented matrix [A|b]
def GetEchelonForms(A, b):

    # Initialization
    U = A
    augmentedMatrix = numpy.zeros((A.shape[0], A.shape[0] + 1))

    for col_index in range(U.shape[0]):
        
        for row_index in range(col_index + 1, U.shape[0]):
            
            # Initialization for convenience
            front_entry = float(U[col_index][col_index])

            # Used to make sure the right row operation is used, sets the sign of the weight
            sign = lambda front_entry: (front_entry > 0) - (front_entry < 0)

            # The row operations themselves
            weight = (sign(front_entry) * U[row_index][col_index]/numpy.absolute(front_entry))
            U[row_index,:] = U[row_index,:] - weight * U[col_index,:]
            b[row_index] = b[row_index] - weight * b[col_index]
    
    # Initializes the augmented matrix
    print("U:",U.shape[0],"x",U.shape[1])
    print("b:",b.shape)
    augmentedMatrix = numpy.column_stack((U,b))

    return augmentedMatrix

# Reads the file from which the A matrix is recorded.
def ParseMatrixAFile(options):
    
    # Initialization
    A = numpy.zeros((0),dtype=float)
    filename = options[8:]

    # File reading
    with open("%s.txt" % filename, "r") as file:
        for line_number, line in enumerate(file,1):
            A.resize(line_number)
            A[line_number-1] = line

    # Matrix resizing
    A_bounds = int(numpy.sqrt(line_number))
    A = numpy.reshape(A, (A_bounds, A_bounds))
    
    return A

# Reads the file from which the b matrix is recorded.
def ParseMatrixBFile(options):

    # Initialize b
    b = numpy.zeros((0),dtype=float)
    filename = options[8:]
    
    # File reading
    with open("%s.txt" % filename, "r") as file:
        for line_number, line in enumerate(file,1):
            b.resize(line_number)
            b[line_number-1] = line
    return b

# Solves a linear system, given by an mxn matrix A and an nx1 solution vector b.
def Solve(A, b, options):
    """A is an mxn matrix. b is an nx1 vector.
       options can take a few keywords:
            'timing' - prints the time taken to finish elimination
            'Afile = filename.txt' - initializes A from the given file
            'bfile = filename.txt' - initializes b from the given file
            'xfile = filename.txt' - writes the solution to the given file
            'absolute' - prints the magnitude of the residual, r = b - Ax
            'relative' - prints the relative error |r|/|b|, or norm(r) / norm(b)"""

    # Due to the limitations of the current implementation, one must set a dummy matrix for the matrix that gets read from a file.
    if "Afile = " in options:
        A = ParseMatrixAFile(options)
    elif "bfile = " in options:
        b = ParseMatrixBFile(options)
            
    tA = time.perf_counter()

    # Used for timing row reduction
    t0 = time.perf_counter()
    augmentedMatrix = GetEchelonForm(A, b)
    t1 = time.perf_counter() - t0
   
    # Divides [A|b] back into A and b 
    upperTriangular = augmentedMatrix[:,:-1]
    solutions = augmentedMatrix[:,augmentedMatrix.shape[1] - 1]
    
    print("augmentedMatrix:")
    print(augmentedMatrix)
    print("upperTriangular:")
    print(upperTriangular)
    print("solutions:")
    print(solutions)

    # Used for timing backwards substitution
    t0 = time.perf_counter()
    x = BackSub(upperTriangular, solutions)
    t2 = time.perf_counter() - t0
    
    tB = time.perf_counter() - tA
    
    # Finds the absolute/relative residual
    if options == "absolute" or options == "relative":
        residual = numpy.zeros((b.shape), dtype = float)
        dotted = A@x
        for position in range(b.shape[0]):
            residual[position] = b[position] - dotted[position]
        if options == "relative":
            relative_residual = numpy.linalg.norm(residual)/numpy.linalg.norm(dotted)
            print("The relative residual was", relative_residual)
        else:
            print("The residual was", residual)

    if options == "timing":
        print("GetEchelonForm took",t1,"time to solve a",upperTriangular.shape[0],"by",upperTriangular.shape[1],"upper triangular matrix.")
        print("BackSub took",t2,"time to reduce a",upperTriangular.shape[0],"by",upperTriangular.shape[1],"matrix to echelon form.")
        print("The Solve function ran for", tB, "time.")
    
    # Used to print solutions to another file
    if "xfile = " in options:
        filename = options[8:]
        with open('%s.txt' % filename, 'w') as file:
            for line_number in range(solutions.shape[0]):
                file.write(str(x[line_number]) + "\n")
    else:
        print("Answer:")
        return x
