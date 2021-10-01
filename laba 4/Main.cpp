#include "libraries.h"
#include "Admin.h"
#include "User.h"
int main()

{
	setlocale(0, "");
	srand(time(NULL));
	int choose;
	std:: vector <People::Admin> admins;
	std::vector <People::User> users;
	while (1)
	{
		chooseinstr();
		choose = getintValue();
		perfomance(admins, users, choose);
	}
	return 0;
}