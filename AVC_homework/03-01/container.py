from rnd import rnd_fig

#----------------------------------------------
class Container:
    def __init__(self):
        self.store = []

    #def ReadStrArray(self, strArray):

    def Print(self):
        print("Container is store", len(self.store), "shapes:")
        for shape in self.store:
            shape.Print()
        #print("sorted  = ", self.shell())
        pass

    def Write(self, ostream1, ostream2):
        ostream1.write("Container is store {} shapes:\n".format(len(self.store)))
        ostream2.write("Container is store {} shapes:\n".format(len(self.store)))
        for shape in self.store:
            shape.Write(ostream1)
            ostream1.write("\n")
        self.shell()
        for shape in self.store:
            shape.Write(ostream2)
            ostream2.write("\n")
        #ostream.write("Summa of func result  = {}\n".format(self.shell()))

    def rnd_cont(self, size):
        for i in range(size):
            self.store.append(rnd_fig())


    def shell(self):
        for s in range(len(self.store) // 2, 0, -1):
            for i in range(0, len(self.store)):
                for j in range(i + s, len(self.store)):
                    first = self.store[i].quantiont()
                    second = self.store[j].quantiont()
                    if first > second:
                        self.store[j], self.store[i] = self.store[i], self.store[j]
                    j += s - 1
            s //= 2 + 1


