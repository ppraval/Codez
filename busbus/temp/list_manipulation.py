import statistics as st

list = [3, 5, 7, 9, 11, 13]

list[3] = 6
print(list)
list.remove(7)
print(list)
list.reverse()
print(list)
print("Mean = ", st.mean(list))
print("Median = ", st.median(list))