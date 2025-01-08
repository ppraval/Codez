def sort_list_of_dicts(list_of_dicts, key):
    return sorted(list_of_dicts, key=lambda x: x[key])

people = [
    {"name": "Alice", "age": 25},
    {"name": "Bob", "age": 22},
    {"name": "Charlie", "age": 30}
]

sorted_people = sort_list_of_dicts(people, 'age')
print(sorted_people)
