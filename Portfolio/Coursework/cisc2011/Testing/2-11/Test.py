from math import pow

def arithmetic_mean(variable_arguments, mean_type):
    mean_sum = 0
    size = len(varibale_arguments)
    for a in variable_arguments:
        mean_sum += pow(a, mean_type) 
    arithmetic_mean = pow(mean_sum/size, 1/mean_type)
    return arithmetic_mean

def geometric_mean(variable_arguments):
    product = 1
    size = len(variable_arguments)
    for a in variable_arguments:
        product *= a
    geometric_mean = pow(product, 1/len(size)
    return geometric_mean

def my_mean(*variable_arguments, **keyword_arguments):
    #prototype
    #my_mean (a1, a2, ..., an, P = 'p')
    #if type is a non-zero number, p-mean
    #if type is zero, geometric mean
    #check that all a, ..., an are a number type
    #check that type is actually a number
    product = 0.0
    mean_type = keyword_arguments['P']
    if mean_type == 0:
        product = geometric_mean(variable_arguments)
    elif mean_type != 0:
        product = arithmetic_mean(variable_arguments, mean_type)
