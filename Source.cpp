#include "stock.h"

int main()
{
    std::setlocale(LC_ALL, "ru");
    system("chcp 1251");

    Stock cache;
    cache.setFileName("Place.txt");
    cache.startProgram();
    return 0;
}
