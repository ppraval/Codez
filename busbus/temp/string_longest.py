import matplotlib.pyplot as plt

def string_operations(strings_list):
    longest_string = max(strings_list, key=len)
    
    vowels = 'aeiouAEIOU'
    count_vowels = sum(1 for string in strings_list if string[0] in vowels)
    
    lengths = [len(string) for string in strings_list]
    plt.hist(lengths, bins=range(min(lengths), max(lengths) + 1, 1))
    plt.title('Distribution of String Lengths')
    plt.xlabel('String Length')
    plt.ylabel('Frequency')
    plt.show()
    
    return longest_string, count_vowels

strings_list = ['apple', 'banana', 'cherry', 'date', 'elderberry', 'fig']
longest_string, count_vowels_start = string_operations(strings_list)
print("Longest String:", longest_string)
print("Strings starting with a vowel:", count_vowels_start)
