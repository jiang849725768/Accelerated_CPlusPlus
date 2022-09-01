#pragma once

#include <string>

class String_list
{
private:
	std::string* data;
	size_t size;
	size_t limit;

	std::string* resize();
public:
	String_list();
	String_list(const String_list&);
	explicit String_list(std::string*, size_t);
	~String_list();
	std::string* begin() const;
	std::string* end() const;
	void push_back(std::string);
	void self_print();
};
