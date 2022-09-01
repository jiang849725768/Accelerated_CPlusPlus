template <class T>
Handle<T>::Handle(): p(nullptr)
{
}

template <class T>
Handle<T>::Handle(const Handle& s): p(nullptr)
{
	if (s.p) p = s.p->clone();
}

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	if (&rhs != this)
	{
		delete p;
		p = rhs.p ? rhs.p->clone() : nullptr;
	}

	return *this;
}

template <class T>
Handle<T>::~Handle()
{
	delete p;
}

template <class T>
Handle<T>::Handle(T* t): p(t)
{
}

template <class T>
Handle<T>::operator bool() const
{
	return p;
}

template <class T>
T& Handle<T>::operator*() const
{
	if (p)
		return *p;
	throw std::runtime_error(" unbound Handle ");
}

template <class T>
T* Handle<T>::operator->() const
{
	if (p)
		return p;
	throw std::runtime_error(" unbound Handle ");
}