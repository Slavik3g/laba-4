#include "libraries.h"
#include "Human.h"
#include "Admin.h"
#include "User.h"


int main()
{
	setlocale(0, "");
	int choose;
	Admin admins;
	User users;
	while (1)
	{
		chooseinstr();
		choose = getintValue();
		perfomance(, choose);
	}
	return 0;
}