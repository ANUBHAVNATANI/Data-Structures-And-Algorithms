# dp way of printing fibonacii sequence
def fibo(n):
    # printing fibonacii series upto n numbers
    # initialize array
    A = [0, 1]  # previos values
    while len(A) < n + 1:
        A.append(0)
    if(n <= 1):
        return n
    else:
        if(A[n-1] == 0):
            A[n-1] = fibo(n-1)
            if(A[n-2] == 0):
                A[n-2] = fibo(n-2)
        A[n] = A[n-2]+A[n-1]
        return A[n]


if __name__ == "__main__":
    print(fibo(5))
