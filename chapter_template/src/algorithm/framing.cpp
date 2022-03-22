#include <iostream>
#include <string>
#include <vector>
#include <random>

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

//居中填充字符串
vector<string> center(const vector<string>& some_strings)
{
	auto maxlen = maxWidth(some_strings);
	vector<string> new_strings{};

	//添加上边框
	string border(maxlen + 2, '*');
	new_strings.push_back(border);

	//用*填充
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		string::size_type left_part_length = (maxlen - (*it).size()) / 2;
		auto right_part_length = maxlen - left_part_length - (*it).size();
		new_strings.push_back(string(left_part_length + 1, '*') + (*it) + string(right_part_length + 1, '*'));
	}

	//添加下边框
	new_strings.push_back(border);

	return new_strings;
}

//输出字符串组
void printfOut(const vector<string>& some_strings)
{
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		cout << (*it) << endl;
	}
}

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
	uniform_int_distribution<int> random_string_length(1, 30);
	uniform_int_distribution<int> random_char(0, 35);

	for (int i = 0; i < length; i++) {
		a_string = "";
		int string_lenth = random_string_length(rng);
		for (int j = 0; j < string_lenth; j++) {
			tmp = random_char(rng) % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
			if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
				tmp += '0';
			}
			else {				// 否则，变换成一个大写字母的 ASCII
				tmp -= 10;
				tmp += 'A';
			}
			a_string += tmp;
		}
		some_strings.push_back(a_string);
	}

	return some_strings;
}