str = input("Please enter a string: ").replace(" ", "").lower()
str2 = ''.join(reversed(str))
if str == str2:
    print("It is a palindrome")
else:
    print("It is not a palindrome")