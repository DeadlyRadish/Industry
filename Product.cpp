#include "product.h"

int Product::count = 0;

Product::Product() {
    name = "Unknow";
    price = 0.0;
    quant = 0;
    count++;
}

Product::~Product() {
    count--;
}

Product::Product(std::string input_name, double input_price, int input_quant) {
    name = input_name;
    price = input_price;
    quant = input_quant;
    count++;
}

void Product::setName(std::string input_name) {
    name = input_name;
}

bool Product::setPrice(double input_price) {
    if (input_price > 0) {
        price = input_price;
        return true;
    }
    std::cout << "Ќевозможно записать отрицательное значение!" << std::endl;
    return false;
}

bool Product::setQuant(int input_quant) {
    if (input_quant > 0) {
        quant = input_quant;
        return true;
    }
    std::cout << "Ќевозможно записать отрицательное значение!" << std::endl;
    return false;
}

std::string Product::getName() {
    return name;
}

double Product::getPrice() {
    return price;
}

int Product::getQuant() {
    return quant;
}
