import random
from symb_encryption import *
from number_encryption import *
from cyclic_encryption import *

def rnd_text():
    str = ""
    symbols = "abcdefghijklmnopqrstuvwxyz"
    for i in range(10):
        str += symbols[random.randint(0, 25)]
    return str


def rnd_int():
    return random.randint(1, 9)


def rnd_char():
    symbols = "abcdefghijklmnopqrstuvwxyz"
    return symbols[random.randint(0, 25)]

def rnd_fig():
    k = random.randint(1, 3)
    if k == 1:
        symbols = [rnd_char(), rnd_char()]
        text = rnd_text()
        return SymbEncryption(True, symbols, text)
    if k == 2:
        numbers = [rnd_char(), rnd_int()]
        text = rnd_text()
        return numb_encryption(True, numbers, text)
    if k == 3:
        text = rnd_text()
        n = rnd_int()
        return Cyclic_encryption(True, n, text)