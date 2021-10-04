#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

// прямоугольник
struct ReplCharEncryption {
    char *symbols[2];
    string enText;
    string text;
};

// Ввод параметров прямоугольника из файла
void In(ReplCharEncryption &r, ifstream &ifst);

// Случайный ввод параметров прямоугольника
void InRnd(ReplCharEncryption &r);

// Вывод параметров прямоугольника в форматируемый поток
void Out(ReplCharEncryption &r, ofstream &ofst);

// Вычисление периметра прямоугольника
double Encryption(ReplCharEncryption &r);

#endif //__rectangle__
