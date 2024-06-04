#include "customer_base.h"
#include <stdlib.h>

CustomerBase::CustomerBase() {}

void CustomerBase::arrayExpansion() {
    int current_size = repository->count;
    Supplier* ptr = new(std::nothrow) Supplier[current_size + 1];
    if (ptr == nullptr) {
        std::cout << "Ошибка виделения памяти!" << std::endl;
        throw std::bad_alloc();
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

int CustomerBase::getIntValidInput() {
    int input_num = 0;
    while (true) {
        std::cin >> input_num;
        if (std::cin.good() && std::cin.peek() == '\n') {
            return input_num;
        }
        else {
            std::cout << "Неверный формат!\nВведите значение повторно:" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void CustomerBase::addNewSupplier() {
    std::string input_name = "";
    std::string input_address = "";
    double input_balance = 0;
    std::string input_date = "";

    int current_size = repository->count;
    try {
        arrayExpansion();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        std::cin >> repository[current_size];
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::exit(-1);
        return;
    }
}

void CustomerBase::saveDataToFile() {
    std::ofstream file_obj;
    file_obj.open(file_name);

    int i, current_size = repository->count;
    std::string templ_first_name;
    std::string templ_second_name;
    std::string templ_patronymic;

    try {
        if (!file_obj.is_open()) {
            throw std::runtime_error("Ошибка открытия файла");
        }
        file_obj << current_size << std::endl;
        for (i = 0; i < current_size; i++) {
            templ_first_name = repository[i].name.getFirstName();
            templ_second_name = repository[i].name.getSecondName();
            templ_patronymic = repository[i].name.getPatronymic();
            std::replace(templ_first_name.begin(), templ_first_name.end(), ' ', '_');
            std::replace(templ_second_name.begin(), templ_second_name.end(), ' ', '_');
            std::replace(templ_patronymic.begin(), templ_patronymic.end(), ' ', '_');
            file_obj << templ_first_name
                     << " " << templ_second_name
                     << " " << templ_patronymic
                     << " " << repository[i].getBalance()
                     << " " << repository[i].getDate()
                     << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    file_obj.close();
}

void CustomerBase::loadDataFromFile() {
    std::string templ_first_name;
    std::string templ_second_name;
    std::string templ_patronymic;
    double templ_balance;
    std::string templ_date;

    std::ifstream file_obj;
    file_obj.open(file_name);

    try {
        if (!file_obj.is_open()) {
            throw std::runtime_error("Ошибка открытия файла");
        }
        int i, size = 0;
        file_obj >> size;
        for (i = 0; i < size; i++) {
            try {
                arrayExpansion();
            } catch (const std::bad_alloc& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return;
            }
            file_obj >> templ_first_name
                >> templ_second_name
                >> templ_patronymic
                >> templ_balance
                >> templ_date;
            std::replace(templ_first_name.begin(), templ_first_name.end(), '_', ' ');
            std::replace(templ_second_name.begin(), templ_second_name.end(), '_', ' ');
            std::replace(templ_patronymic.begin(), templ_patronymic.end(), '_', ' ');
            repository[i].setName(templ_first_name, templ_second_name, templ_patronymic);
            repository[i].setBalance(templ_balance);
            repository[i].setDate(templ_date);
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    file_obj.close();
}

void CustomerBase::printData() {
    int i;

    std::cout << "----------------------------База данных поставщиков-------------------------------------" << std::endl;
    std::cout << "ФИО            /      Сумма поставки     /    Дата поставки" << std::endl;
    std::cout << "поставщика     /          (руб)          /    (дд.мм.гггг)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    for (i = 0; i < repository->count; i++) {
        std::cout << repository[i] << std::endl;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Количество записей в базе:   " << repository->count << std::endl;

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
        std::cout << "Поиск поставщика по ФИО........................................................3" << std::endl;
        std::cout << "Поиск поставщика по дате поставки..............................................4" << std::endl;
        std::cout << "Сортировка поставщиков по уменьшению сальдо ...................................5" << std::endl;
        std::cout << "Завершить выполнение программы.................................................6" << std::endl;
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
            findSupplierByDate();
        }
        else if (choise == 5) {
            sortBaseByBalance();
        }
        else if (choise == 5) {
            std::cout << "Завершение программы..." << std::endl;
            try {
                saveDataToFile();
            } catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        else {
            std::cout << "Такой функции не существует, попробуйте ввести еще раз!" << std::endl;
        }
    }
}

void CustomerBase::findSupplierByName() {
    bool flag = false;
    int i, current_size = repository->count;
    FIO input_fio;
    std::cin >> input_fio;
    Supplier* foundSuppliers = new Supplier[current_size];
    int foundCount = 0;
    for (i = 0; i < current_size; i++) {
        if (input_fio == repository[i].name) {
            foundSuppliers[foundCount] = repository[i];
            foundCount++;
            flag = true;
        }
    }
    if (flag) {
        std::cout << "Найденные поставщики:" << std::endl;
        for (int j = 0; j < foundCount; j++) {
            std::cout << foundSuppliers[j] << std::endl;
        }
    } else {
        std::cout << "Поставщики с таким ФИО не найдены." << std::endl;
    }
    delete[] foundSuppliers;
}
void CustomerBase::findSupplierByDate() {
    Date input_date;
    std::string dateStr;
    std::cout << "Введите дату (дд.мм.гггг):" << std::endl;
    std::getline(std::cin >> std::ws, dateStr);
    try {
        if (!Date::isValidDate(dateStr)) {
            throw std::runtime_error("Неверный формат ввода (ДД.ММ.ГГГГ)");
        }
        input_date = dateStr;
        bool found = false;
        int i, current_size = repository->count;
        Supplier* foundSuppliers = new Supplier[current_size];
        int foundCount = 0;
        for (i = 0; i < current_size; i++) {
            if (repository[i].getDate() == input_date.formatDateAsString()) {
                foundSuppliers[foundCount] = repository[i];
                foundCount++;
                found = true;
            }
        }
        if (found) {
            std::cout << "Найденные поставщики:" << std::endl;
            for (int j = 0; j < foundCount; j++) {
                std::cout << foundSuppliers[j] << std::endl;
            }
        } else {
            std::cout << "Поставщики с данной датой не найдены." << std::endl;
        }
        delete[] foundSuppliers;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CustomerBase::sortBaseByBalance() {
    int size = repository->count;
    Supplier temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (repository[j].getBalance() > repository[j + 1].getBalance()) {
                temp = repository[j];
                repository[j] = repository[j + 1];
                repository[j + 1] = temp;
            }
        }
    }
}

void CustomerBase::startProgram() {
    bool exist = std::filesystem::exists(file_name);
    if (!exist) {
        initializationRepository();
    }
    else {
        try {
            loadDataFromFile();
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    programMenu();
}
