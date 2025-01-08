import statistics as st

list = []
for i in range(1, 21):
    list.append(i)
print("list = ", list)

sum = 0
for i in list:
    sum += i
print("sum = ", sum)

odd_product = 1
for i in list:
    if i % 2 == 1:
        odd_product *= i
print("Product of all odd numbers is = ", odd_product)

print("Mean = ", sum / len(list))
print("Median = ", st.median(list))
print("Standard Deviation = ", st.stdev(list))