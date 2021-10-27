#ifndef AVSHOMEWORK_CONTAINER_H
#define AVSHOMEWORK_CONTAINER_H


#include <cstdio>
#include "Text.h"

class Container {
private:
    const int MAX_LEN = 10000; // Макс. длина.
    int len_ = 0;
    Text **cont;

public:
    Container();

    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void in(FILE *ifst);

    // Случайный ввод содержимого контейнера
    void inRnd(int size);

    // Вывод содержимого контейнера в указанный поток
    void out(FILE *ofst);

    // Сортировка Шелла по возрастанию
    void sortShellContainer();
};

#endif //AVSHOMEWORK_CONTAINER_H
