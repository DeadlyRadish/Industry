#include "stock.h"

Stock::Stock() {}

void Stock::arrayExpansion() {
    int current_size = repository->count;
    Product* ptr = new(std::nothrow) Product[current_size + 1];
    if (ptr == nullptr) {
        std::cout << "������ ��������� ������!" << std::endl;
    }
    else {
        for (int i = 0; i < current_size; i++) {
            ptr[i] = repository[i];
        }
        if (current_size != 0) {
            delete[] repository;
        }
        repository = ptr;
    }
}

int Stock::getIntValidInput() {
    int input_num = 0;
    while (true) {
        std::cin >> input_num;
        if (std::cin.good() && std::cin.peek() == '\n') {
            return input_num;
        }
        else {
            std::cout << "�������� ������!\n������� �������� ��������:" << std::endl;
        }
        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }
}

double Stock::getDoubleValidInput() {
    double input_num = 0;
    while (true) {
        std::cin >> input_num;
        if (std::cin.good() && std::cin.peek() == '\n') {
            return input_num;
        }
        else {
            std::cout << "�������� ������!\n������� �������� ��������:" << std::endl;
        }
        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }
}

void Stock::addNewProduct() {
    std::string input_name = "";
    double input_price = 0;
    int input_quant = 0;

    int current_size = repository->count;
    arrayExpansion();

    std::cout << "������� �������� ������:" << std::endl;
    std::getline(std::cin >> std::ws, input_name);
    repository[current_size].setName(input_name);

    std::cout << "������� ���� ������:" << std::endl;
    input_price = getDoubleValidInput();
    while (not repository[current_size].setPrice(input_price)) {
        std::cout << "������� �������� ��������:" << std::endl;
        input_price = getDoubleValidInput();
    }

    std::cout << "������� ���������� ������:" << std::endl;
    input_quant = getIntValidInput();
    while (not repository[current_size].setQuant(input_quant)) {
        std::cout << "������� �������� ��������:" << std::endl;
        input_quant = getIntValidInput();
    }
}

void Stock::saveDataToFile() {
    std::ofstream file_obj;
    file_obj.open(file_name);

    int i, current_size = repository->count;
    std::string templ_name;

    if (file_obj.is_open()) {
        file_obj << current_size << std::endl;
        for (i = 0; i < current_size; i++) {
            templ_name = repository[i].getName();
            std::replace(templ_name.begin(), templ_name.end(), ' ', '_');
            file_obj << templ_name
                << " " << repository[i].getPrice()
                << " " << repository[i].getQuant()
                << std::endl;
        }
    }
    else {
        std::cout << "������ �������� �����!" << std::endl;
    }
    file_obj.close();
}

void Stock::loadDataFromFile() {
    std::string templ_name;
    int templ_quant;
    double templ_price;

    std::ifstream file_obj;
    file_obj.open(file_name);

    if (file_obj.is_open()) {
        int i, size = 0;
        file_obj >> size;
        for (i = 0; i < size; i++) {
            arrayExpansion();
            file_obj >> templ_name
                >> templ_price
                >> templ_quant;
            std::replace(templ_name.begin(), templ_name.end(), '_', ' ');
            repository[i].setName(templ_name);
            repository[i].setPrice(templ_price);
            repository[i].setQuant(templ_quant);
        }
    }
    else {
        std::cout << "������ �������� �����!" << std::endl;
    }
    file_obj.close();
}

void Stock::printData() {
    int i;
    double partial_amount = 0., full_amount = 0.;

    std::cout << "---------------------------�����--------------------------------------" << std::endl;
    std::cout << "��������   ����   ����������   ����� �����" << std::endl;
    std::cout << "������     (���)     (��)        (���)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    for (i = 0; i < repository->count; i++) {
        partial_amount = repository[i].getPrice() * repository[i].getQuant();
        full_amount += partial_amount;
        std::cout << repository[i].getName() << "   " << repository[i].getPrice() << "   " << repository[i].getQuant() << "   " << partial_amount << std::endl;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "����� ������� �� ����� (���):   " << full_amount <<std::endl;
    std::cout << "���������� ������� � ����:   " << repository->count << std::endl;

}

void Stock::setFileName(std::string input_file_name) {
    file_name = input_file_name;
}

void Stock::findAllProductMoreThanTakePrice() {
    bool flag = false;
    int i, current_size = repository->count;
    std::cout << "������� ���� ������:" << std::endl;
    double input_price = getDoubleValidInput();
       
    for (i = 0; i < current_size; i++) {
        if (repository[i].getPrice() > input_price) {
            std::cout << repository[i].getName() << std::endl;
            flag = true;
        }
    }if (!flag) {
        std::cout << "�� ������� ������� � ����� ����: " << input_price << std::endl;
    }
}

void Stock::findProductByName(){
    bool flag = false;
    int i, current_size = repository->count;
    std::string input_name;
    std::cout << "������� �������� ������:" << std::endl;
    std::getline(std::cin >> std::ws, input_name);

    for (i = 0; i < current_size; i++) {
        if (repository[i].getName().compare(input_name) == 0) {
            flag = true;
            std::cout << repository[i].getName() << std::endl;
        }
    }if (!flag) {
        std::cout << "�� ������� ������� � �������������: " << input_name << std::endl;
    }
}

void Stock::initializationRepository() {
    int i, number_of_init;
    std::string input_name = "";
    double input_price = 0;
    int input_quant = 0;

    std::cout << "������� ���������� ������� ��� �������������" << std::endl;
    while ((number_of_init = getIntValidInput()) <= 0) {
        std::cout << "������� ������������� �����!" << std::endl;
    }
    for (i = 0; i < number_of_init; i++) {
        std::cout << "������������� ������: " << i << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        addNewProduct();
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void Stock::programMenu() {
    int choise = 0;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "�����" << std::endl;
    while (true) {
        std::cout << "---------------------��������� �������----------------------" << std::endl;
        std::cout << "�������� ����� �����.......................................1" << std::endl;
        std::cout << "����������� ���������� � �������...........................2" << std::endl;
        std::cout << "����� ������ �� ��������...................................3" << std::endl;
        std::cout << "����� ��� ������, ��������� ������� ������ ��������........4" << std::endl;
        std::cout << "��������� ���������� ���������.............................5" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "������� ����� �������:" << std::endl;
        while ((choise = getIntValidInput()) <= 0) {
            std::cout << "������� ����������� �����!" << std::endl;
        }
        if (choise == 1) {
            addNewProduct();
        }
        else if (choise == 2) {
            printData();
        }
        else if (choise == 3) {
            findProductByName();
        }
        else if (choise == 4) {
            findAllProductMoreThanTakePrice();
        }
        else if (choise == 5) {
            std::cout << "���������� ���������..." << std::endl;
            saveDataToFile();
            break;
        }
        else {
            std::cout << "����� ������� �� ����������, ���������� ������ ��� ���!" << std::endl;
        }
    }
}

void Stock::startProgram() {
    bool exist = std::filesystem::exists(file_name);
    if (!exist) {
        initializationRepository();
    }
    else {
        loadDataFromFile();
    }
    programMenu();
}
