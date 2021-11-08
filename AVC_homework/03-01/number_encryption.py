from shape import *


# ----------------------------------------------
class numb_encryption(Shape):
    def __init__(self, is_rnd=False, numbers=[], text=[]):
        if is_rnd:
            self.numbers = numbers
            self.text = text
            self.en_text = [0] * len(self.text)
            for j in range(len(self.text)):
                if self.text[j] == self.numbers[0]:
                    self.en_text[j] = str(self.numbers[1])
                else:
                    self.en_text[j] = self.text[j]
        else:
            self.numbers = ['a', 'a']
            self.en_text = []
            self.text = []

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум три непрочитанных значения в массиве
        if i >= len(strArray) - 2:
            return 0
        self.numbers[0] = strArray[i]
        self.numbers[1] = strArray[i + 1]
        str = strArray[i + 2]
        self.text = list(str)
        self.en_text = [0] * len(self.text)
        i += 3
        # print("Triangle: a = ", self.a, " b = ", self.b, "c = ", self.c)
        for j in range(len(self.text)):
            if self.text[j] == self.numbers[0]:
                self.en_text[j] = self.numbers[1]
            else:
                self.en_text[j] = self.text[j]
        return i

    def Print(self):
        print("number encryption:text = ", ''.join(self.text), " encrypt text = ", ''.join(self.en_text), " numbers = ",
              self.numbers, ", Func result = ", str(self.quantiont()))
        pass

    def Write(self, ostream):
        ostream.write("number encryption: text = {}  encrypt text = {} numbers = {}, func result = {}".format \
                          (''.join(self.text), ''.join(self.en_text), self.numbers, str(self.quantiont())))
        pass

    def quantiont(self):
        a = 0
        b = 0
        for i in range(0, len(self.text)):
            a += ord(self.text[i])
            b += ord(self.en_text[i])
        return a / b
