numbers = [1, 2, 3, 4, 5]

with open('numbers.txt', 'w') as file:
    for number in numbers:
        file.write(f"{number}\n")

with open('numbers.txt', 'r') as file:
    read_numbers = [int(line.strip()) for line in file]
    print("Numbers in file: ", read_numbers)
    print("sum of numbers in file:", sum(read_numbers))
