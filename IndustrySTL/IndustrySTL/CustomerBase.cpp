#include "customerbase.h"

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
    repository.back().setName(input_name);

    std::cout << "Введите юридический адрес компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_address);
    repository.back().setAddress(input_address);

    std::cout << "Введите сальдо компании:" << std::endl;
    input_balance = getDoubleValidInput();
    while (not repository.back().setBalance(input_balance)) {
        std::cout << "Введите значение повторно:" << std::endl;
        input_balance = getDoubleValidInput();
    }

    std::cout << "Введите дату поставки: " << std::endl;
    std::getline(std::cin >> std::ws, input_date);
    while (not repository.back().setDate(input_date)) {
        std::cout << "Введите значение повторно:" << std::endl;
        std::getline(std::cin >> std::ws, input_date);
    }
}

void CustomerBase::addNewSupplierToIndex(int index) {
    std::string input_name = "";
    std::string input_address = "";
    double input_balance = 0;
    std::string input_date = "";
    std::list<Supplier>::iterator iter_rep = repository.begin();
    std::advance(iter_rep, index);

    std::cout << "Введите наименование компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_name);
    iter_rep->setName(input_name);

    std::cout << "Введите юридический адрес компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_address);
    iter_rep->setAddress(input_address);

    std::cout << "Введите сальдо компании:" << std::endl;
    input_balance = getDoubleValidInput();
    while (not iter_rep->setBalance(input_balance)) {
        std::cout << "Введите значение повторно:" << std::endl;
        input_balance = getDoubleValidInput();
    }

    std::cout << "Введите дату поставки: " << std::endl;
    std::getline(std::cin >> std::ws, input_date);
    while (not iter_rep->setDate(input_date)) {
        std::cout << "Введите значение повторно:" << std::endl;
        std::getline(std::cin >> std::ws, input_date);
    }
}


void CustomerBase::saveDataToFile() {
    std::ofstream file_obj;
    file_obj.open(file_name);

    int current_size = repository.size();
    std::string templ_name;
    std::string templ_address;
    std::list<Supplier>::iterator iter_rep;

    if (file_obj.is_open()) {
        file_obj << current_size << std::endl;
        for (iter_rep = repository.begin(); iter_rep != repository.end(); iter_rep++) {
            templ_name = iter_rep->getName();
            templ_address = iter_rep->getAddress();
            std::replace(templ_name.begin(), templ_name.end(), ' ', '_');
            std::replace(templ_address.begin(), templ_address.end(), ' ', '_');
            file_obj << templ_name
                << " " << templ_address
                << " " << iter_rep->getBalance()
                << " " << iter_rep->getDate()
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
    std::list<Supplier>::iterator iter_rep;

    if (file_obj.is_open()) {
        int size = 0;
        file_obj >> size;
        for (iter_rep = repository.begin(); iter_rep != repository.end(); iter_rep++) {
            repository.push_back(Supplier());
            file_obj >> templ_name
                >> templ_address
                >> templ_balance
                >> templ_date;
            std::replace(templ_name.begin(), templ_name.end(), '_', ' ');
            std::replace(templ_address.begin(), templ_address.end(), '_', ' ');
            iter_rep->setName(templ_name);
            iter_rep->setAddress(templ_address);
            iter_rep->setBalance(templ_balance);
            iter_rep->setDate(templ_date);
        }
    }
    else {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    file_obj.close();
}

void CustomerBase::printData() {
    std::list<Supplier>::iterator iter_rep;

    std::cout << "----------------------------База данных поставщиков-------------------------------------" << std::endl;
    std::cout << "Название      Юридический     Сальдо       Дата поставки" << std::endl;
    std::cout << "компании        адрес         (руб)        (дд.мм.гггг)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    if (repository.empty()) {
        std::cout << "Не содержит записей" << std::endl;
    }
    else
        for (iter_rep = repository.begin(); iter_rep != repository.end(); iter_rep++) {
            std::cout << iter_rep->getName() << "   " << iter_rep->getAddress() << "   " << iter_rep->getBalance() << "   " << iter_rep->getDate() << std::endl;
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
        std::cout << "Сортировка поставщиков по уменьшению сальдо....................................4" << std::endl;
        std::cout << "Добавить поставщика по индексу.................................................5" << std::endl;
        std::cout << "Удалить поставщика по индексу..................................................6" << std::endl;
        std::cout << "Поиск поставщика по дате поставки..............................................7" << std::endl;
        std::cout << "Завершить выполнение программы.................................................8" << std::endl;
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
            addSupplierByIndex();
        }
        else if (choise == 6) {
            deleteSupplierByIndex();
        }
        else if (choise == 7) {
            findSupplierByDate();
        }
        else if (choise == 8) {
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
    repository.sort([](Supplier& a, Supplier& b) {return a.getBalance() < b.getBalance(); });
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
    }
    else {
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
    auto it = std::find_if(repository.begin(), repository.end(), [input_date](Supplier& supplier) {
        return supplier.getDate().compare(input_date) == 0;
        });
    if (it != repository.end()) {
        std::cout << it->getName() << std::endl;
    }
    else {
        std::cout << "Не найдено компаний с данной датой поставки: " << input_date << std::endl;
    }
}

void CustomerBase::deleteSupplierByIndex() {
    int current_size = repository.size();
    int pos;
    std::list<Supplier>::iterator iter_rep;
    std::cout << "Введите позицию элемента для удаления: " << std::endl;
    while ((pos = getIntValidInput()) < 1 || pos > current_size) {
        std::cout << "Введите число в пределах от 1 до " << current_size << std::endl;
    }
    std::advance(iter_rep, pos - 1);
    repository.erase(iter_rep);    
}

void CustomerBase::addSupplierByIndex() {
    int current_size = repository.size();
    int pos;
    std::list<Supplier>::iterator iter_rep;
    std::cout << "Введите позицию для добавления элеманта: " << std::endl;
    while ((pos = getIntValidInput()) < 1 || pos > current_size) {
        std::cout << "Введите число в пределах от 1 до " << current_size << std::endl;
    }
    std::advance(iter_rep, pos);
    repository.insert(iter_rep, Supplier());
    addNewSupplierToIndex(pos - 1);
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