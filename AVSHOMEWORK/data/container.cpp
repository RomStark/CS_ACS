#include "container.h"

Container::Container() {
    cont = new Text *[MAX_LEN];
}

Container::~Container() {
    for (int i = 0; i < len_; i++) {
        delete cont[i];
    }

    delete[] cont;
}

void Container::in(FILE *ifst) {
    Text *newText;
    while ((newText = Text::in(ifst)) != nullptr) {
        cont[len_] = newText;
        len_++;
    }
}

void Container::inRnd(int size) {
    while (len_ < size) {
        if ((cont[len_] = Text::inRnd()) != nullptr) {
            len_++;
        }
    }
}

void Container::out(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", len_);
    for (int i = 0; i < len_; i++) {
        fprintf(ofst, "%d: ", i);
        cont[i]->out(ofst);
    }
}


void Container::sortShellContainer() {
    for (int s = len_ / 2; s > 0; s /= 2) {
        for (int i = 0; i < len_; i++) {
            for (int j = i + s; j < len_; j += s) {
                if (cont[i]->Quontient(cont[i]->getText()) > cont[j]->Quontient(cont[i]->getText())) {
                    Text *temp = cont[j];
                    cont[j] = cont[i];
                    cont[i] = temp;
                }
            }
        }
    }
}
