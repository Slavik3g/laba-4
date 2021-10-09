#include "Admin.h"

People::Admin::Admin(std::string post, std::string login, std::string pasword, std::string name, std::string pathranomic, int age, int id):Human(login, pasword, name, pathranomic, age, id)
{
	this->post = post;
}

People::Admin::Admin()
{
}

void People::Admin::set_id(int id)
{
	this->id = id;
}

void People::Admin::set_post(std::string post)
{
	this->post = post;
}

std::string People::Admin::get_post()
{
	return post;
}

void People::Admin::showinfo()
{
	std::cout << "Имя:" << get_name() << std::endl;
	std::cout << "Фамилия:" << get_pathranomic() << std::endl;
	std::cout << "Логин:" << get_login() << std::endl;
	std::cout << "Пароль:" << get_pasword() << std::endl;
	std::cout << "Должность:" << this->post << std::endl;
	std::cout << "Id:" << get_id() << std::endl << std::endl;
}
