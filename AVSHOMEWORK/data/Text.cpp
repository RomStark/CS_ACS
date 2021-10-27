//
// Created by Al Stark on 27.10.2021.
//

#include "Text.h"
#include <cstdio>
#include <cstring>
#include "numbChar.h"
#include "Replace.h"
#include "Cyclical.h"
#include "../rnd_files/rnd.h"

Text::Text(const char *text)  {
    strcpy(text_, text);
}

const char *Text::getText() const {
    return text_;
}



Text *Text::in(FILE *ifst) {
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return nullptr;

    switch (k) {
        case 1:
            return Replace::in(ifst);
        case 2:
            return NumbChar::in(ifst);
        case 3:
            return Cyclical::in(ifst);
        default:
            return nullptr;
    }
}

Text *Text::inRnd() {
    int k = Random::RandomRange(1, 3);
    switch (k) {
        case 1:
            return Replace::inRnd();
        case 2:
            return NumbChar::inRnd();
        case 3:
            return Cyclical::inRnd();
        default:
            return nullptr;
    }
}

void Text::out(FILE *ofst) {
    fprintf(ofst, " Text = %s,\n", text_);
}

double Text::Quontient(const char *enText) const {
    double k = 0;
    double d = 0;
    for (int i = 0; i < sizeof(text_); i++) {
        k += int(text_[i]);
        d += int(enText[i]);
    }
    return k / d;
}
