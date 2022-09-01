#include "Ct_ptr.h"

Ct_ptr::Ct_ptr(): count_ptr(new size_t(1))
{
}

Ct_ptr::Ct_ptr(const Ct_ptr& r): count_ptr(r.count_ptr)
{
	++*count_ptr;
}

Ct_ptr& Ct_ptr::operator=(const Ct_ptr& rhs)
{
	if (&rhs != this)
	{
		++*rhs.count_ptr;
		if (--*count_ptr == 0)
			delete count_ptr;
		count_ptr = rhs.count_ptr;
	}
	return *this;
}

Ct_ptr& Ct_ptr::operator--()
{
	if (--*count_ptr == 0)
		delete count_ptr;
	return *this;
}

Ct_ptr::~Ct_ptr()
{
	if (--*count_ptr == 0)
		delete count_ptr;
}

Ct_ptr::operator bool() const
{
	return count_ptr;
}

bool Ct_ptr::the_only() const
{
	return *count_ptr == 1;
}
