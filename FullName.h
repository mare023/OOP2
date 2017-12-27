#pragma once
#include <string>
#include <iostream>

class FullName
{
	std::string name;
	std::string surname;
public:
	FullName();
	FullName(std::string n, std::string s);
	std::string getName() const;
	std::string getSurname() const;
	bool operator==(const FullName& rhs);
	friend std::ostream& operator<<(std::ostream& out, FullName& fn);
};
