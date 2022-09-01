#pragma once

template <class T>
class Ref_handle
{
public:
	Ref_handle();
	Ref_handle(T* t);
	Ref_handle(const Ref_handle& h);
	Ref_handle& operator=(const Ref_handle&);
	~Ref_handle();

	operator bool() const;
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
	size_t* refptr;
};

#include "Ref_handle.tpp"
