#pragma once
#include <iostream>

#include "Core.h"


class Student_info
{
public:
	Student_info();

	explicit Student_info(std::istream& is);
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	~Student_info();

	std::istream& read(std::istream&);

	std::string name() const;

	double grade() const;

	bool valid() const;

	bool great() const;

	bool pass() const;

	std::string letter_grade() const;

	static bool compare(const Student_info& s1, const Student_info& s2);

private:
	Core* cp;
};
