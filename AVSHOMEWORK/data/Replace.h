#ifndef AVSHOMEWORK_REPLACE_H
#define AVSHOMEWORK_REPLACE_H


#include "Text.h"

class Replace : public Text {
private:
    char chars_[2];
    char enText_[20];

public:
    Replace(const char *text, const char *chars);

    const char *getEnText() const;

    static Replace *in(FILE *ifst);

    static Replace *inRnd();



    void out(FILE *ofst) override;
};


#endif //AVSHOMEWORK_REPLACE_H
