#!/usr/bin/python3
def uppercase(str):
    spam = str
    new = ""
    for ch in spam:
        n = ord(ch)
        if (n >= 97 and n <= 122):
            ch = chr((n - 32))
            new = new + ch
        else:
            new = new + ch
    print("{}".format(new))
