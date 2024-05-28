#ifndef CUSTOMER_BASE_H
#define CUSTOMER_BASE_H

#include"supplier.h"
#include"date.h"

#include <iostream>
#include <string>
#include <new>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

class CustomerBase
{
private:
    std::vector<Supplier> repository;
    std::string file_name;

    void loadDataFromFile();
    void saveDataToFile();
    void initializationRepository();
    int getIntValidInput();
    double getDoubleValidInput();
    void addNewSupplier();
    void printData();
    void programMenu();
    void findSupplierByName();
    void sortBaseByBalance();
    void findSupplierByDate();
    void deleteItemFromPos(int);
    void addSupplierToBegin();
    void addSupplierToEnd();
public:
    CustomerBase();
    ~CustomerBase() {
        repository.clear();
    };
    void startProgram();
    void setFileName(std::string);
};
#endif // CUSTOMER_BASE_H
