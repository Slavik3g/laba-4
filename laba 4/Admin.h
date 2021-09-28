#pragma once

class Admin : public Human
{
private:
	std::string post;
public:
	int get_id();
	int access_rights();
	void set_access_rights(int);
	void set_id(int);

};
