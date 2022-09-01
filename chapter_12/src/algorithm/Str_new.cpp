#include "Str_new.h"

#include <iostream>
#include <vector>

Str_new::Str_new(const char* cp)
{
	create(std::strlen(cp));
	std::copy_n(cp, std::strlen(cp), head);
}

Str_new& Str_new::operator=(const Str_new& s)
{
	if (&s != this)
	{
		uncreate();
		create(s.begin(), s.end());
	}

	return *this;
}

Str_new& Str_new::operator+=(const Str_new& s)
{
	size_type new_length = size() + s.size();
	auto new_head = alloc.allocate(new_length);
	std::copy(head, avail, new_head);
	std::copy(s.begin(), s.end(), new_head + size());
	uncreate();
	head = new_head;
	avail = head + new_length;

	return *this;
}

bool Str_new::operator==(const Str_new& s)
{
	if (s.size() != size())
		return false;
	for (size_t i = 0; i < size(); ++i)
		if (head[i] != s.head[i])
			return false;
	return true;
}

bool Str_new::operator!=(const Str_new& s)
{
	return !(*this == s);
}

Str_new& Str_new::operator+(const char* chs)
{
	const size_type new_length = size() + strlen(chs);
	auto new_head = alloc.allocate(new_length);
	std::copy(head, avail, new_head);
	std::copy_n(chs, strlen(chs), new_head + size());
	uncreate();
	head = new_head;
	avail = head + new_length;

	return *this;
}

const char* Str_new::data()
{
	char* ch_head = str_ch.ch_create(size());
	for (size_t i = 0; i < size(); ++i)
		ch_head[i] = head[i];

	return ch_head;
}

const char* Str_new::c_str()
{
	char* ch_head = str_ch.ch_create(size() + 1);
	for (size_t i = 0; i < size(); ++i)
		ch_head[i] = head[i];
	ch_head[size()] = '\0';
	return ch_head;
}

Str_new::size_type Str_new::copy(char* p, size_t n) const
{
	const size_type copy_size = std::min(n, size());
	for (size_t i = 0; i < copy_size; ++i)
		p[i] = head[i];

	return copy_size;
}

Str_new::operator void*() const
{
	return head;
}

void Str_new::create()
{
	head = avail = nullptr;
}

void Str_new::create(size_type n, const char& ch)
{
	head = alloc.allocate(n);
	avail = head + n;
	std::uninitialized_fill(head, avail, ch);
}

void Str_new::uncreate()
{
	str_ch.clear();
	if (head)
	{
		const size_type length = avail - head;
		while (avail != head)
			alloc.destroy(--avail);
		alloc.deallocate(head, length);
	}
	head = avail = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Str_new& s)
{
	//for (const char i : s)
	//	os << i;


	//12-9
	const std::ostream_iterator<char> out_it(os);
	std::copy(s.begin(), s.end(), out_it);

	return os;
}

Str_new operator+(const Str_new& str_new, const Str_new& str_new1)
{
	Str_new str_new2(str_new);
	return str_new2 += str_new1;
}

ptrdiff_t strcmp(const Str_new& str1, const Str_new& str2)
{
	return str1.size() - str2.size();
}

std::istream& operator>>(std::istream& is, Str_new& s)
{
	//delete existed value
	s.uncreate();

	std::vector<char> str_in;
	//read char in order, ignore space char before
	char c;
	while (is.get(c) && isspace(c))
	{
	} //only judge loop condition
	//repeat reading until meet a space char
	if (is)
	{
		do
		{
			str_in.push_back(c);
		}
		while (is.get(c) && !isspace(c));

		//put the space char back to the in stream
		if (is)
			is.unget();
	}

	s.create(str_in.begin(), str_in.end());

	return is;
}

std::istream& getline(std::istream& is, Str_new& str, char lim)
{
	//delete existed value
	str.uncreate();

	std::vector<char> str_in;
	//read char in order, ignore space char before
	char c;
	while (is.get(c) && c == lim)
	{
	} //only judge loop condition
	//repeat reading until meet a space char
	if (is)
	{
		do
		{
			str_in.push_back(c);
		}
		while (is.get(c) && c != lim);
	}

	str.create(str_in.begin(), str_in.end());

	return is;
}
