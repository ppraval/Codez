import array as arr

# Arrays vs Lists
a = arr.array('i', [1, 2, 3, 4, 5, 6, 7])  # This is type-specific
b = [1, 2, "Pain"]
c = [a, b]

for sublist in c:
    for item in sublist:
        print(item, end=' ')
    print()  # Just for a newline at the end
