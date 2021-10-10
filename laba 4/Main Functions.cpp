#include "libraries.h"
#include "Admin.h"
#include "User.h"

void chooseinstr()
{
	std::cout << "Введите 1 чтобы добавить администратора" << std::endl;
	std::cout << "Введите 2 чтобы добавить пользователя" << std::endl;
	std::cout << "Введите 3 чтобы удалить аккаунт" << std::endl;
	std::cout << "Введите 4 чтобы изменить информацию об аккаунте" << std::endl;
	std::cout << "Введите 5 чтобы вывести администаторов на экран" << std::endl;
	std::cout << "Введите 6 чтобы вывести ползователей на экран" << std::endl;
	std::cout << "Введите 7 чтобы отсортировать ползователей по фамилии" << std::endl;
	std::cout << "Введите 8 чтобы отсортировать администраторов по фамилии" << std::endl;
	std::cout << "Введите 9 чтобы добавить деньги на аккаунт" << std::endl;
}

int getintValue()
{
	int value = 0;

	while (true)
	{
		std::cin >> value;
		if (std::cin.peek() != '\n')
		{

			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("CLS");
			std::cout << "Введено неправильное число, повторите ввод" << std::endl;
		}
		else
		{
			return value;
		}
	}
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
	int temp_int, temp_int2;
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
	std::cout << "Введите cvv код:" << std::endl;
	temp_int2 = getintValue();
	user.set_card_info(temp_int, temp_int2);
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
	for (int i = 0; i < admins.size(); i++)
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
		if (x.get_login() == temp_str_login)
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

void changeinfoinstr()
{
	std::cout << "Введите 1 чтобы изменить имя" << std::endl;
	std::cout << "Введите 2 чтобы изменить фамилию" << std::endl;
	std::cout << "Введите 3 чтобы изменить логин" << std::endl;
	std::cout << "Введите 4 чтобы изменить пароль" << std::endl;
	std::cout << "Введите 5 чтобы изменить номер карты" << std::endl;
	std::cout << "Введите 6 чтобы изменить пост" << std::endl;
	std::cout << "Введите 7 чтобы изменить возраст" << std::endl;
}
void chageinfo(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	changeinfoinstr();
	int choose = getintValue();
	std::string temp, changed, pasword;
	if (choose == 1)
		temp = "имя";
	else if(choose == 2)
		temp = "фамилию";
	else if (choose == 3)
		temp = "логин";
	else if (choose == 4)
		temp = "пароль";
	else if (choose == 5)
		temp = "номер карты";
	else if (choose == 6)
		temp = "пост";
	else if (choose == 7)
		temp = "возраст";
	else
	{
		std::cout << "Такого выбора не существует" << std::endl;
		return;
	}
	std::cout << "Введите id человека которому хотите поменять " << temp << std::endl;
	int id = getintValue();
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].get_id() == id)
		{
			if (choose == 1)
			{
				std::cout << "Введите новое имя" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				admins[i].set_name(changed);
				return;
			}
			else if (choose == 2)
			{
				std::cout << "Введите новую фамилию" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				admins[i].set_pathranomic(changed);
				return;
			}
			else if (choose == 3)
			{
				std::cout << "Введите новый логин" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				admins[i].set_login(changed);
				return;
			}
			else if (choose == 4)
			{
				std::cout << "Введите новый пароль" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				admins[i].set_pasword(changed);
				return;
			}
			else if (choose == 5)
			{
				std::cout << "У администратора нельзя нет номера карты" << std::endl;
				return;
			}
			else if (choose == 6)
			{
				std::cout << "Введите новый пост" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				admins[i].set_post(changed);
				return;
			}
			else if (choose == 7)
			{
				std::cout << "Введите новый возраст" << std::endl;
				int new_age = getintValue();
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				admins[i].set_age(new_age);
				return;
			}
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_id() == id)
		{
			if (choose == 1)
			{
				std::cout << "Введите новое имя" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				users[i].set_name(changed);
				return;
			}
			else if (choose == 2)
			{
				std::cout << "Введите новую фамилию" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				users[i].set_pathranomic(changed);
				return;
			}
			else if (choose == 3)
			{
				std::cout << "Введите новый логин" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				users[i].set_login(changed);
				return;
			
			}
			
			else if (choose == 4)
			{
				std::cout << "Введите новый пароль" << std::endl;
				std::cin >> changed;
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				users[i].set_pasword(changed);
				return;
			}
			else if (choose == 5)
			{
				std::cout << "Введите новый номер карты" << std::endl;
				int new_card_number = getintValue();
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				users[i].set_card_number(new_card_number);
				return;
			}
			else if (choose == 6)
			{
				std::cout << "У пользователья нельзя нет поста" << std::endl;
				return;
			}
			else if (choose == 7)
			{
				std::cout << "Введите новый возраст" << std::endl;
				int new_age = getintValue();
				std::cout << "Введите пароль от аккаунта" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "Неверный пароль" << std::endl;
					return;
				}
				users[i].set_age(new_age);
				return;
			}
		}
	}
	std::cout << "Не найдено человека с таким id" << std::endl;	
}

void sortinstr()
{
	std::cout << "Введите 1 чтобы отсортировать по убыванию" << std::endl;
	std::cout << "Введите 2 чтобы отсортировать по возрастанию" << std::endl;
}
void sortusers(std::vector <People::User>& users)
{
	sortinstr();
	int choose = getintValue();
	if (choose == 1)
	{
		for (int k = 0; k < users.size() - 1; k++)
		{
			for (int l = 0; l < users.size() - k - 1; l++)
			{
				if (users[l].get_pathranomic() > users[l + 1].get_pathranomic())
				{
					People::User d = users[l];
					users[l] = users[l + 1];
					users[l + 1] = d;
				}
			}
		}
		return;
	}
	else if (choose == 2)
	{
		for (int k = 0; k < users.size() - 1; k++)
		{
			for (int l = 0; l < users.size() - k - 1; l++)
			{
				if (users[l].get_pathranomic() < users[l + 1].get_pathranomic())
				{
					People::User d = users[l];
					users[l] = users[l + 1];
					users[l + 1] = d;
				}
			}
		}
		return;
	}
	else
		std::cout << "Такого выбора вам не давали" << std::endl;
}

void sortadmins(std::vector <People::Admin>& admins)
{
	sortinstr();
	int choose = getintValue();
	if (choose == 1)
	{
		for (int k = 0; k < admins.size() - 1; k++)
		{
			for (int l = 0; l < admins.size() - k - 1; l++)
			{
				if (admins[l].get_pathranomic() > admins[l + 1].get_pathranomic())
				{
					People::Admin d = admins[l];
					admins[l] = admins[l + 1];
					admins[l + 1] = d;
				}
			}
		}
		return;
	}
	else if (choose == 2)
	{
		for (int k = 0; k < admins.size() - 1; k++)
		{
			for (int l = 0; l < admins.size() - k - 1; l++)
			{
				if (admins[l].get_pathranomic() < admins[l + 1].get_pathranomic())
				{
					People::Admin d = admins[l];
					admins[l] = admins[l + 1];
					admins[l + 1] = d;
				}
			}
		}
		return;
	}
	else
		std::cout << "Такого выбора вам не давали" << std::endl;
}

void addmoney(std::vector <People::User>& users)
{
	std::cout << "Введите id пользователя которому хотите добавить денег" << std::endl;
	int id = getintValue();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_id() == id)
		{
			std::cout << "Введите сумму которую хотите добавить" << std::endl;
			int money = getintValue();
			std::cout << "Посылаем запрос в банк" << std::endl;
			Sleep(3000);
			int bank = rand();
			if (bank % 3 == 0)
			{
				std::cout << "В операции отказано банком" << std::endl;
				return;
			}
			else
			{
				std::cout << "Оплата прошла, деньги добавлены на аккаунт" << std::endl;
				users[i].addmoney(money);
				return;
			}

		}
	}
	std::cout << "Пользователя с таким id не найдено" << std::endl;
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
		if (!admins.size() && !users.size())
		{
			std::cout << "Нет добавленых аккаунтов" << std::endl;
			break;
		}
		deletehuman(admins, users);
		break;
	case 4:
		system("CLS");
		if (!admins.size() && !users.size())
		{
			std::cout << "Нет добавленых аккаунтов" << std::endl;
			break;
		}
		chageinfo(admins, users);
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
		if (!users.size())
		{
			std::cout << "Нет добавленых пользователей" << std::endl;
			break;
		}
		sortusers(users);
		break;
	case 8:
		system("CLS");
		if (!admins.size())
		{
			std::cout << "Нет добавленых администраторов" << std::endl;
			break;
		}
		sortadmins(admins);
		break;
	case 9:
		system("CLS");
		if (!users.size())
		{
			std::cout << "Нет добавленых пользователей" << std::endl;
			break;
		}
		addmoney(users);
		break;
	default:
		break;
	}
}