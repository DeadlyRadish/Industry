#ifndef STOCK_H
#define STOCK_H

#include "product.h"

#include <iostream>
#include <string>
#include <new>
#include <fstream>
#include <algorithm>
#include <filesystem>

class Stock
{
private:
    Product* repository;
    std::string file_name;

    void loadDataFromFile();
    void saveDataToFile();
    void arrayExpansion();
    void initializationRepository();
    int getIntValidInput();
    double getDoubleValidInput();
    void addNewProduct();
    void printData();
    void programMenu();
    void findAllProductMoreThanTakePrice();
    void findProductByName();

public:

    Stock();
    ~Stock() {
        delete[] repository;
    }

    void startProgram();
    void setFileName(std::string);
};


#endif // STOCK_H
