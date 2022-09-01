#pragma once
#include <algorithm>
#include <iterator>
#include <memory>

struct ch_array
{
	char* ch_head;
	size_t length;
	std::allocator<char> ch_alloc;

	ch_array()
	{
		ch_head = nullptr;
		length = 0;
	}

	char* ch_create(size_t n)
	{
		clear();
		length = n;
		ch_head = ch_alloc.allocate(n);
		return ch_head;
	}

	void clear()
	{
		if (ch_head)
		{
			while (length != 0)
			{
				length--;
				ch_alloc.destroy(ch_head + length);
			}
			ch_alloc.deallocate(ch_head, length);
		}
		ch_head = nullptr;
	}
};

class Str_new
{
	friend std::istream& operator>>(std::istream& is, Str_new& s);
	friend std::istream& getline(std::istream& is, Str_new& str, char lim = '\n');
public:
	using size_type = size_t;
	using iterator = char*;
	using const_iterator = const char*;
	using difference_type = std::ptrdiff_t;
	using reference = char&;
	using const_reference = const char&;

	//default construct function
	Str_new()
	{
		create();
	}

	//generate a Str with n of c
	explicit Str_new(size_type n, const char c = '\0')
	{
		create(n, c);
	}

	//generate a Str with char array end with '\0'
	Str_new(const char* cp);

	//generate a Str using content between iterator b and e
	template <class In>
	Str_new(In b, In e);

	Str_new(const Str_new& s) { create(s.begin(), s.end()); }

	~Str_new() { uncreate(); }

	//size and index
	size_type size() const { return avail - head; }
	reference operator[](size_type i) { return head[i]; }
	const_reference operator[](size_type i) const { return head[i]; }

	//assignment
	Str_new& operator=(const Str_new&);

	iterator begin() { return head; }
	const_iterator begin() const { return head; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	Str_new& operator+=(const Str_new& s);
	//12-4
	bool operator==(const Str_new&);
	bool operator!=(const Str_new&);
	//12-5
	Str_new& operator+(const char*);

	//12-2
	const char* data();
	const char* c_str();
	size_type copy(char* p, size_t n) const;

	//12-6
	operator void*() const;

private:
	iterator head;
	iterator avail;

	ch_array str_ch;
	//memory management tool
	std::allocator<char> alloc;


	//assign space and initialize array
	void create();
	void create(size_type n, const char& ch = '\0');
	template <class In>
	void create(In i, In j);
	void uncreate();
};

std::ostream& operator<<(std::ostream& os, const Str_new& s);

Str_new operator+(const Str_new&, const Str_new&);

ptrdiff_t strcmp(const Str_new&, const Str_new&);

template <class In>
Str_new::Str_new(In b, In e)
{
	create(b, e);
}

template <class In>
void Str_new::create(In i, In j)
{
	auto length = j - i;
	head = alloc.allocate(length);
	avail = head + length;
	std::copy(i, j, head);
}
