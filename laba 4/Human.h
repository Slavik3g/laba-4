#pragma once
#include "libraries.h"

class Human
{
private:
	std::string login;
	std::string pasword;
	std::string name;
	std::string pathranomic;
	int age;
protected:
	int id;
public:
	virtual void showinfo() = 0;
	Human();
	Human(std::string, std::string, std::string, std::string, int, int);
	std::string get_login();
	std::string get_pasword();
	std::string get_name();
	std::string get_pathranomic();
	int get_age();
	int get_id();
	void set_login(std::string);
	void set_pasword(std::string);
	void set_name(std::string);
	void set_pathranomic(std::string);
	void set_age(int);
	void set_id(int);
};

