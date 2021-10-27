//
// Created by Al Stark on 27.10.2021.
//
// сломал программу, не знаю как починить
#ifndef AVSHOMEWORK_TEXT_H
#define AVSHOMEWORK_TEXT_H

#include <cstdio>
class Text {
private:
    char text_[20];

public:
    Text(const char *text);

    const char *getText() const;



    static Text *in(FILE *ifst);

    static Text *inRnd();

    virtual void out(FILE *ofst);

    double Quontient(const char *enText) const;
};



#endif //AVSHOMEWORK_TEXT_H
