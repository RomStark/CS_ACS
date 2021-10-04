//
// Created by Al Stark on 03.10.2021.
//

#include "NumbEncryption.h"


//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(NumbEncryption &r, ifstream &ifst) {
    ifst >> r.enText;
    int k;
    for (int i = 0; i < 26; i++) {
        r.st.insert({char(97 + i), cin >> k})
    }
}

// Случайный ввод параметров прямоугольника
void InRnd(NumbEncryption &r) {
    r.enText = Random();
    for (int i = 0; i < 26; i++) {
        r.st.insert({char(97 + i), RandomInt()})
    }

}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(NumbEncryption &r, ofstream &ofst) {
    ofst << "It is NumbEncryption : entext = " << r.enTexttext
         << ". Function = " << Encryption(r) << ", text = " << r.text << "\n";
}

//------------------------------------------------------------------------------
// Шифрование текста
double Encryption(NumbEncryption &r) {
    for (int i = 0; i < r.text.size(); i++) {
        r.enTexttext += r.st[r.text[i]];
    }
    int k;
    int d;
    for (int i = 0; i < r.text.size(); i++) {
        k += int(r.text[i]);
        d += int(r.enText[i]);
    }
    return k / d;
}
