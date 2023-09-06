#!/usr/bin/python3
import random
number = random.randint(-10000, 10000)
rem = number % 10
if (number < 0):
    rem = (number * -1) % 10
    rem = rem * -1
print(f"Last digit of {number} is {rem}", end=" ")
if ((rem < 6) and (rem != 0)):
    print("and is less than 6 and not 0")
elif (rem > 5):
    print("and is greater than 5")
else:
    print("and is 0")
