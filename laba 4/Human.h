#pragma once
#include "libraries.h"

class Human
{
private:
	std::string lonig;
	std::string pasword;
	std::string name;
	std::string pathranomic;
	int age;
protected:
	int id;
	int access_rights;
public:
	Human();
	Human(std::string, std::string, std::string, std::string, int, int, int);
	std::string get_lonig();
	std::string get_pasword();
	std::string get_name();
	std::string get_pathranomic();
	void set_login(std::string);
	void set_pasword(std::string);
	void set_name(std::string);
	void set_pathranomic(std::string);
	void set_age(int);



};

