#include "libraries.h"
#include "Admin.h"
#include "User.h"

void chooseinstr()
{
	std::cout << "������� 1 ����� �������� ��������������" << std::endl;
	std::cout << "������� 2 ����� �������� ������������" << std::endl;
	std::cout << "������� 3 ����� ������� �������" << std::endl;
	std::cout << "������� 4 ����� �������� ���������� �� ��������" << std::endl;
	std::cout << "������� 5 ����� ������� �������������� �� �����" << std::endl;
	std::cout << "������� 6 ����� ������� ������������ �� �����" << std::endl;
	std::cout << "������� 7 ����� ������������� ������������ �� �������" << std::endl;
	std::cout << "������� 8 ����� ������������� ��������������� �� �������" << std::endl;
	std::cout << "������� 9 ����� �������� ������ �� �������" << std::endl;
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
			std::cout << "������� ������������ �����, ��������� ����" << std::endl;
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
	std::cout << "������� ���:" << std::endl;
	std::cin >> temp_str;
	admin.set_name(temp_str);
	std::cout << "������� �������:" << std::endl;
	std::cin >> temp_str;
	admin.set_pathranomic(temp_str);
	std::cout << "������� �����:" << std::endl;
	std::cin >> temp_str;
	admin.set_login(temp_str);
	std::cout << "������� ������:" << std::endl;
	std::cin >> temp_str;
	admin.set_pasword(temp_str);
	std::cout << "������� �������:" << std::endl;
	temp_int = getintValue();
	admin.set_age(temp_int);
	std::cout << "������� ����:" << std::endl;
	std::cin >> temp_str;
	admin.set_post(temp_str);
} 
void addHuman(People::User& user)
{
	std::string temp_str;
	int temp_int, temp_int2;
	std::cout << "������� ���:" << std::endl;
	std::cin >> temp_str;
	user.set_name(temp_str);
	std::cout << "������� �������:" << std::endl;
	std::cin >> temp_str;
	user.set_pathranomic(temp_str);
	std::cout << "������� �����:" << std::endl;
	std::cin >> temp_str;
	user.set_login(temp_str);
	std::cout << "������� ������:" << std::endl;
	std::cin >> temp_str;
	user.set_pasword(temp_str);
	std::cout << "������� �������:" << std::endl;
	temp_int = getintValue();
	user.set_age(temp_int);
	std::cout << "������� ����� �����:" << std::endl;
	temp_int = getintValue();
	std::cout << "������� cvv ���:" << std::endl;
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
	std::cout << "������� 1 ���� ������ ������� �� id:" << std::endl;
	std::cout << "������� 2 ���� ������ ������� �� ������:" << std::endl;
}
void deletbyid(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	std::cout << "������� id �������� �������� ������ �������:" << std::endl;
	int id = getintValue();
	std::string temp_str;
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].get_id() == id)
		{
			std::cout << "������� ������ �� ��������:" << std::endl;
			std::cin >> temp_str;
			if (admins[i].get_pasword() == temp_str)
			{
				admins.erase(admins.begin() + i);
				std::cout << "������������ �����" << std::endl;
				return;
			}
			else
			{
				std::cout << "�������� ������ �� ��������:" << std::endl;
			}
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_id() == id)
		{
			std::cout << "������� ������ �� ��������:" << std::endl;
			std::cin >> temp_str;
			if (users[i].get_pasword() == temp_str)
			{
				users.erase(users.begin() + i);
				std::cout << "������������ �����" << std::endl;
				return;
			}
			else
			{
				std::cout << "�������� ������ �� ��������:" << std::endl;
			}
		}
	}
	std::cout << "�� ������� ������������ � ����� id" << std::endl;

}
void deletbylogin(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	std::cout << "������� ����� �������� �������� ������ �������:" << std::endl;
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
		std::cout << "�� ������� ������������� � ����� �������" << std::endl;
		return;
	}
	std::cout << "������� " << cout << " ������������� � ����� �������. ������� ����? (������� 1 ���� ��)" << std::endl;
	int choose = getintValue();
	if (choose != 1)
	{
		std::cout << "� ������ ������ �������� �� id" << std::endl;
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
	std::cout << "������������ �������" << std::endl;

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
		std::cout << "�� ����� ������� �����" << std::endl;
	}
}

void changeinfoinstr()
{
	std::cout << "������� 1 ����� �������� ���" << std::endl;
	std::cout << "������� 2 ����� �������� �������" << std::endl;
	std::cout << "������� 3 ����� �������� �����" << std::endl;
	std::cout << "������� 4 ����� �������� ������" << std::endl;
	std::cout << "������� 5 ����� �������� ����� �����" << std::endl;
	std::cout << "������� 6 ����� �������� ����" << std::endl;
	std::cout << "������� 7 ����� �������� �������" << std::endl;
}
void chageinfo(std::vector <People::Admin>& admins, std::vector <People::User>& users)
{
	changeinfoinstr();
	int choose = getintValue();
	std::string temp, changed, pasword;
	if (choose == 1)
		temp = "���";
	else if(choose == 2)
		temp = "�������";
	else if (choose == 3)
		temp = "�����";
	else if (choose == 4)
		temp = "������";
	else if (choose == 5)
		temp = "����� �����";
	else if (choose == 6)
		temp = "����";
	else if (choose == 7)
		temp = "�������";
	else
	{
		std::cout << "������ ������ �� ����������" << std::endl;
		return;
	}
	std::cout << "������� id �������� �������� ������ �������� " << temp << std::endl;
	int id = getintValue();
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].get_id() == id)
		{
			if (choose == 1)
			{
				std::cout << "������� ����� ���" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				admins[i].set_name(changed);
				return;
			}
			else if (choose == 2)
			{
				std::cout << "������� ����� �������" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				admins[i].set_pathranomic(changed);
				return;
			}
			else if (choose == 3)
			{
				std::cout << "������� ����� �����" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				admins[i].set_login(changed);
				return;
			}
			else if (choose == 4)
			{
				std::cout << "������� ����� ������" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				admins[i].set_pasword(changed);
				return;
			}
			else if (choose == 5)
			{
				std::cout << "� �������������� ������ ��� ������ �����" << std::endl;
				return;
			}
			else if (choose == 6)
			{
				std::cout << "������� ����� ����" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				admins[i].set_post(changed);
				return;
			}
			else if (choose == 7)
			{
				std::cout << "������� ����� �������" << std::endl;
				int new_age = getintValue();
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (admins[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
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
				std::cout << "������� ����� ���" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				users[i].set_name(changed);
				return;
			}
			else if (choose == 2)
			{
				std::cout << "������� ����� �������" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				users[i].set_pathranomic(changed);
				return;
			}
			else if (choose == 3)
			{
				std::cout << "������� ����� �����" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				users[i].set_login(changed);
				return;
			
			}
			
			else if (choose == 4)
			{
				std::cout << "������� ����� ������" << std::endl;
				std::cin >> changed;
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				users[i].set_pasword(changed);
				return;
			}
			else if (choose == 5)
			{
				std::cout << "������� ����� ����� �����" << std::endl;
				int new_card_number = getintValue();
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				users[i].set_card_number(new_card_number);
				return;
			}
			else if (choose == 6)
			{
				std::cout << "� ������������� ������ ��� �����" << std::endl;
				return;
			}
			else if (choose == 7)
			{
				std::cout << "������� ����� �������" << std::endl;
				int new_age = getintValue();
				std::cout << "������� ������ �� ��������" << std::endl;
				std::cin >> pasword;
				if (users[i].get_pasword() != pasword)
				{
					std::cout << "�������� ������" << std::endl;
					return;
				}
				users[i].set_age(new_age);
				return;
			}
		}
	}
	std::cout << "�� ������� �������� � ����� id" << std::endl;	
}

void sortinstr()
{
	std::cout << "������� 1 ����� ������������� �� ��������" << std::endl;
	std::cout << "������� 2 ����� ������������� �� �����������" << std::endl;
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
		std::cout << "������ ������ ��� �� ������" << std::endl;
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
		std::cout << "������ ������ ��� �� ������" << std::endl;
}

void addmoney(std::vector <People::User>& users)
{
	std::cout << "������� id ������������ �������� ������ �������� �����" << std::endl;
	int id = getintValue();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_id() == id)
		{
			std::cout << "������� ����� ������� ������ ��������" << std::endl;
			int money = getintValue();
			std::cout << "�������� ������ � ����" << std::endl;
			Sleep(3000);
			int bank = rand();
			if (bank % 3 == 0)
			{
				std::cout << "� �������� �������� ������" << std::endl;
				return;
			}
			else
			{
				std::cout << "������ ������, ������ ��������� �� �������" << std::endl;
				users[i].addmoney(money);
				return;
			}

		}
	}
	std::cout << "������������ � ����� id �� �������" << std::endl;
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
			std::cout << "��� ���������� ���������" << std::endl;
			break;
		}
		deletehuman(admins, users);
		break;
	case 4:
		system("CLS");
		if (!admins.size() && !users.size())
		{
			std::cout << "��� ���������� ���������" << std::endl;
			break;
		}
		chageinfo(admins, users);
		break;
	case 5:
		system("CLS");
		if (!admins.size())
		{
			std::cout << "��� ���������� ���������������" << std::endl;
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
			std::cout << "��� ���������� �������������" << std::endl;
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
			std::cout << "��� ���������� �������������" << std::endl;
			break;
		}
		sortusers(users);
		break;
	case 8:
		system("CLS");
		if (!admins.size())
		{
			std::cout << "��� ���������� ���������������" << std::endl;
			break;
		}
		sortadmins(admins);
		break;
	case 9:
		system("CLS");
		if (!users.size())
		{
			std::cout << "��� ���������� �������������" << std::endl;
			break;
		}
		addmoney(users);
		break;
	default:
		break;
	}
}