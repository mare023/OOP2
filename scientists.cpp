#include "Scientist.h"

/*
@TODO: Complete the Scientist class definition:
- add implementation for constructor with parameters
- add implementation for operator ==
- add implementation for operator <
- add implementation for get methods
*/

Scientist::Scientist(FullName name, int i)
{
	this->scientist = name;
	this->id = i;
}

bool Scientist::operator==(const Scientist & rhs)
{
	return this->id == rhs.id && this->scientist == rhs.scientist;
}

bool Scientist::operator<(const Scientist rhs)
{
	return this->id < rhs.id;
}

std::ostream & Scientist::operator<<(std::ostream & out)
{
	out << this->id << " " <<this->getFullName().getName() << " " << this->getFullName().getSurname() << std::endl;
	return out;
}

FullName Scientist::getFullName() const
{
	return scientist;
}

int Scientist::getId() const
{
	return id;
}
