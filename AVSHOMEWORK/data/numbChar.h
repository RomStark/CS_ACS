

#ifndef AVSHOMEWORK_NUMBCHAR_H
#define AVSHOMEWORK_NUMBCHAR_H


#include "Text.h"

class NumbChar : public Text {
    char charNumb_[2];
    char enText_[20];
public:

    const char *getEnText() const;
    NumbChar(const char *text, const char *charNumb);

    static NumbChar *in(FILE *ifst);

    static NumbChar *inRnd();

    void out(FILE *ofst) override;
};


#endif
