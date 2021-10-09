#include "User.h"

People::User::User(std::string login, std::string pasword, std::string name, std::string pathranomic, int age, int id, int card_number, int money, int cvv_code) :Human(login, pasword, name, pathranomic, age, id)
{
	this->money = money;
	this->inf.set_card_numder(card_number);
	this->inf.set_cvv_code(cvv_code);
}

People::User::User() : Human()
{
	this->money = 0;
	inf.set_card_numder(0);
	inf.set_cvv_code(0);
}

void People::User::showinfo()
{
	std::cout << "Имя:" << get_name() << std::endl;
	std::cout << "Фамилия:" << get_pathranomic() << std::endl;
	std::cout << "Логин:" << get_login() << std::endl;
	std::cout << "Пароль:" << get_pasword() << std::endl;
	std::cout << "Кол-во денег:" << this->money << std::endl;
	std::cout << "Номер карты:" << inf.get_card_number() << std::endl;
	std::cout << "Id:" << get_id() << std::endl << std::endl;
}

int People::User::get_money()
{
	return money;
}

void People::User::set_money(int money)
{
	this->money = money;
}

void People::User::addmoney(int money)
{
	this->money += money;
}

void People::User::set_card_info(int card_num, int cvv_code)
{
	inf.set_card_numder(card_num);
	inf.set_cvv_code(cvv_code);
}

void People::User::set_ccv_code(int cvv_code)
{
	inf.set_cvv_code(cvv_code);
}

void People::User::set_card_number(int card_number)
{
	inf.set_card_numder(card_number);
}