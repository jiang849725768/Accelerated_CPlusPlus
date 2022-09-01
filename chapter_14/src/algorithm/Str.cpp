#include "Str.h"

#include <cctype>
#include <iostream>

std::istream& operator>>(std::istream& is, Str& s)
{
	//delete existed value
	s.data->clear();

	//read char in order, ignore space char before
	char c;
	while (is.get(c) && isspace(c)); //only judge loop condition
	//repeat reading until meet a space char
	if (is)
	{
		do
		{
			s.data->push_back(c);
		}
		while (is.get(c) && !isspace(c));

		//put the space char back to the in stream
		if (is)
			is.unget();
	}

	return is;
}


Str::Str(): data(new Vec<char>)
{
}

Str::Str(size_type n, char c): data(new Vec<char>(n, c))
{
}

Str::Str(const char* cp): data(new Vec<char>)
{
	std::copy_n(cp, std::strlen(cp), std::back_inserter(*data));
}

Str::size_type Str::size() const
{
	return data->size();
}

char& Str::operator[](size_type i)
{
	return (*data)[i];
}

const char& Str::operator[](size_type i) const
{
	return (*data)[i];
}

Str& Str::operator+=(const Str& s)
{
	data.make_unique();
	std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
	return *this;
}

const char* Str::ec_str() const
{
	static auto ch_str(data);
	ch_str.make_unique();
	ch_str->push_back('\0');
	//std::cout << ch_str->begin() << std::endl;
	return ch_str->begin();
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
	for (const char i : s)
		os << i;
	return os;
}

Str operator+(const Str& str, const Str& str1)
{
	Str str2(str);
	return str2 += str1;
}
