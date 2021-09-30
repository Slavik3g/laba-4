#pragma once
#include "Human.h"

class Admin : public Human
{
private:
	std::string post;
public:
	int get_id();
	int access_rights();
	void set_post();
	void get_post();
	void set_access_rights(int);
	void set_id(int);

};
