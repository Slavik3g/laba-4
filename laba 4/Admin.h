#pragma once
#include "Human.h"

class Admin : public Human
{
private:
	std::string post;
public:
	Admin();
	Admin(std::string, std::string, std::string, std::string, std::string, int, int);
	void set_post(std::string);
	std::string get_post();
	void set_id(int);
	void showinfo() override;
};
