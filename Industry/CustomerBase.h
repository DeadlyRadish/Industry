#pragma once

#include"Delivery1.h"
#include"Delivery2.h"

#include <iostream>
#include <string>
#include <new>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <chrono>
#include <thread>

class CustomerBase
{
private:
    Supplier* repository;
    Supplier1* repository1;
    std::string file_name;
    std::string file_name1;

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

    void loadDataFromFile1();
    void saveDataToFile1();
    void arrayExpansion1();
    void initializationRepository1();
    void addNewSupplier1();
    void findSupplierByName1();
    void sortBaseByBalance1();
public:
    CustomerBase();
    ~CustomerBase() {
        delete[] repository;
    };
    void startProgram();
    void setFileName(std::string);
    void setFileName1(std::string);
};
