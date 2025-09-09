import re

text ="apple5 banana6 cherry mango7 peach"
matches = re.findall(r"\w+(?=\d)", text)

print(matches)