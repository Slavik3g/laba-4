#pragma once
#include "Human.h"

class User : public Human
{
private:
	int money;
	int card_number;
public:
	int get_money();
	int get_card_number();
	void set_money();
	void set_card_number();
	void showinfo() override;

};
