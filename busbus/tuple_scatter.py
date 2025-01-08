import matplotlib.pyplot as plt

list = []

for i in range(1, 11):
    list.append((i, i ** 2))

x_values = [item[0] for item in list]
y_values = [item[1] for item in list]

plt.scatter(x_values, y_values)
plt.xlabel('X Values')
plt.ylabel('Y Values (Squared)')
plt.title('Scatter Plot of Numbers and Their Squares')
plt.show()
