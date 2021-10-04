#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// треугольник
struct CyclicEncryption {
    int n;
    string enText;
    string text;
};

// Ввод параметров треугольника из файла
void In(CyclicEncryption &t, ifstream &ifst);

// Случайный ввод параметров треугольника
void InRnd(CyclicEncryption &е);

// Вывод параметров треугольника в форматируемый поток
void Out(CyclicEncryption &t, ofstream &ofst);

// Вычисление периметра треугольника
double Encryption(CyclicEncryption &t);

#endif //__triangle__
