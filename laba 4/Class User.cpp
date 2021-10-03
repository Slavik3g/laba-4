#include "User.h"

People::User::User(std::string login, std::string pasword, std::string name, std::string pathranomic, int age, int id, int card_number, int money) :Human(login, pasword, name, pathranomic, age, id)
{
	this->card_number = card_number;
	this->money = money;
}

People::User::User() : Human()
{
	this->money = 0;
	this->card_number = 0;
}

void People::User::showinfo()
{
	std::cout << "���:" << get_name() << std::endl;
	std::cout << "�������:" << get_pathranomic() << std::endl;
	std::cout << "�����:" << get_login() << std::endl;
	std::cout << "������:" << get_pasword() << std::endl;
	std::cout << "���-�� �����:" << this->money << std::endl;
	std::cout << "����� �����:" << this->card_number << std::endl;
	std::cout << "Id:" << get_id() << std::endl << std::endl;
}

int People::User::get_money()
{
	return money;
}

int People::User::get_card_number()
{
	return card_number;
}

void People::User::set_money(int money)
{
	this->money = money;
}

void People::User::set_card_number(int card_number)
{
	this->card_number = card_number;
}

void People::User::addmoney(int money)
{
	this->money += money;
}