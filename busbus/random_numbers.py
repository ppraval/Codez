import random
import matplotlib.pyplot as plt

random_numbers = [random.randint(1, 50) for _ in range(100)]

with open('random_numbers.txt', 'w') as file:
    for number in random_numbers:
        file.write(f"{number}\n")

with open('random_numbers.txt', 'r') as file:
    numbers = [int(line.strip()) for line in file]
    mean_value = sum(numbers) / len(numbers)
    print("Mean of the numbers:", mean_value)

plt.hist(numbers, bins=range(1, 52), edgecolor='black')
plt.title('Distribution of Random Numbers')
plt.xlabel('Number')
plt.ylabel('Frequency')
plt.show()
