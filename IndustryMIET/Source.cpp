#include<iostream>
#include<string>
#include"CustomersBase.h"

int main() {
	std::setlocale(LC_ALL, "ru");
	system("chcp 1251");
	CustomerBase cache;
	cache.setFileName("Place.txt");
	cache.startProgram();
	return 0;
}