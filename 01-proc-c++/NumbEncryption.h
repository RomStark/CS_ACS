//
// Created by Al Stark on 03.10.2021.
//

#ifndef TASK1_NUMBENCRYPTION_H
#define TASK1_NUMBENCRYPTION_H

#include <fstream>
using namespace std;
#include <set>


# include "rnd.h"

// прямоугольник
struct NumbEncryption {
    set<pair<char, short int> > st;
    string enText;
    string text;
};

// Ввод параметров прямоугольника из файла
void In(NumbEncryption &r, ifstream &ifst);

// Случайный ввод параметров прямоугольника
void InRnd(NumbEncryption &r);

// Вывод параметров прямоугольника в форматируемый поток
void Out(NumbEncryption &r, ofstream &ofst);

// Вычисление периметра прямоугольника
string Encryption(NumbEncryption &r);

#endif //TASK1_NUMBENCRYPTION_H




