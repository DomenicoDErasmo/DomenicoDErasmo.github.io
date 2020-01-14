# Question 1

import matplotlib.pyplot as plt

print("Plotting the initial curve and parallelogram from question 1:")
x = [interval/20.0 for interval in range (-40,21)]
y = []
x_quadrilateral = [-1.46506, -0.65016, 0.0, 0.0,-1.46506]
y_quadrilateral = [0, 1.14791, 1, 0,0]
for value in range(len(x)):
    y.append(x[value]**3 + x[value]**2 + 1)
plt.plot(x,y,'r')
quadrilateral = plt.plot(x_quadrilateral,y_quadrilateral,'b', linewidth=3.0)
plt.axhline(0, color = 'black')
plt.axvline(0, color = 'black')
plt.show()

# Question 2 - fix imaginary

import random
def Real(complexes):
    reals = []
    for index in range(len(complexes)):
       reals.append(complexes[index].real)
    return reals

def Imag(complexes):
    imaginarys = []
    for index in range(len(complexes)):
       imaginarys.append(complexes[index].imag)
    return imaginarys

print("Printing a list of real and imaginary components from question 2:")
complexes = []
imaginary_number = 0+1j
for index in range(20):
    complexes.append((random.randint(-50,50))+(random.randint(-50,50))*imaginary_number)
    reals = Real(complexes)
    imags = Imag(complexes)
print("Real \t\t Imaginary")
for index in range(20):
    print (reals[index], "\t\t", imags[index])

# Question 3

def GetBunnyCloudData():

    f    = open("bunny_cloud.dat", "r") # f is the object to open and read bunny_cloud.dat
    DATA = f.readlines()                # DATA is a list containing the lines of data in bunny_cloud.dat

    N    = len(DATA)                    # N is the number of lines in bunny_cloud.dat

    z = []                              # z is an empty list to be used later

    for s in DATA:                      # for every line s in DATA, do the following:

        ss = s.split()                  #   split each line s into a list of two numbers, using space as the delimiter
    
        a = float(ss[0])                #   the real component of the complex number is the first number in ss
        b = float(ss[1])                #   the imaginary component of the complex number is the second number in ss

        z.append( a + b*1j )            #   append the complex number formed by the current iteration of s to the list z
    
    return z                            # return the list of complex numbers

def GetHousePoints(bunny_numbers):
    
    house_numbers = []
    x_min = min(Real(bunny_numbers))-0.1; x_max = max(Real(bunny_numbers))+0.1
    y_min = min(Imag(bunny_numbers))-0.1; y_max = max(Imag(bunny_numbers))+0.1
    house_numbers.append(x_min + y_min * 1j); house_numbers.append(x_min + y_max * 1j); house_numbers.append(x_max + y_max * 1j); house_numbers.append(x_max + y_min * 1j); house_numbers.append(x_min + y_min * 1j)
    return house_numbers

def PlotFromNumbers(list_numbers, plot_format):
    
    x_coordinates = Real(list_numbers); y_coordinates = Imag(list_numbers)
    plt.plot(x_coordinates, y_coordinates, plot_format)

print("Plotting the initial bunny and house from question 3:")

bunny_numbers = GetBunnyCloudData()
PlotFromNumbers(bunny_numbers, "yo")
house_numbers = GetHousePoints(bunny_numbers)
PlotFromNumbers(house_numbers, "y")
plt.show()

# Question 4

import math

def Scale(complex_list, scalar):
    scalar_list = []
    for complex_number in complex_list:
        scalar_list.append(complex_number * scalar)
    return scalar_list

def Trans(complex_list, translation):
    translation_list = []
    for complex_number in complex_list:
        translation_list.append(complex_number + translation)
    return translation_list

def Conju(complex_list):
    conjugate_list = []
    for complex_number in complex_list:
        conjugate_list.append(complex_number - (2 * complex_number.imag * 1j))
    return conjugate_list

def Rotat(complex_list, angle):
    rotate_list = []
    rotate_number = math.cos(angle) + (math.sin(angle) * 1j)
    for complex_number in complex_list:
        rotate_list.append(complex_number * rotate_number)
    return rotate_list

# Question 5

print("Plotting a bunch of bunnies from question 5:")
PlotFromNumbers(bunny_numbers, "yo")
PlotFromNumbers(house_numbers, "y")
PlotFromNumbers(Scale(bunny_numbers, 3), "ro")
PlotFromNumbers(Scale(house_numbers, 3), "r")
PlotFromNumbers(Trans(bunny_numbers, 1-2j), "bo")
PlotFromNumbers(Trans(house_numbers, 1-2j), "b")
PlotFromNumbers(Conju(bunny_numbers), "go")
PlotFromNumbers(Conju(house_numbers), "g")
PlotFromNumbers(Rotat(bunny_numbers, (math.pi)*3/4), "ko")
PlotFromNumbers(Rotat(house_numbers, (math.pi)*3/4), "k")
plt.show()

# Question 6

print("Showing that rotate(transform) != transform(rotate) from question 6:")
PlotFromNumbers(bunny_numbers, "yo")
PlotFromNumbers(Rotat(Trans(bunny_numbers, 1-2j), (math.pi)*3/4), "ro")
PlotFromNumbers(Trans(Rotat(bunny_numbers, (math.pi)*3/4), 1-2j), "bo")
plt.show()

# Question 7

print("Extra credit from question 7:")
x = [-2, 5]
y = [-2*math.sqrt(3), 5*math.sqrt(3)]
plt.plot(x,y,'k')
PlotFromNumbers(bunny_numbers, "yo")
PlotFromNumbers(Rotat(Conju(Rotat(Trans(bunny_numbers, 4+0j), -(math.pi)/3)), (math.pi)/3), "bo")
plt.axhline(0, color = 'black')
plt.axvline(0, color = 'black')
plt.show()

