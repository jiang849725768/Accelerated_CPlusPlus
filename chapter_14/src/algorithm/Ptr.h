#pragma once
#include <stdexcept>

#include "Core.h"
#include "Vec.h"

template <class T>
class Ptr
{
public:
	Ptr();
	Ptr(T* t);
	Ptr(const Ptr& h);
	Ptr& operator=(const Ptr&);
	~Ptr();

	operator bool() const;
	T& operator*() const;
	T* operator->() const;

	void make_unique();


private:
	T* p;
	size_t* refptr;
};

#include "Ptr.tpp"

template <class T>
T* clone(const T* tp)
{
	return tp->clone();
}

template <>
Vec<char>* clone(const Vec<char>* tp);

bool compare_Core_Ptrs(const Ptr<Core>& a, const Ptr<Core>& b);
