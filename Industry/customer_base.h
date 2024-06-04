#ifndef CUSTOMER_BASE_H
#define CUSTOMER_BASE_H

#include"supplier.h"

#include <iostream>
#include <string>
#include <new>
#include <fstream>
#include <algorithm>
#include <filesystem>

class CustomerBase
{
private:
    Supplier* repository;
    std::string file_name;

    void loadDataFromFile();
    void saveDataToFile();
    void arrayExpansion();
    void initializationRepository();
    int getIntValidInput();
    double getDoubleValidInput();
    void addNewSupplier();
    void printData();
    void programMenu();
    void findSupplierByName();
    void sortBaseByBalance();
    void findSupplierByDate();
public:
    CustomerBase();
    ~CustomerBase() {
        delete[] repository;
    };
    void startProgram();
    void setFileName(std::string);
};
#endif // CUSTOMER_BASE_H
