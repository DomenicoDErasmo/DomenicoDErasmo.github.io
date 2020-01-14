def fibonacci_print(last_term):
    first, second = 0,1
    while second < last_term:
        print(second)
        first, second = second, first + second

def fibonacci_list(last_term):
    result = []
    first, second = 0, 1
    while second < last_term:
        result.append(second)
        first, second = second, first+second
    return result

def main():
    fibonacci_print(10)
    print(fibonacci_list(10))

if __name__ == "__main__":
    main()
