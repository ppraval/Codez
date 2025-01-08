import matplotlib.pyplot as plt

def word_filtering_and_sorting(text):
    words = text.split()
    
    filtered_words = [word for word in words if len(word) >= 4]
    
    sorted_words = sorted(filtered_words)
    
    word_lengths = [len(word) for word in sorted_words]
    plt.bar(sorted_words, word_lengths)
    plt.title('Word Lengths')
    plt.xlabel('Words')
    plt.ylabel('Length')
    plt.xticks(rotation=90)
    plt.show()
    
    return sorted_words

text = "This is an example sentence for word filtering and sorting"
sorted_words = word_filtering_and_sorting(text)
print("Sorted Words:", sorted_words)
