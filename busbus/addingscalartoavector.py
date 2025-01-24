import numpy as np

w = np.array([1, 2, 3, 4])

temp = []

for _ in range(10):
    temp.append(w)

temp = np.array(temp)

b = 2

gmr = np.array([1, 1, 1, 1])
print("My array is ", temp)
print("Dot")
print(temp.dot(gmr))
print("Dot + b")
print(temp.dot(gmr) + b)