from shape import *


# ----------------------------------------------
class Cyclic_encryption(Shape):
    def __init__(self, is_rnd=False, n=0, text=[]):
        if is_rnd:
            self.text = text
            self.n = n
            self.en_text = [0] * len(self.text)
            for j in range(len(self.text)):
                self.en_text[j] = self.text[(j + self.n) % len(self.text)]
        else:
            self.text = []
            self.n = 0
            self.en_text = []

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум два непрочитанных значения в массиве
        if i >= len(strArray) - 1:
            return 0
        self.n = int(strArray[i])
        str = strArray[i + 1]
        self.text = list(str)
        self.en_text = [0] * len(self.text)
        i += 2
        # print("Rectangle: x = ", self.x, " y = ", self.y)
        for j in range(len(self.text)):
            self.en_text[j] = self.text[(j + self.n) % len(self.text)]
        return i

    def Print(self):
        print("cyclic encryption: text = ", ''.join(self.text), " encrypt text = ", ''.join(self.en_text), "n = ",
              self.n,
              ", func result = ", self.quantiont())
        pass

    def Write(self, ostream):
        ostream.write(
            "cyclic encryption:   text = {} encrypt text = {} n = {}, func result = {}".format(''.join(self.text),
                                                                                               ''.join(self.en_text),
                                                                                               self.n,
                                                                                               self.quantiont()))
        pass

    def quantiont(self):
        return 1.0
