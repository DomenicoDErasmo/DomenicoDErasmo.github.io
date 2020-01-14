import numpy as np

# U is an nxn upper triangular matrix, b is an nx1 solution vector
# Returns a solution vector p
# Preconditions: U must be a square matrix, no diagonals can equal 0
def BackSolve(U, b):
    size = b.size
    for row_index in range (size - 1, -1, -1):
        sum = 0
        for col_index in range (row_index + 1, size, 1):
            sum += U[row_index, col_index] * b[col_index]
        b[row_index] = (b[row_index] - sum) / U[row_index, row_index]
    return b

# Chooses the largest row from row j downward and swaps it with j
def FindSwapRow(U, j):
    compare_row = np.absolute(U[j,j])
    swap_row = j
    for row in range(j, U.shape[0]):
        if np.absolute(U[row, j]) > compare_row:
            compare_row = np.absolute(U[row, j])
            swap_row = row
    
    #print("The row to swap row " + str(j) + " with is row " + str(swap_row))
    return swap_row    

# A is an nxn matrix, b is an nx1 solution vector
# Returns [U,p], an augmented matrix with U as an upper triangular matrix of A and p as the new solution vector
def MakeUpperTriangular(A, b):
    U = A
    p = b
    for i in range (U.shape[0]):
        for j in range(i + 1, p.shape[0]):
            swap = FindSwapRow(U, j)
            U[[j, swap]] = U[[swap, j]]
            p[[j, swap]] = p[[swap, j]]
            weight = U[j,i] / U[i,i]
            U[j,:] = U[j,:] - weight * U[i,:]
            p[j] = p[j] - weight * p[i]
    U = np.column_stack((U,p))
    return U 

# A is an nxn matrix, b is an nx1 solution vector
# Returns a solution vector p
def GaussianElimination(A, b):
    U = MakeUpperTriangular(A,b)
    p = BackSolve(U[:,:-1], U[:,U.shape[1] - 1])
    return p
