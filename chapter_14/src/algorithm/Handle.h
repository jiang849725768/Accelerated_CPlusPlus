#pragma once
#include <stdexcept>

#include "Core.h"

template <class T>
class Handle
{
public:
	Handle();
	Handle(const Handle& s);
	Handle& operator=(const Handle&);
	~Handle();

	Handle(T* t);

	operator bool() const;
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};

bool compare_Core_handles(const Handle<Core>& a, const Handle<Core>& b);

#include "Handle.tpp"
