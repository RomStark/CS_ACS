from shape import *


# ----------------------------------------------
class SymbEncryption(Shape):
    def __init__(self, is_rnd=False, symbols=[], text=[]):
        if is_rnd:
            self.symbols = symbols
            self.text = text
            self.en_text = [0] * len(self.text)
            for j in range(len(self.text)):
                if self.text[j] == self.symbols[0]:
                    self.en_text[j] = self.symbols[1]
                else:
                    self.en_text[j] = self.text[j]
        else:
            self.symbols = ['a', 'a']
            self.en_text = []
            self.text = []

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум три непрочитанных значения в массиве
        if i >= len(strArray) - 2:
            return 0
        self.symbols[0] = strArray[i]
        self.symbols[1] = strArray[i + 1]
        str = strArray[i + 2]
        self.text = list(str)
        self.en_text = [0] * len(self.text)
        i += 3
        # print("Triangle: a = ", self.a, " b = ", self.b, "c = ", self.c)
        for j in range(len(self.text)):
            if self.text[j] == self.symbols[0]:
                self.en_text[j] = self.symbols[1]
            else:
                self.en_text[j] = self.text[j]
        return i

    def Print(self):
        print("character encryption: text = ", ''.join(self.text), " encrypt text = ", ''.join(self.en_text),
              " symbols = ", self.symbols,
              ", Func result = ",
              self.quantiont())
        pass

    def Write(self, ostream):
        ostream.write("character encryption: text = {}  encrypt text = {} symbols = {}, func result = {}".format \
                          (''.join(self.text), ''.join(self.en_text), self.symbols, self.quantiont()))
        pass

    def quantiont(self):
        a = 0
        b = 0
        for i in range(0, len(self.text)):
            a += ord(self.text[i])
            b += ord(self.en_text[i])
        return a / b
