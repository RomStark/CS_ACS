#include <cstring>
#include "Replace.h"
#include "../rnd_files/rnd.h"

Replace::Replace(const char *text, const char *chars) : Text(text){
    strcpy(chars_, chars);
    for (int i =0; i < 20; i++) {
        if (text[i] == chars[0]) {
            enText_[i] = chars[1];
        } else {
            enText_[i] = text[i];
        }
    }
}

const char *Replace::getEnText() const {
    return enText_;
}

Replace *Replace::in(FILE *ifst) {
    char text[20];
    if (fscanf(ifst, "%s %d", text) == EOF)
        return nullptr;
    char chars[2];
    if (fscanf(ifst, "%s", chars) == EOF)
        return nullptr;

    return new Replace(text, chars);
}

Replace *Replace::inRnd() {
    char text[20];
    Random::RandomString(text, 20);
    char chars[2];
    Random::RandomString(chars, 2);
    return new Replace(text, chars);
}

void Replace::out(FILE *ofst) {
    const char *chars;
    chars = chars_;
    fprintf(ofst, "This is replace: chars = %c %c.Task result: %f. EnText: %s", chars[0], chars[1], Quontient(enText_), enText_);
    Text::out(ofst);
}

