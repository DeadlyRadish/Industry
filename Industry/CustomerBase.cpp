#include"CustomerBase.h"

CustomerBase::CustomerBase() {}

void CustomerBase::arrayExpansion() {
    int current_size = repository->count;
    Supplier* ptr = new(std::nothrow) Supplier[current_size + 1];
    if (ptr == nullptr) {
        std::cout << "Ошибка виделения памяти!" << std::endl;
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

void CustomerBase::arrayExpansion1() {
    int current_size = repository1->count;
    Supplier1* ptr = new(std::nothrow) Supplier1[current_size + 1];
    if (ptr == nullptr) {
        std::cout << "Ошибка виделения памяти!" << std::endl;
    }
    else {
        for (int i = 0; i < current_size; i++) {
            ptr[i] = repository1[i];
        }
        if (current_size != 0) {
            delete[] repository1;
        }
        repository1 = ptr;
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

    int current_size = repository->count;
    arrayExpansion();

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

void CustomerBase::addNewSupplier1() {
    std::string input_first_name = "";
    std::string input_second_name = "";
    std::string input_patronymic = "";
    double input_balance = 0;
    std::string input_date = "";

    int current_size = repository1->count;
    arrayExpansion1();

    std::cout << "Введите имя поставщика: " << std::endl;
    std::getline(std::cin >> std::ws, input_first_name);

    std::cout << "Введите фамилию поставщика: " << std::endl;
    std::getline(std::cin >> std::ws, input_second_name);

    std::cout << "Введите отчество поставщика: " << std::endl;
    std::getline(std::cin >> std::ws, input_patronymic);

    repository1[current_size].setName(input_first_name, input_second_name, input_patronymic);

    std::cout << "Введите сумму поставки:" << std::endl;
    input_balance = getDoubleValidInput();
    while (not repository1[current_size].setBalance(input_balance)) {
        std::cout << "Введите значение повторно:" << std::endl;
        input_balance = getDoubleValidInput();
    }

    std::cout << "Введите дату поставки: " << std::endl;
    std::getline(std::cin >> std::ws, input_date);
    while (not repository1[current_size].setDate(input_date)) {
        std::cout << "Введите значение повторно:" << std::endl;
        std::getline(std::cin >> std::ws, input_date);
    }
}

void CustomerBase::saveDataToFile() {
    std::ofstream file_obj;
    file_obj.open(file_name);

    int i, current_size = repository->count;
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

void CustomerBase::saveDataToFile1() {
    std::ofstream file_obj;
    file_obj.open(file_name1);

    int i, current_size = repository1->count;
    std::string templ_first_name;
    std::string templ_second_name;
    std::string templ_patronymic;

    if (file_obj.is_open()) {
        file_obj << current_size << std::endl;
        for (i = 0; i < current_size; i++) {
            templ_first_name = repository1[i].seller.getFirstName();
            templ_second_name = repository1[i].seller.getSecondName();
            templ_patronymic = repository1[i].seller.getPatronymic();
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
            arrayExpansion();
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

void CustomerBase::loadDataFromFile1() {
    std::string templ_first_name;
    std::string templ_second_name;
    std::string templ_patronymic;
    double templ_balance;
    std::string templ_date;

    std::ifstream file_obj1;
    file_obj1.open(file_name1);

    if (file_obj1.is_open()) {
        int i, size = 0;
        file_obj1 >> size;
        for (i = 0; i < size; i++) {
            arrayExpansion1();
            file_obj1 >> templ_first_name
                >> templ_second_name
                >> templ_patronymic
                >> templ_balance
                >> templ_date;
            std::replace(templ_first_name.begin(), templ_first_name.end(), '_', ' ');
            std::replace(templ_second_name.begin(), templ_second_name.end(), '_', ' ');
            std::replace(templ_patronymic.begin(), templ_patronymic.end(), '_', ' ');
            repository1[i].setName(templ_first_name, templ_second_name, templ_patronymic);
            repository1[i].setBalance(templ_balance);
            repository1[i].setDate(templ_date);
        }
    }
    else {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    file_obj1.close();
}

void CustomerBase::printData() {
    int i, j;

    std::cout << "----------------------------База данных поставщиков (компании)-------------------------------------" << std::endl;
    std::cout << "Название      Юридический     Сальдо       Дата поставки" << std::endl;
    std::cout << "компании        адрес         (руб)        (дд.мм.гггг)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    for (i = 0; i < repository->count; i++) {
        std::cout << repository[i].getName() << "   " << repository[i].getAddress() << "   " << repository[i].getBalance() << "   " << repository[i].getDate() << std::endl;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Количество записей в базе:   " << repository->count << std::endl;

    std::cout << "---------------------База данных поставщиков (индивидуальные предприниматели)----------------------" << std::endl;
    std::cout << "ФИО                       Сумма поставки       Дата поставки" << std::endl;
    std::cout << "поставщика                    (руб)           (дд.мм.гггг)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    for (j = 0; j < repository1->count; j++) {
        std::cout << repository1[j].getName() << "   " << repository1[j].getBalance() << "   " << repository1[j].getDate() << std::endl;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Количество записей в базе:   " << repository1->count << std::endl;

}

void CustomerBase::setFileName(std::string input_file_name) {
    file_name = input_file_name;
}

void CustomerBase::setFileName1(std::string input_file_name) {
    file_name1 = input_file_name;
}

void CustomerBase::findSupplierByName() {
    bool flag = false;
    int i, current_size = repository->count;
    std::string input_name;
    std::cout << "Введите название компании: " << std::endl;
    std::getline(std::cin >> std::ws, input_name);

    for (i = 0; i < current_size; i++) {
        if (repository[i].getName().compare(input_name) == 0) {
            flag = true;
            std::cout << repository[i].getName() << std::endl;
        }
    }if (!flag) {
        std::cout << "Не найдено компании с таким названием: " << input_name << std::endl;
    }
}

void CustomerBase::findSupplierByName1() {
    bool flag = false;
    int i, current_size = repository1->count;
    std::string input_name;
    std::cout << "Введите ФИО ИП: " << std::endl;
    std::getline(std::cin >> std::ws, input_name);

    for (i = 0; i < current_size; i++) {
        if (repository1[i].getName().compare(input_name) == 0) {
            flag = true;
            std::cout << repository1[i].getName() << std::endl;
        }
    }if (!flag) {
        std::cout << "Не найдено компании с таким названием: " << input_name << std::endl;
    }
}

void CustomerBase::initializationRepository() {
    int i, number_of_init;

    std::cout << "Введите количество компаний для инициализации" << std::endl;
    while ((number_of_init = getIntValidInput()) <= 0) {
        std::cout << "Введите положительное число!" << std::endl;
    }
    for (i = 0; i < number_of_init; i++) {
        std::cout << "Инициализация компании: " << i + 1 << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        addNewSupplier();
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void CustomerBase::initializationRepository1() {
    int i, number_of_init;

    std::cout << "Введите количество ИП для инициализации" << std::endl;
    while ((number_of_init = getIntValidInput()) <= 0) {
        std::cout << "Введите положительное число!" << std::endl;
    }
    for (i = 0; i < number_of_init; i++) {
        std::cout << "Инициализация компании: " << i + 1 << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        addNewSupplier1();
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void CustomerBase::programMenu() {
    int choise = 0;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "База данных поставщиков" << std::endl;
    while (true) {
        std::cout << "--------------------------------Доступные функции-------------------------------" << std::endl;
        std::cout << "Добавить нового поставщика(компания)...........................................1" << std::endl;
        std::cout << "Добавить нового поставщика(ИП).................................................2" << std::endl;
        std::cout << "Распечатать информацию о поставщиках...........................................3" << std::endl;
        std::cout << "Поиск поставщика по названию(компании).........................................4" << std::endl;
        std::cout << "Поиск поставщика по названию(ИП)...............................................5" << std::endl;
        std::cout << "Сортировка поставщиков по уменьшению сальдо/суммы поставки.....................6" << std::endl;
        std::cout << "Завершить выполнение программы.................................................7" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "Введите номер функции:" << std::endl;
        while ((choise = getIntValidInput()) <= 0) {
            std::cout << "Введите натуральное число!" << std::endl;
        }
        if (choise == 1) {
            addNewSupplier();
        }
        else if (choise == 2) {
            addNewSupplier1();
        }
        else if (choise == 3) {
            printData();
        }
        else if (choise == 4) {
            findSupplierByName();
        }
        else if (choise == 5) {
            findSupplierByName1();
        }
        else if (choise == 6) {
            sortBaseByBalance();
            sortBaseByBalance1();
        }
        else if (choise == 7) {
            std::cout << "Завершение программы..." << std::endl;
            saveDataToFile();
            saveDataToFile1();
            break;
        }
        else {
            std::cout << "Такой функции не существует, попробуйте ввести еще раз!" << std::endl;
        }
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

void CustomerBase::sortBaseByBalance1() {
    int size = repository1->count;
    Supplier1 temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (repository1[j].getBalance() > repository1[j + 1].getBalance()) {
                temp = repository1[j];
                repository1[j] = repository1[j + 1];
                repository1[j + 1] = temp;
            }
        }
    }
}

void CustomerBase::startProgram() {
    bool exist = std::filesystem::exists(file_name);
    bool exist1 = std::filesystem::exists(file_name1);
    if (!exist && !exist1) {
        initializationRepository();
        initializationRepository1();
    }
    else if (!exist && exist1) {
        initializationRepository();
        loadDataFromFile1();
    }
    else if (exist && !exist1) {
        initializationRepository1();
        loadDataFromFile();
    }
    else {
        loadDataFromFile();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        loadDataFromFile1();
    }
    programMenu();
}