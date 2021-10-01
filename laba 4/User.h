
#include "Human.h"

namespace People
{
	class User : public Human
	{
	private:
		int money;
		int card_number;
	public:
		int get_money();
		int get_card_number();
		void set_money(int);
		void set_card_number(int);
		void showinfo();
		/*friend std::istream& operator>> (std::istream&, const User&);*/
	};
}