#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

inline string Random() {
    string text;
    int index = rand() %20 + 10;
    for (int i = 0; i < index; i++) {
        text += char(rand() % 26 + 97);
    }
    return text;
}

inline int RandomInt() {
    return rand() % 5 + 5;
}

inline char RandomChar(){
    return rand() % 26 + 97;
}

//inline char* Random_2() {
//    char *mas[2] = new char[2];
//    mas[0] = rand() % 26 + 97;
//    mas[1] = rand() % 26 + 97;
//    return mas;
//}

#endif //__rnd__
