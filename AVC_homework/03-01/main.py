import sys
import time
from extender import *

#----------------------------------------------
start_time = time.time()
if __name__ == '__main__':
    print('==> Start')
    container = Container()
    if len(sys.argv) != 5:
        print("Incorrect command line! You must write: python main <inputFileName> [<outputFileName>]")
        exit()
    if sys.argv[1] == "-f":
        inputFileName = sys.argv[2]
        # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
        ifile = open(inputFileName)
        str = ifile.read()
        ifile.close()
        # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
        strArray = str.replace("\n", " ").split(" ")
        figNum = ReadStrArray(container, strArray)
    elif sys.argv[1] == "-n":
        size = int(sys.argv[2])
        if size < 1 or size > 10000:
            print("Incorrect command line! You must write: python main <inputFileName> [<outputFileName>]")
            exit()
        container.rnd_cont(size)
    else:
        print("Incorrect command line! You must write: python main <inputFileName> [<outputFileName>]")
        exit()
    outputFileName = sys.argv[3]
    outputFileName2 = sys.argv[4]

    container.Print()

    ofile = open(outputFileName, 'w')
    ofile2 = open(outputFileName2, 'w')
    container.Write(ofile, ofile2)
    ofile.close()
    ofile2.close()

    print('==> Finish')

end_time = time.time()
total_time = end_time - start_time
print("time = ", total_time)