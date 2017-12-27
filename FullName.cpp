#include "FullName.h"

using namespace std;

/*
@TODO: Complete the FullName class definition:
- add implementation for constructor with parameters
- add implementation for operator ==
- add implementation for get methods
*/

FullName::FullName()
{
}

FullName::FullName(std::string n, std::string s)
{
	this->name = n;
	this->surname = s;
}

std::string FullName::getName() const
{
	return name;
}

std::string FullName::getSurname() const
{
	return surname;
}

bool FullName::operator==(const FullName & rhs)
{
	return this->name == rhs.name & this->surname == rhs.surname;
}

std::ostream & operator<<(std::ostream & out, FullName & fn)
{

	out << fn.name << " " << fn.surname << std::endl;
	return out;
}
