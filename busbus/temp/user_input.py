import statistics as st
import matplotlib.pyplot as plt

input_list = (input("Please enter a comma separated list: ")).split(", ")
list = [int(i) for i in input_list]
print(list)

print("Mean = ", st.mean(list))
print("Median = ", st.median(list))

print("Max = ", max(list))
print("Min = ", min(list))

plt.hist(list, bins=10, edgecolor='black') 
plt.title('Histogram') 
plt.xlabel('Values') 
plt.ylabel('Frequency') 
plt.show()