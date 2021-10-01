#include "libraries.h"
#include "Admin.h"
#include "User.h"

int getintValue()
{
	int value = 0;

	while (true)
	{
		std::cin >> value;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			system("CLS");
			std::cout << "Введено неправильное число, повторите ввод" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

void chooseinstr()
{
	std::cout << "Введите 1 чтобы добавить администратора" << std::endl;
	std::cout << "Введите 2 чтобы добавить пользователя" << std::endl;
	std::cout << "Введите 3 чтобы удалить аккаунт" << std::endl;
	std::cout << "Введите 4 чтобы изменить информацию об аккаунте" << std::endl;
	std::cout << "Введите 5 чтобы вывести администаторов на экран" << std::endl;
	std::cout << "Введите 6 чтобы вывести ползователей на экран" << std::endl;
	std::cout << "Введите 7 чтобы отсортировать ползователей" << std::endl;
	std::cout << "Введите 8 чтобы отсортировать администраторов" << std::endl;
	std::cout << "Введите 9 чтобы добавить деньги на аккаунт" << std::endl;
}

void addHuman(People::Admin &admin)
{
	std::string temp_str;
	int temp_int;
	std::cout << "Введите имя:" << std::endl;
	std::cin >> temp_str;
	admin.set_name(temp_str);
	std::cout << "Введите фамилию:" << std::endl;
	std::cin >> temp_str;
	admin.set_pathranomic(temp_str);
	std::cout << "Введите логин:" << std::endl;
	std::cin >> temp_str;
	admin.set_login(temp_str);
	std::cout << "Введите пароль:" << std::endl;
	std::cin >> temp_str;
	admin.set_pasword(temp_str);
	std::cout << "Введите возраст:" << std::endl;
	temp_int = getintValue();
	admin.set_age(temp_int);
	std::cout << "Введите пост:" << std::endl;
	std::cin >> temp_str;
	admin.set_post(temp_str);
}

void addHuman(People::User& user)
{
	std::string temp_str;
	int temp_int;
	std::cout << "Введите имя:" << std::endl;
	std::cin >> temp_str;
	user.set_name(temp_str);
	std::cout << "Введите фамилию:" << std::endl;
	std::cin >> temp_str;
	user.set_pathranomic(temp_str);
	std::cout << "Введите логин:" << std::endl;
	std::cin >> temp_str;
	user.set_login(temp_str);
	std::cout << "Введите пароль:" << std::endl;
	std::cin >> temp_str;
	user.set_pasword(temp_str);
	std::cout << "Введите возраст:" << std::endl;
	temp_int = getintValue();
	user.set_age(temp_int);
	std::cout << "Введите номер карты:" << std::endl;
	temp_int = getintValue();
	user.set_card_number(temp_int);
	std::cout << "Введите количество денег которые хотите добавить:" << std::endl;
	temp_int = getintValue();
	user.set_money(temp_int);
}

void addId(People::Admin& admin, std::vector <People::Admin>& admins, std::vector <People::User> users)
{
	srand(time(NULL));
	bool bad_rand = true;
	int id = 0;
	while (bad_rand == true)
	{
		bad_rand = false;
		id = rand();
		for (auto& x : admins)
		{
			if (x.get_id() == id)
			{
				bad_rand = true;
				break;
			}
		}
		if (bad_rand == true)
			continue;
		for (auto& x : users)
		{
			if (x.get_id() == id)
			{
				bad_rand = true;
				break;
			}
		}
		admin.set_id(id);
	}
}

void addId(People::User& user, std::vector <People::Admin>& admins, std::vector <People::User> users)
{
	srand(time(NULL));
	bool bad_rand = true;
	int id = 0;
	while (bad_rand == true)
	{
		bad_rand = false;
		id = rand();
		for (auto& x : admins)
		{
			if (x.get_id() == id)
			{
				bad_rand = true;
				break;
			}
		}
		if (bad_rand == true)
			continue;
		for (auto& x : users)
		{
			if (x.get_id() == id)
			{
				bad_rand = true;
				break;
			}
		}
		user.set_id(id);
	}
}

void deleteinstr()
{
	std::cout << "Введите 1 если хотите удалить по id:" << std::endl;
	std::cout << "Введите 2 если хотите удалить по логину:" << std::endl;
}

void deletbyid(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	std::cout << "Введите id человека которого хотите удалить:" << std::endl;
	int id = getintValue();
	std::string temp_str;
	for (int i=0; i<admins.size();i++)
	{
		if (admins[i].get_id() == id)
		{
			std::cout << "Введите пароль от аккаунта:" << std::endl;
			std::cin >> temp_str;
			if (admins[i].get_pasword() == temp_str)
			{
				admins.erase(admins.begin() + i);
				std::cout << "Пользователь удалён" << std::endl;
				return;
			}
			else
			{
				std::cout << "Неверный пароль от аккаунта:" << std::endl;
			}
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_id() == id)
		{
			std::cout << "Введите пароль от аккаунта:" << std::endl;
			std::cin >> temp_str;
			if (users[i].get_pasword() == temp_str)
			{
				users.erase(users.begin() + i);
				std::cout << "Пользователь удалён" << std::endl;
				return;
			}
			else
			{
				std::cout << "Неверный пароль от аккаунта:" << std::endl;
			}
		}
	}
	std::cout << "Не найдено пользователя с таким id" << std::endl;

}

void deletbylogin(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	std::cout << "Введите логин человека которого хотите удалить:" << std::endl;
	std::string temp_str_login;
	std::cin >> temp_str_login;
	int cout = 0;
	for (auto& x : admins)
	{
		if(x.get_login() == temp_str_login)
			cout++;
	}
	for (auto& x : users)
	{
		if (x.get_login() == temp_str_login)
			cout++;
	}
	if (cout == 0)
	{
		std::cout << "Не найдено пользователей с таким логином" << std::endl;
		return;
	}
	std::cout << "Найдено " << cout << " пользователей с таким логином. Удалить всех? (Введите 1 если да)" << std::endl;
	int choose = getintValue();
	if (choose != 1)
	{
		std::cout << "В данном случае удаляйте по id" << std::endl;
		return;
	}
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].get_login() == temp_str_login)
		{
			admins.erase(admins.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_login() == temp_str_login)
		{
			users.erase(users.begin() + i);
			i--;
		}
	}
	std::cout << "Пользователи удалены" << std::endl;

}

void deletehuman(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	deleteinstr();
	int choose = getintValue();
	if (choose == 1)
	{
		deletbyid(admins, users);
	}
	else if (choose == 2)
	{
		deletbylogin(admins, users);
	}
	else
	{
		std::cout << "Вы ввели херовое число" << std::endl;
	}
}
void perfomance(std::vector <People::Admin> &admins, std::vector <People::User>& users, int choose)
{
	switch (choose)
	{
	case 1:
		system("CLS");
		admins.push_back(People::Admin());
		addHuman(admins[admins.size() - 1]);
		addId(admins[admins.size() - 1], admins, users);
		break;
	case 2:
		system("CLS");
		users.push_back(People::User());
		addHuman(users[users.size() - 1]);
		addId(users[users.size() - 1], admins, users);
		break;
	case 3:
		system("CLS");
		deletehuman(admins, users);
		break;
	case 4:
		system("CLS");
		chageinfo();
		break;
	case 5:
		system("CLS");
		if (!admins.size())
		{
			std::cout << "Нет добавленых администраторов" << std::endl;
			break;
		}
		for (auto& x : admins)
		{
			x.showinfo();
		}
		break;
	case 6:
		system("CLS");
		if (!users.size())
		{
			std::cout << "Нет добавленых пользователей" << std::endl;
			break;
		}
		for (auto& x : users)
		{
			x.showinfo();
		}
		break;
	case 7:
		system("CLS");

	case 8:
		system("CLS");
	default:
		break;
	}
}