#include "rnd.h"
#include <string>


int Random::RandomInt(){
    return rand() % 5 + 5;
}

int Random::RandomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char Random::RandomChar(){
    return rand() % 26 + 97;
}

std::string Random::RandomStr() {
    std::string text;
    int index = rand() %20 + 10;
    for (int i = 0; i < index; i++) {
        text += char(rand() % 26 + 97);
    }
    return text;
}

char *Random::RandomString(char *str, size_t size) {
    const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = RandomRange(0, strlen(charset) - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}