#include "User.h"

void User::showinfo()
{
	std::cout << "Имя:" << get_name() << std::endl;
	std::cout << "Фамилия:" << get_pathranomic() << std::endl;
	std::cout << "Логин:" << get_login() << std::endl;
	std::cout << "Пароль:" << get_pasword() << std::endl;
	std::cout << "Кол-во денег:" << this->money << std::endl;
	std::cout << "Номер карты:" << this->card_number << std::endl;
}