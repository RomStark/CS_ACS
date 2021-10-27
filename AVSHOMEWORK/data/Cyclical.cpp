#include "Cyclical.h"
#include "../rnd_files/rnd.h"

Cyclical::Cyclical(const char *text, int n) : Text(text) {
    n_ = n;
    for (int i = 0; i < 20; i++) {
        enText_[i] = text[(i + n) % 20];
    }

}


const char *Cyclical::getEnText() const {
    return enText_;
}

Cyclical *Cyclical::in(FILE *ifst) {
    int n;
    char text[20];
    if (fscanf(ifst, "%s %d", text, &n) == EOF)
        return nullptr;

    return new Cyclical(text, n);
}

Cyclical *Cyclical::inRnd() {
    int n = Random::RandomRange(1, 20);
    char text[256];
    Random::RandomString(text, 20);

    return new Cyclical(text, n);
}

void Cyclical::out(FILE *ofst) {
    int n;
    n = n_;
    fprintf(ofst, "n = %d, encrypt text = %s.Task result: %f", n_, enText_, Quontient(enText_));
    Text::out(ofst);
}
