import matplotlib.pyplot as plt

str = input("Give me an input string: ").lower()
print(str)

freq = {}
for i in str:
    freq.setdefault(i, 0)
    freq[i] += 1
print(freq)

plt.bar(freq.keys(), freq.values(), color='skyblue')
plt.xlabel('Characters')
plt.ylabel('Frequency')
plt.title('Character Frequency in Input String')
plt.show()