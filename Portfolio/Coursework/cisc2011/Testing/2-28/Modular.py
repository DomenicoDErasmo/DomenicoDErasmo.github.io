class Modular:
    
    def __init__(self, new_value):
    
        self.mod = 7
        self.value = new_value % self.mod

    def __add__(self, adder):

        return Modular(self.value + adder.value)

    def __negation__(self):

        return Modular(-self.value)

    def __sub__(self, subtractor):

        return Modular(self.value - subtractor.value)

    def __mul__(self, product):

        return Modular(self.value * product.value)

    def __str__(self):

        return '[%i]' % self.value

    # Precondition: self is an integer, exponent is a natural number
    def __pow__ (self, exponent):

        return Modular(self.value ** exponent.value)

    def Inverse(self):

        return Modular(self.value ** (self.mod-2)

    def __div__ (self, divisor):

        return self * Inverse(divisor)
