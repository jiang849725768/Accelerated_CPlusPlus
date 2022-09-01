#include "Str.h"

#include <cctype>
#include <iostream>

std::istream& operator>>(std::istream& is, Str& s)
{
	//delete existed value
	s.data.clear();

	//read char in order, ignore space char before
	char c;
	while (is.get(c) && isspace(c)); //only judge loop condition
	//repeat reading until meet a space char
	if (is)
	{
		do
		{
			s.data.push_back(c);
		}
		while (is.get(c) && !isspace(c));

		//put the space char back to the in stream
		if (is)
			is.unget();
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
	for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

Str operator+(const Str& str, const Str& str1)
{
	Str str2(str);
	return str2 += str1;
}
