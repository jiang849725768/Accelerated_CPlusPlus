#pragma once
#include <cstddef>
#include <memory>


template <class T>
class Vec
{
public:
	using iterator = T*;
	using const_iterator = const T*;
	using size_type = size_t;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using reference = T&;
	using const_reference = const T&;

	Vec() { create(); }
	explicit Vec(size_t n, const T& val = T()) { create(n, val); }

	//duplicate
	Vec(const Vec& v) { create(v.begin(), v.end()); }

	//size and index
	size_type size() const { return avail - data; }
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	//assignment
	Vec& operator=(const Vec&);

	//destructor
	~Vec() { uncreate(); }

	//get iterator
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	//memory management
	void push_back(const T& val)
	{
		if (avail == limit)
			grow();
		unchecked_append(val);
	}

	//erase&clear(11-6)
	iterator erase(iterator);
	iterator erase(iterator, iterator);

	void clear()
	{
		if (data)
			while (avail != data)
				alloc.destroy(--avail);
	}

	//empty
	bool empty() const { return data == avail; }

private:
	iterator data;
	iterator avail;
	iterator limit;

	//memory management tool
	std::allocator<T> alloc;

	//assign space and initialize array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	//delete elements & free memory
	void uncreate();

	//support for push_back
	void grow();
	void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	//judge whether self-assign
	if (&rhs != this)
	{
		//delete left array
		uncreate();

		//duplicate from right to left
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator position)
{
	if (data == avail)
		std::cerr << "Vector is empty to erase" << std::endl;
	for (iterator it = position; it != avail - 1; ++it)
		*it = *(it + 1);
	alloc.destroy(--avail);
	return position;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator first, iterator last)
{
	iterator i = first;
	for (iterator j = last; j != avail; ++i, ++j)
		*i = *j;
	while (avail != i)
		alloc.destroy(--avail);

	return first;
}

template <class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate()
{
	if (data)
	{
		//delete elements in reverse order
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		//return all used space
		alloc.deallocate(data, limit - data);
	}
	//reset pointer to set Vec to none
	data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow()
{
	//assign two times memory space
	size_type new_size = std::max(2 * (limit - data), static_cast<ptrdiff_t>(1));

	//assign new memory space & duplicate existed elements
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	//delete origin space
	uncreate();

	//reset pointer to new assigned space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}
