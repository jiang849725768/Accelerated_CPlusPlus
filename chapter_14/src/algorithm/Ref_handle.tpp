#include <stdexcept>

template <class T>
Ref_handle<T>::Ref_handle(): p(nullptr), refptr(new size_t(1))
{
}

template <class T>
Ref_handle<T>::Ref_handle(T* t): p(t), refptr(new size_t(1))
{
}

template <class T>
Ref_handle<T>::Ref_handle(const Ref_handle& h): p(h.p), refptr(h.refptr)
{
	++*refptr;
}

template <class T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
	++*rhs.refptr;
	if (--*refptr == 0)
	{
		delete p;
		delete refptr;
	}
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T>
Ref_handle<T>::~Ref_handle()
{
	if(--*refptr==0)
	{
		delete refptr;
		delete p;
	}
}

template <class T>
Ref_handle<T>::operator bool() const
{
	return p;
}

template <class T>
T& Ref_handle<T>::operator*() const
{
	if (p)
		return *p;
	throw std::runtime_error("unbound Ref_handle ");
}

template <class T>
T* Ref_handle<T>::operator->() const
{
	if (p)
		return p;
	throw std::runtime_error("unbound Ref_handle ");
}