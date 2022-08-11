#ifndef GUARD_BOOK_H
#define GUARD_BOOK_H

#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

//判断非空格字符
bool isntSpace(const char);

//取中值函数模板(8.1.1)
template <class T>
T median(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid + 1]) / 2 : v[mid];
}

//max函数模板(8.1.3)
template <class T>
T max(const T& left, const T& right)
{
	return left > right ? left : right;
}

//find函数模板(8.2.2)
template <class In, class X>
In find(In begin, In end, const X& x)
{
	//方法1
	while (begin != end && *begin != x)
		++begin;
	return begin;

	//方法2
	// if (begin == end || *begin == x)
	// 	return begin;
	// ++begin;
	// return find(begin, end, x);
}

//copy函数模板(8.2.3)
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

//replace函数模板(8.2.4)
template<class For, class X>
void replace(For begin, For end, const X& x, const X& y)
{
	while (begin != end)
	{
		if (*begin == x)
			*begin = y;
		++begin;
	}
}

//reverse函数模板(8.2.5)
template<class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

//binary_search模板函数(8.2.6)
template <class Ran, class X>
// ReSharper disable once CppInconsistentNaming
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end) {
		Ran mid = begin + (end - begin) / 2;
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		else return true;
	}
	return false;
}

//字符串分割函数模板(8.4)
template <class Out>
void split(const std::string& str, Out os)
{
	typedef std::string::const_iterator it;

	it i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), isntSpace); //忽略前端的空白
		const it j = find_if(i, str.end(), isspace); //找出下一个单词结尾

		if (i != str.end())
			*os++ = std::string(i, j);
		i = j;
	}
}

#endif