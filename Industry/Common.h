#pragma once

#include<iostream>
#include<string>
#include"Date.h"

class Common
{
private:
	Date date_of_delivery;
	double balance;
public:
	Common() {};
	bool setDate(std::string);
	std::string getDate();
};

