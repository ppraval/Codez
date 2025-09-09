import re

text = "the 35 boxes"
result = re.sub(r'([0-9]+)', r'<\1>', text)
print(result)  # Output: the <35> boxes