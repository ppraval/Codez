import pandas as pd

data = {
    'column_name': [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
}

df = pd.DataFrame(data)

df.to_csv('data.csv', index=False)
