#include <cstring>
#include "numbChar.h"
#include "../rnd_files/rnd.h"

NumbChar::NumbChar(const char *text,  const char *charNumb) : Text(text) {
    strcpy(charNumb_, charNumb);
    for (int i = 0; i < 20; i++) {
        if (text[i] == charNumb[0]) {
            enText_[i] = charNumb[1];
        } else {
            enText_[i] = text[i];
        }
    }
}

const char *NumbChar::getEnText() const {
    return enText_;
}
NumbChar *NumbChar::in(FILE *ifst) {
    char text[20];
    if (fscanf(ifst, "%s %d",  text) == EOF)
        return nullptr;

    char charNumb[2];
    if (fscanf(ifst, "%s", charNumb) == EOF)
        return nullptr;


    return new NumbChar(text,charNumb);
}

NumbChar *NumbChar::inRnd() {
    char text[20];
    Random::RandomString(text, 20);
    char charNumb[2];
    charNumb[0] = Random::RandomChar();
    charNumb[1] = Random::RandomInt();


    return new NumbChar(text,charNumb);
}

void NumbChar::out(FILE *ofst) {
    fprintf(ofst, "This is charNumb encryption: charNumb = %c %c ., encryption text : %s, func result: %f", charNumb_[0], charNumb_[1], enText_,
            Quontient(enText_));
    Text::out(ofst);
}
