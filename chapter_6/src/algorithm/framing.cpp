﻿#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <numeric>
#include <iterator>

#include "framing.h"

using namespace std;

//求最大行长度
string::size_type maxWidth(const vector<string>& some_strings)
{
	string::size_type maxlen = 0;
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
		maxlen = max(maxlen, (*it).size());
	return maxlen;
}

//输出字符串组
void printfOut(const vector<string>& some_strings)
{
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		cout << (*it) << endl;
	}
}

//随机生成字符串组(指定数量)
//length: 产生字符串组的长度
vector<string> genRanStr(const int length)
{
	char tmp{};
	vector<string> some_strings{};
	string a_string;

	//定义种子发生器
	random_device rd;
	//定义随机数序列生成器
	default_random_engine rng{ rd() };
	//指定随机数类型和范围
	uniform_int_distribution<int> random_string_length(10, 40);
	uniform_int_distribution<int> random_char(0, 60);

	for (int i = 0; i < length; i++) {
		a_string = "";
		int string_lenth = random_string_length(rng);
		for (int j = 0; j < string_lenth; j++) {
			tmp = random_char(rng);			// 随机一个 0-60 的整数，a-z、A-Z 共 52 种字符
			if (tmp > 51) {					// 如果随机数大于 51，变换成一个空格的 ASCII
				tmp = ' ';
			}
			else if (tmp < 26) {			// 如果随机数小于 26，变换成一个小写字母的 ASCII
				tmp += 'a';
			}
			else {							// 其他情况，变换成一个大写字母的 ASCII
				tmp -= 26;
				tmp += 'A';
			}
			a_string += tmp;
		}
		some_strings.push_back(a_string);
	}

	return some_strings;
}

//字符串装框
std::vector<std::string> frame(const std::vector<std::string>& some_strings)
{
	vector<string> ret;
	auto maxlen = maxWidth(some_strings);
	string border(maxlen + 4, '*');

	//上边框
	ret.push_back(border);

	//内部行
	for (vector<string>::size_type i = 0; i != some_strings.size(); ++i)
	{
		ret.push_back("* " + some_strings[i] + string(maxlen - some_strings[i].size(), ' ') + " *");
	}

	//下边框
	ret.push_back(border);

	return ret;
}

//字符串横向连接
vector<string> heat(const vector<string>& left_strings, const vector<string>& right_strings)
{
	vector<string> ret;

	string::size_type left_width = maxWidth(left_strings);

	vector<string>::size_type i = 0, j = 0;

	while (i != left_strings.size() || j != right_strings.size())
	{
		//用于保存连接后的新字符串
		string s;

		if (i != left_strings.size())
			s = left_strings[i++];

		//填充，同时在左右之间留一个空格
		s += string(left_width + 1 - s.size(), ' ');

		if (j != right_strings.size())
			s += right_strings[j++];

		ret.push_back(s);
	}

	return ret;
}

//迭代器字符串装框(6-1)
std::vector<std::string> frameIterator(const std::vector<std::string>& some_strings)
{
	vector<string> ret;
	auto maxlen = maxWidth(some_strings);
	string border(maxlen + 4, '*');

	//上边框
	ret.push_back(border);

	//内部行
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		ret.push_back("* " + (*it) + string(maxlen - (*it).size(), ' ') + " *");
	}

	//下边框
	ret.push_back(border);

	return ret;
}

//迭代器字符串横向连接(6-1)
vector<string> heatIterator(const vector<string>& left_strings, const vector<string>& right_strings)
{
	vector<string> ret;

	string::size_type left_width = maxWidth(left_strings);

	auto lit = left_strings.begin();
	auto rit = right_strings.begin();

	while (lit != left_strings.end() || rit != right_strings.end())
	{
		//用于保存连接后的新字符串
		string s;

		if (lit != left_strings.end())
			s = (*lit++);

		//填充，同时在左右之间留一个空格
		s += string(left_width + 1 - s.size(), ' ');

		if (rit != right_strings.end())
			s += (*rit++);

		ret.push_back(s);
	}

	return ret;
}

//拼接字符串组(6-9)
std::string conectStrings(const std::vector<std::string>& some_strings)
{
	string new_string;
	new_string = accumulate(some_strings.begin(), some_strings.end(), new_string);

	return new_string;
}