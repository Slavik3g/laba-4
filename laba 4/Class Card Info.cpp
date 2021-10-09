#include "Card_info.h"

int People::card_info::get_card_number()
{
	return card_number;
}

void People::card_info::set_card_numder(int card_number)
{
	this->card_number = card_number;
}

int People::card_info::get_cvv_code()
{
	return cvv_code;
}

void People::card_info::set_cvv_code(int cvv_code)
{
	this->cvv_code = cvv_code;
}