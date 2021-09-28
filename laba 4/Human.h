#pragma once

#include "libraries.h"

class Human
{
private:
	std::string lonig;
	std::string pasword;
	std::string name;
	std::string pathranomic;
	int id;
	int age;
	int access_rights;
public:
	Human();
	Human(std::string, std::string, std::string, std::string, int, int, int);
	std::string get_lonig();
	std::string get_pasword();
	std::string get_name();
	std::string get_pathranomic();
	int get_age();



};

