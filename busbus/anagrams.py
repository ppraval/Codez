def find_anagrams(word, words_list):
    sorted_word = sorted(word)
    anagrams = [w for w in words_list if sorted(w) == sorted_word]
    return anagrams

word = "listen"
words_list = ["enlist", "google", "inlets", "banana"]
anagrams = find_anagrams(word, words_list)
print("Anagrams of '{}': {}".format(word, anagrams))
