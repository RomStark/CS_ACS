#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// encryption.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include "ReplCharEncryption.h"
#include "CyclicEncryption.h"
#include "NumbEncryption.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct encryption {
    // значения ключей для каждой из фигур
    enum key {CYCLICENCRYPTION, REPLCHARENCRYPTION, NUMBENCRYPTION};
    key k; // ключ
    ReplCharEncryption r;
    CyclicEncryption t;
    NumbEncryption n;
    // используемые альтернативы
};

// Ввод обобщенной фигуры
encryption *In(ifstream &ifdt);

// Случайный ввод обобщенной фигуры
encryption *InRnd();

// Вывод обобщенной фигуры
void Out(encryption &s, ofstream &ofst);

// Вычисление периметра обобщенной фигуры
double Encryption(encryption &s);

#endif
