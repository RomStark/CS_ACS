#ifndef AVSHOMEWORK_CYCLICAL_H
#define AVSHOMEWORK_CYCLICAL_H


#include "Text.h"

class Cyclical : public Text {
private:
    int n_;
    char enText_[20];

public:
    Cyclical(const char *text, int n);

    const char *getEnText() const;
    static Cyclical *in(FILE *ifst);

    static Cyclical *inRnd();

    void out(FILE *ofst) override;
};


#endif //AVSHOMEWORK_CYCLICAL_H
