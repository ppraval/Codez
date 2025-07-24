import random

def flip_unfair_coin(unknown_bias):
    return 1 if random.random() < unknown_bias else 0

# function that generates a fair flip
# returns either 1 or 0
def generate_fair_bit(unknown_bias = 0.7):
    return  flip_unfair_coin(0.5)

print(generate_fair_bit())  # Example usage