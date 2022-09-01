#pragma once

#include <iterator>

#include "Ptr.h"
#include "Vec.h"

class Str
{
	friend std::istream& operator>>(std::istream& is, Str& s);
public:
	using size_type = Vec<char>::size_type;

	//default construct function
	Str();

	//generate a Str with n of c
	Str(size_type n, char c);

	//generate a Str with char array end with '\0'
	Str(const char* cp);

	//generate a Str using content between iterator b and e
	template <class In>
	Str(In b, In e);

	size_type size() const;
	char& operator[](size_type i);
	const char& operator[](size_type i) const;

	Str& operator+=(const Str& s);

	//get iterator
	char* begin() { return data->begin(); }
	const char* begin() const { return data->begin(); }
	char* end() { return data->end(); }
	const char* end() const { return data->end(); }

	const char* ec_str() const;

private:
	Ptr<Vec<char>> data;
};

template <class In>
Str::Str(In b, In e): data(new Vec<char>)
{
	std::copy(b, e, std::back_inserter(*data));
}

std::ostream& operator<<(std::ostream& os, const Str& s);

Str operator+(const Str&, const Str&);
