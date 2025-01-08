from collections import Counter
import matplotlib.pyplot as plt

with open('temp/file.txt', 'r') as file:
    words = file.read().split()
    word_count = len(words)
    word_freq = Counter(words)

most_common_word = word_freq.most_common(1)[0]

print("Total number of words:", word_count)
print("Most frequent word:", most_common_word)

plt.bar(word_freq.keys(), word_freq.values())
plt.xlabel('Words')
plt.ylabel('Frequency')
plt.title('Word Frequency')
plt.show()
