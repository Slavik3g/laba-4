#pragma once
namespace People
{
	class card_info
	{
	private:
		int card_number;
		int cvv_code;
	public:
		int get_card_number();
		void set_card_numder(int);
		int get_cvv_code();
		void set_cvv_code(int);
	};
}