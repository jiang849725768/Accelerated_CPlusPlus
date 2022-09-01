#pragma once

class Ct_ptr
{
public:
	Ct_ptr();
	Ct_ptr(const Ct_ptr& r);
	Ct_ptr& operator=(const Ct_ptr&);
	Ct_ptr& operator--();
	~Ct_ptr();

	operator bool() const;

	bool the_only() const;


private:
	size_t* count_ptr;
};
