#!/usr/bin/python3
def print_reversed_list_integer(my_list=[]):
    my_list.reverse()
    for num in my_list:
        print("{:d}".format(num))
my_list = [1, 2, 3, 4, 5]
print_reversed_list_integer(my_list)
