dict1 = {
    'a': 1,
    'b': 2,
    'c': 3
}

dict2 = {
    'b': 3,
    'c': 4,
    'd': 5
}

merged_dict = dict1.copy()
for key, value in dict2.items():
    if key in merged_dict:
        merged_dict[key] += value
    else:
        merged_dict[key] = value

print("Merged Dictionary:", merged_dict)
