//------------------------------------------------------------------------------
// encryption.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "encryption.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
encryption* In(ifstream &ifst) {
    encryption *sp;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sp = new encryption;
            sp->k = encryption::REPLCHARENCRYPTION;
            In(sp->r, ifst);
            return sp;
        case 2:
            sp = new encryption;
            sp->k = encryption::CYCLICENCRYPTION;
            In(sp->t, ifst);
            return sp;
        case 3:
            sp = new encryption;
            sp->k = encryption::NUMBENCRYPTION;
            In(sp->t, ifst);
            return sp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
encryption *InRnd() {
    encryption *sp;
    auto k = rand() % 2 + 1;
    switch(k) {
        case 1:
            sp = new encryption;
            sp->k = encryption::REPLCHARENCRYPTION;
            InRnd(sp->r);
            return sp;
        case 2:
            sp = new encryption;
            sp->k = encryption::CYCLICENCRYPTION;
            InRnd(sp->t);
            return sp;
        case 3:
            sp = new encryption;
            sp->k = encryption::NUMBENCRYPTION;
            InRnd(sp->t);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(encryption &s, ofstream &ofst) {
    switch(s.k) {
        case encryption::CYCLICENCRYPTION:
            Out(s.t, ofst);
            break;
        case encryption::REPLCHARENCRYPTION:
            Out(s.r, ofst);
            break;
        case encryption::NUMBENCRYPTION:
            Out(s.n, ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double Perimeter(encryption &s) {
    switch(s.k) {
        case encryption::CYCLICENCRYPTION:
            return Encryption(s.r);
            break;
        case encryption::REPLCHARENCRYPTION:
            return Encryption(s.t);
            break;
        case encryption::NUMBENCRYPTION:
            return Encryption(s.t);
            break;
        default:
            return 0.0;
    }
}
