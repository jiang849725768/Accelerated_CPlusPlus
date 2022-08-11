// ReSharper disable CppInconsistentNaming
#ifndef GUARD_ANSWER_H
#define GUARD_ANSWER_H

#include <vector>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>

#include "chap_before.h"
#include "chapter_seven.h"

//成绩分析模板函数(8-1)
template <class T>
double gradeAnalysis(T func(const Student_info&), const std::vector<Student_info>& students)
{
	std::vector<double> grades;
	std::transform(students.begin(), students.end(),
	               std::back_inserter(grades), func);
	return median(grades);
}

//equal模板函数(8-2)
template <class In, class X>
bool equal(In begin, In end, const X& x)
{
	auto it = x.begin();
	while (begin != end && it != x.end())
	{
		if (*begin++ != *it++)
			return false;
	}
	return true;
}

//search模板函数(8-2)
template <class In>
In search(In begin, In end, In begin_s, In end_s)
{
	while (begin != end)
	{
		if (*begin == *begin_s)
		{
			auto location = begin;
			bool still_equal = true;
			while (begin_s != end_s)
			{
				if (*begin++ != *begin_s++)
				{
					still_equal = false;
					break;
				}
			}
			if (still_equal)
				return location;
		}
		++begin;
	}
	return begin;
}

//find_if模板函数(8-2)
template <class In, class X>
In find_if(In begin, In end, bool func(const X&))
{
	while (begin != end)
	{
		if (func(*begin))
			return begin;
		++begin;
	}
	return begin;
}

//remove_copy模板函数(8-2)
template <class In, class Out, class X>
Out remove_copy(In begin, In end, Out start, const X& x)
{
	while (begin != end)
		if (*begin != x)
			*start++ = *begin++;
	return start;
}

//remove_copy_if模板函数(8-2)
template <class In, class Out, class X>
Out remove_copy(In begin, In end, Out start, bool func(const X&))
{
	while (begin != end)
		if (!func(*begin))
			*start++ = *begin++;
	return start;
}

//remove模板函数(8-2)
template <class For, class X>
For remove(For begin, For end, const X& x)
{
	For start = begin;
	while (begin++ != end)
	{
		if (*begin != x)
			*start++ = *begin;
	}
	return start;
}

//transform模板函数(8-2)
template <class In, class Out, class X, class Y>
Out transform(In begin, In end, Out dest, X func(const Y&))
{
	while (begin++ != end)
		*dest++ = func(*begin);
	return dest;
}

//partition模板函数(8-2)
template <class For, class X>
auto partition(For begin, For end, bool func(const X&))
{
	For fake = begin;
	while (begin++ != end)
	{
		if (!func(*begin))
			fake = begin;
		else if (func(*begin) && !func(*fake))
		{
			std::swap(*begin, *fake++);
		}
	}
	return fake;
}

//accumulate模板函数(8-2)
template <class In, class X>
X accumulate(In begin, In end, X& x)
{
	while (begin++ != end)
		x += *begin;
	return x;
}

//swap模板函数(8-4)
template <class T>
void swap(T a, T b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//取中值函数模板(8-3)
template <class In, class X>
X medianNew(In begin, In end)
{
	size_t size = 0;
	In it = begin;
	while (it++ != end)
		++size;

	if (size == 0)
		throw std::domain_error("median of an empty vector");

	sort(begin, end);
	size_t mid = size / 2;
	if (size % 2 == 0)
	{
		size_t i = 0;
		X value = *begin;
		while (i++ != size / 2)
			++begin;
		value = *begin;
		return (value + *(++begin)) / 2;
	}
	else
	{
		size_t i = 0;
		X value = *begin;
		while (i++ != size / 2)
			++begin;
		value = *begin;
		return value;
	}
}

//查找指向输入中每一个单词的全部行(7.3)
std::map<std::string, std::vector<int> > xref(std::istream&,
	std::ostream_iterator<int> out,
	std::vector<std::string> find_words(const std::string&) = split);

//生成完整句子
std::list<std::string> genSentence(const Grammar& the_grammar, std::ostream_iterator<std::string> out);

#endif // !GUARD_answer_h
