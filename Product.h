#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product
{
private:
    std::string name;
    double price;
public:
    int quant;
    static int count;

    Product();
    Product(std::string, double, int);

    ~Product();

    void setName(std::string);
    bool setPrice(double);
    bool setQuant(int);

    std::string getName();
    double getPrice();
    int getQuant();

};

#endif // PRODUCT_H
