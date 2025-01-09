import random

def random_hex():
    return '#{:01x}'.format(random.randint(0, 0xF))

matrix = [[random_hex() for _ in range(3)] for _ in range(3)]

for row in matrix:
    print(row)

print("The numbers are: ")
list = [i for j in matrix for i in j]
print(list)
