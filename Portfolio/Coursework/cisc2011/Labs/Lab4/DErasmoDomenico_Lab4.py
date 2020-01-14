import math

class Vector:

    # Constructor
    def __init__ (self, input_dimensions, input_coordinates):

        # Made a copy to preserve all input variables for future use
        filtered_dimensions = input_dimensions
        filtered_coordinates = input_coordinates

        # Used in the definition of a SPARSE vector
        for key in list(input_coordinates):
            if filtered_coordinates[key] == 0:
                del filtered_coordinates[key]
                filtered_dimensions = filtered_dimensions - 1
        
        # Finally initializes the Vector
        self.dimensions = filtered_dimensions
        self.coordinates = filtered_coordinates

    # Addition Operator
    def __add__ (self, input_vector):

        # Error Checking
        if self.dimensions != input_vector.dimensions:
             print("Error: Inequal number of dimensions: {} != {}".format(self.dimensions, input_vector.dimensions))

        else:
            # Made a copy to preserve all input variables for future use
            new_dimensions = self.dimensions
            new_coordinates = {}
            
            # Initializing new_coorindates
            for key in self.coordinates:
                new_coordinates[key] = coordinates[key]
            
            # Addition
            for key in input_vector.coordinates:
                new_coordinates[key] += input_vector.coordinates[key]

            return Vector(new_dimensions, new_coordinates)

    # Negation Operator
    def __neg__ (self):
    
        # Made a copy to preserve all input variables for future use
        new_dimensions = self.dimensions
        new_coordinates = {}

        # Negation
        for key in self.coordinates:
            new_coorinates[key] = self.coordinates[key] * -1
    
        return Vector(new_dimensions, new_coordinates)

    # Subtraction Operator
    def __sub__ (self, input_vector):

        # Error Checking
        if self.dimensions != input_vector.dimensions:
             print("Error: Inequal number of dimensions: {} != {}".format(self.dimensions, input_vector.dimensions))

        else:
            # Made a copy to preserve all input variables for future use
            new_dimensions = self.dimensions
            new_coordinates = {}
           
            # Initialize new_coordinates
            for key in self.coordinates:
                new_coordinates[key] = coordinates[key]
            
            # Subtraction
            for key in input_vector.coordinates:
                new_coordinates[key] -= input_vector.coordinates[key]

            return Vector(new_dimensions, new_coordinates)

    # Multiplication Operator, works with scalars (returns vector) and vectors (returns scalar)
    def __mul__ (self, multiplier):

        # Checks for an int or a float
        if isinstance(multiplier, (int, float)):

            # Made a copy to preserve all input variables for future use
            new_dimensions = self.dimensions
            new_coordinates = self.coordinates

            # Multiplication
            for key in self.coordinates:
                new_coordinates[key] = self.coordinates[key] * multiplier

            return Vector(new_dimensions, new_coordinates)

        # Checks for a Vector
        elif isinstance(multiplier, Vector):

            dot_product = 0.0

            # Computes dot product
            for key in self.coordinates:
                if key in multiplier.coordinates:
                    dot_product += self.coordinates[key] * multiplier.coordinates[key]

            return dot_product

    # Reverse Multiplication Operator, works with scalars (returns vector) and vectors (returns scalar)
    def __rmul__ (self, multiplier):
        
        # Checks for an int or a float
        if isinstance(multiplier, (int, float)):

            # Made a copy to preserve all input variables for future use
            new_dimensions = self.dimensions
            new_coordinates = self.coordinates

            # Multiplication
            for key in self.coordinates:
                new_coordinates[key] = self.coordinates[key] * multiplier

            return Vector(new_dimensions, new_coordinates)

        # Checks for a Vector
        elif isinstance(multiplier, Vector):

            dot_product = 0.0

            # Compute dot product
            for key in self.coordinates:
                if key in multiplier.coordinates:
                    dot_product += self.coordinates[key] * multiplier.coordinates[key]

            return dot_product

    # Division Operator, divides the vector by a scalar
    def __truediv__ (self, scalar):

        # Made a copy to preserve all input variables for future use
        new_dimensions = self.dimensions
        new_coordinates = self.coordinates

        # Division
        for key in self.coordinates:
            new_coordinates[key] = self.coordinates[key] / scalar

        return Vector(new_dimensions, new_coordinates)
        
    # Mangitude Operation
    def norm (self):

        magnitude = 0.0
        
        # Squares each term
        for key in self.coordinates:
            magnitude += self.coordinates[key] ** 2

        return math.sqrt(magnitude)

    # Projection Operation
    def proj (self, input_vector):

        # Error Checking for Zero Vector
        if bool(input_vector.coordinates) == 0:
            print("Error: finding the projection of a zero vector!")

        # Formula
        else:
            return (((self * input_vector) / (input_vector.norm() ** 2)) * input_vector)

    # Allows the vector to be printed
    def __str__ (self):

        # Gives the dimensions the vector has a nonzero value in
        domain = ''.join(['\t{dim}'.format(dim = key) for key in self.coordinates])

        # Splits domain and values for visibility
        dash = "\n" + ("-" * (len(domain) + len(self.coordinates) * 8))

        # Gives the nonzero values of the vector
        values = ''.join(['\t{value}'.format(value = self.coordinates[key]) for key in self.coordinates])
        
        # Putting it all together
        return domain + dash + "\n" + values
