#include "User.h"

void People::User::showinfo()
{
	std::cout << "���:" << get_name() << std::endl;
	std::cout << "�������:" << get_pathranomic() << std::endl;
	std::cout << "�����:" << get_login() << std::endl;
	std::cout << "������:" << get_pasword() << std::endl;
	std::cout << "���-�� �����:" << this->money << std::endl;
	std::cout << "����� �����:" << this->card_number << std::endl;
	std::cout << "Id:" << get_id() << std::endl;
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