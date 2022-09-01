#pragma once

#include <iterator>

#include "Vec.h"

class Str
{
	friend std::istream& operator>>(std::istream& is, Str& s);
public:
	using size_type = Vec<char>::size_type;

	//default construct function
	Str() = default;

	//generate a Str with n of c
	Str(size_type n, char c): data(n, c)
	{
	}

	//generate a Str with char array end with '\0'
	Str(const char* cp)
	{
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}

	//generate a Str using content between iterator b and e
	template <class In>
	Str(In b, In e)
	{
		data = data(b, e);
	}

	size_type size() const { return data.size(); }
	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

	Str& operator+=(const Str& s)
	{
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

private:
	Vec<char> data;
};

std::ostream& operator<<(std::ostream& os, const Str& s);

Str operator+(const Str&, const Str&);
