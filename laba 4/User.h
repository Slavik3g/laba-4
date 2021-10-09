#include "Human.h"
#include "Card_info.h"

namespace People
{
	class User : public Human
	{
	private:
		int money;
		card_info inf;
	public:
		User();
		User(std::string, std::string, std::string, std::string, int, int, int, int, int);
		void set_card_info(int, int);
		void set_ccv_code(int);
		void set_card_number(int);
		int get_money();
		void set_money(int);
		void showinfo();
		void addmoney(int);
	};
}