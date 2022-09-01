#pragma once
#include <stdexcept>

#include "Core.h"
#include "Ct_ptr.h"
#include "Vec.h"

template <class T>
class Ptr_new
{
public:
	Ptr_new();
	Ptr_new(T* t);
	Ptr_new(const Ptr_new& h);
	Ptr_new& operator=(const Ptr_new&);
	~Ptr_new();

	operator bool() const;
	T& operator*() const;
	T* operator->() const;

	void make_unique();

private:
	T* p;
	Ct_ptr pct;
};

template <class T>
Ptr_new<T>::Ptr_new(): p(nullptr)
{
}

template <class T>
Ptr_new<T>::Ptr_new(T* t): p(t)
{
}

template <class T>
Ptr_new<T>::Ptr_new(const Ptr_new& h): p(h.p), pct(h.pct)
{
}

template <class T>
Ptr_new<T>& Ptr_new<T>::operator=(const Ptr_new& rhs)
{
	if (&rhs != this)
	{
		if (pct.the_only())
			delete p;
		pct = rhs.pct;
		p = rhs.p;
	}
	return *this;
}

template <class T>
Ptr_new<T>::~Ptr_new()
{
	if (pct.the_only())
		delete p;
	--pct;
}

template <class T>
Ptr_new<T>::operator bool() const
{
	return p;
}

template <class T>
T& Ptr_new<T>::operator*() const
{
	if (p)
		return *p;
	throw std::runtime_error(" unbound Ptr ");
}

template <class T>
T* Ptr_new<T>::operator->() const
{
	if (p)
		return p;
	throw std::runtime_error(" unbound Ptr ");
}

template <class T>
void Ptr_new<T>::make_unique()
{
	if (!pct.the_only())
	{
		--pct;
		pct = Ct_ptr();
		p = p ? clone(p) : nullptr;
	}
}


bool compareCorePtrs(const Ptr_new<Core>& a, const Ptr_new<Core>& b);
