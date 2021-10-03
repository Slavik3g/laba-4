#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

namespace People
{
	class Admin;
	class User;
}
int getintValue();
void chooseinstr();
void perfomance(std::vector <People::Admin>&, std::vector <People::User>&, int);
void addHuman(People::Admin&);
void addHuman(People::User&);
void addId(People::Admin&, std::vector <People::Admin>&, std::vector <People::User>);
void addId(People::User&, std::vector <People::Admin>&, std::vector <People::User>);
void deleteinstr();
void deletbyid(std::vector <People::Admin>&, std::vector <People::User>&);
void deletbylogin(std::vector <People::Admin>&, std::vector <People::User>&);
void deletehuman(std::vector <People::Admin>&, std::vector <People::User>&);
void changeinfoinstr();
void chageinfo(std::vector <People::Admin>&, std::vector <People::User>&);
void sortinstr();
void sortusers(std::vector <People::User>&);
void sortadmins(std::vector <People::Admin>&);
void addmoney(std::vector <People::User>&);


