import math

def sum(x, y):

    """Returns the sum of the two given vectors x and y. x and y are lists of floats of the same length that represent two vectors."""

    summation = []
    for position in range(len(x)):
        summation.append(0.0)
        summation[position] = x[position] + y[position]
    return summation

def diff(x, y):

    """Returns the difference of the two given vectors x and y. x and y are lists of floats of the same length that represent two vectors."""

    difference = []
    for position in range(len(x)):
        difference.append(0.0)
        difference[position] = x[position] - y[position]
    return difference

def scale (x, scalar):

    """Returns the vector x multiplied by scalar. x is a list of floats that represents a vector. scalar is a float."""

    scaled_x = []
    for position in range(len(x)):
        scaled_x.append(0.0)
        scaled_x[position] = x[position] * scalar
    return scaled_x

def lincomb(x_vector_list, scalar_list):

    """Returns the linear combination of scalar_list and x_vector_list. This is expressed as scalar_list[0] * x_vector_list[0] + scalar_list[1] * x_vector_list[1] + ... scalar_list[n] * x_vector_list[n]. x_vector_list is a list of lists of floats, with each list of floats representing a vector. scalar_list is a list of floats. x_vector_list and scalar_list have the same number of elements."""

    linear_combination = [0,0,0]
    for position in range(len(x_vector_list)):
        linear_combination = sum(linear_combination, scale(x_vector_list[position], scalar_list[position]))
    return linear_combination

def length(x):

    """Returns the length of vector x. x is a list of floats of equal length that represents a vector."""

    length_squared = 0
    for position in range(len(x)):
        length_squared += x[position]**2
    return math.sqrt(length_squared)
    
def dot(x, y):

    """Finds the dot product of vectors x and y. x and y are lists of floats of equal length that represent two vectors."""

    dot_product = 0
    for position in range(len(x)):
        dot_product += x[position] * y[position]
    return dot_product

def proj(x, y):

    """Finds the projection of vector x onto vector y. x and y are lists of floats of equal length that represent two vectors."""

    return scale(y, dot(x,y)/(length(y)**2))

def perp(x, y):

    """Finds the perpendicular part of vector x to vector y. x and y are lists of floats of equal length that represent two vectors."""

    return diff(x, proj(x, y))

def refl(x, y):

    """Finds the reflection of vector x across vector y. x and y are lists of floats of equal length that represent two vectors."""

    return diff(x, scale(proj(x,y), 2))

def arccos(x):

    """Finds the inverse cosine of angle x. x is a float between -1 and 1. This is implemented as per the extra credit."""

    angle = 0
    for term in range(10):
            # taylor series expansion of arccos(x), carried out to ten terms for high precision
            angle += (math.factorial(2 * term) * x ** (2 * term + 1)) / ((2 ** (2 * term)) * math.factorial(term) ** 2 * (2 * term + 1))
    return (math.pi / 2) - angle

def angle(x,y,s='r'):

    """Finds the angle between vectors x and y. x and y are lists of floats of equal lengths that represent two vectors. s is an option to output the angle in radians using 'r' or degrees using 'd'. This answer is expressed in radians by default."""

    # uses dot product (x,y) / length(x) * length (y)
    if s == 'r':
        return math.acos(dot(x,y) / (length(x) * length(y)))
    elif s == 'd':
        return (arccos(dot(x,y) / (length(x) * length(y))) * 180 / math.pi)

#12/10
#excellent work
#color would aid distringuishing vectors in figures
#+2 extra credit
