#ifndef GUARD_ANSWER_H
#define GUARD_ANSWER_H

#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <vector>

#include "String_list.h"

//10-2
//取中值函数模板(8.1.1)
template <class In, class T>
T median(In begin, In end)
{
	std::vector<T> new_vec;
	std::copy(begin, end, std::back_inserter(new_vec));
	sort(new_vec.begin(), new_vec.end());

	//获取数组或向量长度
	auto size = new_vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	auto mid = size / 2;

	return size % 2 == 0 ? (new_vec[mid] + new_vec[mid + 1]) / 2 : new_vec[mid];
}

#endif


//判断非空格字符(10-4)
bool isNotSpace(char c);

//分割字符串(10-4)
String_list split(const std::string& a_string);
