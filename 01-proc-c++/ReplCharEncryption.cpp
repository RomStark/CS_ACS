//------------------------------------------------------------------------------
// rectangle_In.cpp - содержит процедуру ввода параметров 
// для уже созданного прямоугольника
//------------------------------------------------------------------------------

#include "ReplCharEncryption.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(ReplCharEncryption &r, ifstream &ifst) {
    ifst >> r.symbols[0] >> r.symbols[1] >> r.text;
}

// Случайный ввод параметров прямоугольника
void InRnd(ReplCharEncryption &r) {
    //r.symbols = Random_2();
    r.text = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(ReplCharEncryption &r, ofstream &ofst) {
    ofst << "It is ReplCharEncryption: x = " << r.symbols << ", y = " << r.text
         << ". function = " << Encryption(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Encryption(ReplCharEncryption &r) {
    for (int i = 0; i < r.text.size(); i++) {
        if (r.text[i] == *r.symbols[0]) {
            r.enText[i] = *r.symbols[1];
        }
    }

    int k = 0;
    int d = 0;
    for (int i = 0; i < r.text.size(); i++) {
        k += int(r.text[i]);
        d += int(r.enText[i]);
    }
    return k / d;
}
