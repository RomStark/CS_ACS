#ifndef AVSHOMEWORK_RND_H
#define AVSHOMEWORK_RND_H
#include <string>




class Random {
public:
    std::string RandomStr();

    static int RandomInt();

    static char RandomChar();
    static int RandomRange(int min, int max);
    static char *RandomString(char *str, size_t size);

};



#endif
