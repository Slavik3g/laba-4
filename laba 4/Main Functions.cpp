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
			std::cout << "¬ведено неправильное число, повторите ввод" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

void chooseinstr()
{
	std::cout << "¬ведите 1 чтобы добавить элемент" << std::endl;
	std::cout << "¬ведите 2 чтобы удалить элемент по значению" << std::endl;
	std::cout << "¬ведите 3 чтобы удалить элемент по индексу" << std::endl;
	std::cout << "¬ведите 4 чтобы вывести массив на экран" << std::endl;
	std::cout << "¬ведите 5 чтобы отсортировать массив" std::endl;
	std::cout << "¬ведите 6 чтобы выйти из программы" << std::endl;
}

void performance(Array& Nums, int choose)
{

}