#include "User.h"

void User::showinfo()
{
	std::cout << "���:" << get_name() << std::endl;
	std::cout << "�������:" << get_pathranomic() << std::endl;
	std::cout << "�����:" << get_login() << std::endl;
	std::cout << "������:" << get_pasword() << std::endl;
	std::cout << "���-�� �����:" << this->money << std::endl;
	std::cout << "����� �����:" << this->card_number << std::endl;
}