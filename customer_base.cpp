#include "customer_base.h"

CustomerBase::CustomerBase() {}

int CustomerBase::getIntValidInput() {
    int input_num = 0;
    while (true) {
        std::cin >> input_num;
        if (std::cin.good() && std::cin.peek() == '\n') {
            return input_num;
        }
        else {
            std::cout << "Неверный формат!\nВведите значение повторно:" << std::endl;
        }
        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }
}

double CustomerBase::getDoubleValidInput() {
    double input_num = 0;
    while (true) {
        std::cin >> input_num;
        if (std::cin.good() && std::cin.peek() == '\n') {
            return input_num;
        }
        else {
            std::cout << "Неверный формат!\nВведите значение повторно:" << std::endl;
        }
        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }
}

void CustomerBase::addNewSupplier() {
    std::string input_name = "";
    std::string input_address = "";
    double input_balance = 0;
    std::string input_date = "";

    int current_size = repository.size();
    repository.push_back(Supplier());

    std::cout << "Введите наименование компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_name);
    repository[current_size].setName(input_name);

    std::cout << "Введите юридический адрес компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_address);
    repository[current_size].setAddress(input_address);

    std::cout << "Введите сальдо компании:" << std::endl;
    input_balance = getDoubleValidInput();
    while (not repository[current_size].setBalance(input_balance)) {
        std::cout << "Введите значение повторно:" << std::endl;
        input_balance = getDoubleValidInput();
    }

    std::cout << "Введите дату поставки: " << std::endl;
    std::getline(std::cin >> std::ws, input_date);
    while (not repository[current_size].setDate(input_date)) {
        std::cout << "Введите значение повторно:" << std::endl;
        std::getline(std::cin >> std::ws, input_date);
    }
}

void CustomerBase::saveDataToFile() {
    std::ofstream file_obj;
    file_obj.open(file_name);

    int i, current_size = repository.size();
    std::string templ_name;
    std::string templ_address;

    if (file_obj.is_open()) {
        file_obj << current_size << std::endl;
        for (i = 0; i < current_size; i++) {
            templ_name = repository[i].getName();
            templ_address = repository[i].getAddress();
            std::replace(templ_name.begin(), templ_name.end(), ' ', '_');
            std::replace(templ_address.begin(), templ_address.end(), ' ', '_');
            file_obj << templ_name
                     << " " << templ_address
                     << " " << repository[i].getBalance()
                     << " " << repository[i].getDate()
                     << std::endl;
        }
    }
    else {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    file_obj.close();
}

void CustomerBase::loadDataFromFile() {
    std::string templ_name;
    std::string templ_address;
    double templ_balance;
    std::string templ_date;

    std::ifstream file_obj;
    file_obj.open(file_name);

    if (file_obj.is_open()) {
        int i, size = 0;
        file_obj >> size;
        for (i = 0; i < size; i++) {
            repository.push_back(Supplier());
            file_obj >> templ_name
                >> templ_address
                >> templ_balance
                >> templ_date;
            std::replace(templ_name.begin(), templ_name.end(), '_', ' ');
            std::replace(templ_address.begin(), templ_address.end(), '_', ' ');
            repository[i].setName(templ_name);
            repository[i].setAddress(templ_address);
            repository[i].setBalance(templ_balance);
            repository[i].setDate(templ_date);
        }
    }
    else {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    file_obj.close();
}

void CustomerBase::printData() {
    int i;

    std::cout << "----------------------------База данных поставщиков-------------------------------------" << std::endl;
    std::cout << "Название      Юридический     Сальдо       Дата поставки" << std::endl;
    std::cout << "компании        адрес         (руб)        (дд.мм.гггг)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    if (repository.empty()){
        std::cout << "Не содержит записей" << std::endl;
    }
    else
    for (i = 0; i < repository.size(); i++) {
        std::cout << repository[i].getName() << "   " << repository[i].getAddress() << "   " << repository[i].getBalance() << "   " << repository[i].getDate() << std::endl;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Количество записей в базе:   " << repository.size() << std::endl;

}

void CustomerBase::setFileName(std::string input_file_name) {
    file_name = input_file_name;
}

void CustomerBase::initializationRepository() {
    int i, number_of_init;
    std::string input_name = "";
    double input_price = 0;
    int input_quant = 0;

    std::cout << "Введите количество компаний для инициализации" << std::endl;
    while ((number_of_init = getIntValidInput()) <= 0) {
        std::cout << "Введите положительное число!" << std::endl;
    }
    for (i = 0; i < number_of_init; i++) {
        std::cout << "Инициализация компании: " << i << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        addNewSupplier();
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void CustomerBase::programMenu() {
    int choise = 0;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "База данных поставщиков" << std::endl;
    while (true) {
        std::cout << "--------------------------------Доступные функции-------------------------------" << std::endl;
        std::cout << "Добавить нового поставщика.....................................................1" << std::endl;
        std::cout << "Распечатать информацию о поставщиках...........................................2" << std::endl;
        std::cout << "Поиск поставщика по названию...................................................3" << std::endl;
        std::cout << "Сортировка поставщиков по уменьшению сальдо ...................................4" << std::endl;
        std::cout << "Завершить выполнение программы.................................................5" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "Введите номер функции:" << std::endl;
        while ((choise = getIntValidInput()) <= 0) {
            std::cout << "Введите натуральное число!" << std::endl;
        }
        if (choise == 1) {
            addNewSupplier();
        }
        else if (choise == 2) {
            printData();
        }
        else if (choise == 3) {
            findSupplierByName();
        }
        else if (choise == 4) {
            sortBaseByBalance();
        }
        else if (choise == 5) {
            std::cout << "Завершение программы..." << std::endl;
            saveDataToFile();
            break;
        }
        else {
            std::cout << "Такой функции не существует, попробуйте ввести еще раз!" << std::endl;
        }
    }
}

void CustomerBase::sortBaseByBalance() {
    std::sort(repository.begin(), repository.end(),
              [](Supplier& a, Supplier& b){
        return a.getBalance() < b.getBalance();
    });
}

void CustomerBase::findSupplierByName() {
    std::string input_name;
    std::cout << "Введите название компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_name);

    auto it = std::find_if(repository.begin(), repository.end(), [input_name](Supplier& supplier) {
        return supplier.getName().compare(input_name) == 0;
    });
    if (it != repository.end()) {
        std::cout << it->getName() << std::endl;
    } else {
        std::cout << "Не найдено компании с таким названием: " << input_name << std::endl;
    }
}

void CustomerBase::findSupplierByDate() {
    std::string input_date;
    std::cout << "Введите дату поставки: " << std::endl;
    std::getline(std::cin >> std::ws, input_date);
    while (!Date::isValidDate(input_date)) {
        std::cout << "Введите значение повторно:" << std::endl;
        std::getline(std::cin >> std::ws, input_date);
    }
}

void CustomerBase::startProgram() {
    bool exist = std::filesystem::exists(file_name);
    if (!exist) {
        initializationRepository();
    }
    else {
        loadDataFromFile();
    }
    programMenu();
}
