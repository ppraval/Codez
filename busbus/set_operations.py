import matplotlib.pyplot as plt
from matplotlib_venn import venn2

list1 = [1, 2, 3, 4, 5]
list2 = [4, 5, 6, 7, 8]

set1 = set(list1)
set2 = set(list2)

intersection = set1 & set2
union = set1 | set2
symmetric_difference = set1 ^ set2

print("Intersection:", intersection)
print("Union:", union)
print("Symmetric Difference:", symmetric_difference)

venn2([set1, set2], ('List 1', 'List 2'))
plt.show()
