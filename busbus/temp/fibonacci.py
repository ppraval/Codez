import matplotlib.pyplot as plt

def generate_fibonacci(n):
    fib_list = []
    a, b = 0, 1
    while len(fib_list) < n:
        fib_list.append(a)
        a, b = b, a + b
    return fib_list

fib_list = generate_fibonacci(5)
print(fib_list)
plt.plot(fib_list) 
plt.title('Fibonacci Sequence')
plt.xlabel('Index')
plt.ylabel('Fibonacci Number')
plt.show()
