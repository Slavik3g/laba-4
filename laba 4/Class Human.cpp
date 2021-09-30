#include "Human.h"

Human::Human()
{
	this->age = 0;
	this->id = 0;
}

Human::Human(std::string login, std::string pasword, std::string name, std::string pathranomic, int age, int id)
{
	this->login = login;
	this->pasword = pasword;
	this->name = name;
	this->pathranomic = pathranomic;
	this->age = age;
	this->id = id;
}

std::string Human::get_login()
{
	return this->get_login();
}

std::string Human::get_pasword()
{
	return this->get_pasword();
}

std::string Human::get_name()
{
	return this->get_name();
}

std::string Human::get_pathranomic()
{
	return this->get_pathranomic();
}

void Human::set_login(std::string login)
{
	this->login = login;
}

void Human::set_pasword(std::string pasword)
{
	this->pasword = pasword;
}

void Human::set_name(std::string name)
{
	this->name = name;
}

void Human::set_pathranomic(std::string pathranomic)
{
	this->pathranomic = pathranomic;
}

void Human::set_age(int age)
{
	this->age = age;
} 

void Human::set_id(int id)
{
	this->id = id;
}

int Human::get_age()
{
	return this->age;
}

int Human::get_id()
{
	return this->id;
}