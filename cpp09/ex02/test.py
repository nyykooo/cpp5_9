#!/usr/bin/env python3
import random
import subprocess

# Configuration
num_numbers = 1000      # number of numbers to generate
min_value = 0         # minimum value
max_value = 200    # maximum value
executable = "./PmergeMe"  # path to your compiled executable

# Generate random numbers
numbers = [str(random.randint(min_value, max_value)) for _ in range(num_numbers)]

# Join numbers into a single string argument
numbers_arg = " ".join(numbers)

# Build the command
cmd = [executable, numbers_arg]

# Execute the program
try:
    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    print("Program output:\n")
    print(result.stdout)
except subprocess.CalledProcessError as e:
    print("Program failed with return code", e.returncode)
    print("Error output:\n", e.stderr)