#include "libraries.h"

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
			std::cout << "������� ������������ �����, ��������� ����" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

void chooseinstr()
{
	std::cout << "������� 1 ����� �������� �������" << std::endl;
	std::cout << "������� 2 ����� ������� ������� �� ��������" << std::endl;
	std::cout << "������� 3 ����� ������� ������� �� �������" << std::endl;
	std::cout << "������� 4 ����� ������� ������ �� �����" << std::endl;
	std::cout << "������� 5 ����� ������������� ������" std::endl;
	std::cout << "������� 6 ����� ����� �� ���������" << std::endl;
}

void performance(Array& Nums, int choose)
{

}