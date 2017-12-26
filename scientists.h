#pragma once

#include "FullName.h"
#include <iostream>


class Scientist
{
	FullName scientist;
	int id;

public:
	Scientist(FullName name, int i);
	bool operator==(const Scientist& rhs);
	bool operator<(const Scientist rhs);
	std::ostream& operator<<(std::ostream& in);
	FullName getFullName() const;
	int getId() const;
};

