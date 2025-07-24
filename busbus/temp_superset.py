def product_except_self(nums):
    n = len(nums)
    output = [1] * n

    prefix = 1
    for i in range(n):
        output[i] = prefix
        prefix *= nums[i]

    suffix = 1
    for i in reversed(range(n)):
        output[i] *= suffix
        suffix *= nums[i]

    return output

input_str = input("Enter comma-separated numbers: ")
nums = list(map(int, input_str.split(',')))
result = product_except_self(nums)

print("Output:",", ".join(map(str, result)))