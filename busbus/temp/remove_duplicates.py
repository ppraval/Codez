import statistics as st

input_list = input("Give me a list of numbers: ").split(" ")
num_list = [int(i) for i in input_list]

unique_list = []
seen = set()
for num in num_list:
    if num not in seen:
        unique_list.append(num)
        seen.add(num)

print("Unique elements:", unique_list)

mean_unique = st.mean(unique_list)
median_unique = st.median(unique_list)

print("Mean of unique elements:", mean_unique)
print("Median of unique elements:", median_unique)