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


