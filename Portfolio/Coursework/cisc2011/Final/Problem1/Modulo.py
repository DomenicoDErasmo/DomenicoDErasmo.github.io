class Modulo:

    # Constructor
    # Initializes the modulus number of the modulo integer and the value, mapped to the modulo domain from the domain of reals    
    def __init__(self, new_mod, new_value):

        self.mod = new_mod
        self.value = new_value
        
        # Calculates self.value % self.mod without using the % operator
        if self.value < 0:
            while self.value <= -1 * self.mod:
                self.value += self.mod
        else:
            while self.value >= self.mod:
                self.value -= self.mod
    
    # Used for checking the validity of modulo operations
    def IsCompatabile(self, other_modulo):
        
        if self.mod != other_modulo.mod:
            print("Error: mods don't match.")
            return false
        else:
            return true
    
    # Adds the two modulo integers
    def __add__(self, adder):

        if self.IsCompatable(adder):
            return Modulo(self.mod, self.value + adder.value)

    # Negates a modulo integer
    def __negation__(self):

        return Modulo(self.mod, -self.value)

    # Subtracts a modulo integer from another
    def __sub__(self, subtractor):

        if self.IsCompatable(subtractor):
            return Modulo(self.mod, self.value - subtractor.value)

    # Multiplies one modulo integer by another
    def __mul__(self, multiplier):

        if self.IsCompatable(multiplier):
            return Modulo(self.mod, self.value * multiplier.value)

    # Converts the modulo integer to a string form, allowing it to be printed
    def __str__(self):

        return "{} % {}".format(self.value, self.mod)

    # Raises a modulo integer by a power
    # Precondition: self is an integer, exponent is a natural number
    def __pow__ (self, exponent):

        return Modulo(self.mod, self.value ** exponent.value)
    
    # Gives the multiplicative inverse of the modulo integer
    # Precondition: self.mod is prime
    def inverse(self):
        
        return Modulo(self.mod, self.value ** (self.mod - 2))
    
    # Multiplies one number by the multiplicative inverse of another number
    def __div__ (self, divisor):
        if self.IsCompatable(divisor):
            return self * divisor.inverse()

    # Prints the addition table for the modulo integer
    def atab(self):
        print("+", end = "")
        for col_head in range(self.mod):
            print(col_head, end = "")
        print()
        for row in range(self.mod):
            print(row, end="")
            for col in range(self.mod):
                cell_value = Modulo(self.mod, row + col)
                print(cell_value.value, end = "")
            print()
    
    # Prints the multiplication table for the modulo integer
    def mtab(self):
        print("*", end = "")
        for col_head in range(self.mod):
            print(col_head, end = "")
        print()
        for row in range(self.mod):
            print(row, end="")
            for col in range(self.mod):
                cell_value = Modulo(self.mod, row * col)
                print(cell_value.value, end = "")
            print()

