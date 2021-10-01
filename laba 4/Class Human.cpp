#include "Human.h"

People::Human::Human()
{
	this->age = 0;
	this->id = 0;
}

People::Human::Human(std::string login, std::string pasword, std::string name, std::string pathranomic, int age, int id)
{
	this->login = login;
	this->pasword = pasword;
	this->name = name;
	this->pathranomic = pathranomic;
	this->age = age;
	this->id = id;
}

std::string People::Human::get_login()
{
	return login;
}

std::string People::Human::get_pasword()
{
	return pasword;
}

std::string People::Human::get_name()
{
	return name;
}

std::string People::Human::get_pathranomic()
{
	return pathranomic;
}

void People::Human::set_login(std::string login)
{
	this->login = login;
}

void People::Human::set_pasword(std::string pasword)
{
	this->pasword = pasword;
}

void People::Human::set_name(std::string name)
{
	this->name = name;
}

void People::Human::set_pathranomic(std::string pathranomic)
{
	this->pathranomic = pathranomic;
}

void People::Human::set_age(int age)
{
	this->age = age;
} 

void People::Human::set_id(int id)
{
	this->id = id;
}

int People::Human::get_age()
{
	return age;
}

int People::Human::get_id()
{
	return id;
}

