#include "String_list.h"

#include <iostream>
#include <algorithm>
#include <utility>

using std::string;
using std::copy;
using std::cout;
using std::endl;

String_list::String_list(): data(new string[1]), size(0), limit(1)
{
}

String_list::String_list(const String_list& string_list)
{
	*this = string_list;

	data = new string[limit];
	copy(string_list.data, string_list.data + string_list.size, data);
}

String_list::String_list(std::string* string_list, size_t list_size)
{
	size = list_size;
	limit = size * 2;
	data = new string[limit];
	copy(string_list, string_list + size, data);
}

String_list::~String_list()
{
	delete[] data;
}

std::string* String_list::begin() const
{
	return data;
}

std::string* String_list::end() const
{
	return data + size;
}

std::string* String_list::resize()
{
	limit *= 2;
	auto new_string_list = new string[limit];
	copy(data, data + size, new_string_list);
	delete[] data;

	data = new_string_list;

	return data;
}

void String_list::push_back(std::string new_string)
{
	if (size == limit)
		resize();
	data[size] = std::move(new_string);
	size++;
}

void String_list::self_print()
{
	for (size_t i = 0; i < size; i++)
		cout << "Word" << i + 1 << ":" << data[i] << endl;
}
