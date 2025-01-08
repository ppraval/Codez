import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('temp\data.csv')

sum_of_column = df['column_name'].sum()
print("Sum of the column:", sum_of_column)

plt.plot(df['column_name'])
plt.title('Line Plot of Column Data')
plt.xlabel('Index')
plt.ylabel('Values')
plt.show()
