list = [2,4,6,1,5]
squared_list = [x**2 for x in list]
print(squared_list)
squared_dict = {x:x**2 for x in list}
another_squared_dict = {x:y for x, y in zip(squared_list, squared_dict)}
print(squared_dict)
print(another_squared_dict)

conditional_list = [x for x in squared_list if x % 2 == 0]
print(conditional_list)

my_list = [[10,20,30],[40,50,60],[70,80,90]]

flattened_list = [x for temp in my_list for x in temp ]
print("Flat list = ", end='')
print(flattened_list)