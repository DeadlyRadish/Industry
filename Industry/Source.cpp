#include<iostream>
#include<string>
#include"CustomerBase.h"

int main() {
	std::setlocale(LC_ALL, "ru");
	system("chcp 1251");
	CustomerBase cache;
	cache.setFileName("Place.txt");
	cache.setFileName1("Place1.txt");
	cache.startProgram();
	return 0;
}