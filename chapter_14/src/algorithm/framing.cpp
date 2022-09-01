#include <iostream>
#include <vector>
#include <random>

#include "framing.h"

using namespace std;

bool isNotSpace(const char ch)
{
	return !isspace(ch);
}

//分割字符串
Vec<Str> split(const Str& a_string)
{
	Vec<Str> ret;
	auto i = a_string.begin();
	while (i != a_string.end())
	{
		i = find_if(i, a_string.end(), isNotSpace); //定位非空开头
		auto j = find_if(i, a_string.end(), isspace); //定位单词结尾

		//复制[i, j)中字符
		if (i != a_string.end())
			ret.push_back(Str(i, j));
		i = j;
	}

	return ret;
}


//求最大行长度
Str::size_type maxWidth(const Vec<Str>& some_strings)
{
	Str::size_type maxlen = 0;
	for (const auto& some_string : some_strings)
		maxlen = max(maxlen, some_string.size());
	return maxlen;
}

//居中填充字符串
Vec<Str> center(const Vec<Str>& some_strings)
{
	auto maxlen = maxWidth(some_strings);
	Vec<Str> new_strings{};

	//添加上边框
	Str border(maxlen + 2, '*');
	new_strings.push_back(border);

	//用*填充
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		Str::size_type left_part_length = (maxlen - (*it).size()) / 2;
		auto right_part_length = maxlen - left_part_length - (*it).size();
		new_strings.push_back(Str(left_part_length + 1, '*') + (*it) + Str(right_part_length + 1, '*'));
	}

	//添加下边框
	new_strings.push_back(border);

	return new_strings;
}

//输出字符串组
void printfOut(Vec<Str>& some_strings)
{
	for (auto& some_string : some_strings)
	{
		cout << some_string.ec_str() << endl;
	}
}

//length: 产生字符串组的长度
Vec<Str> genRanStr(const int length)
{
	char tmp{};
	Vec<Str> some_strings{};
	Str a_string;

	//定义种子发生器
	random_device rd;
	//定义随机数序列生成器
	default_random_engine rng{rd()};
	//指定随机数类型和范围
	uniform_int_distribution<int> random_string_length(10, 40);
	uniform_int_distribution<int> random_char(0, 60);

	for (int i = 0; i < length; i++)
	{
		a_string = "";
		int string_length = random_string_length(rng);
		for (int j = 0; j < string_length; j++)
		{
			tmp = random_char(rng); // 随机一个 0-60 的整数，a-z、A-Z 共 52 种字符
			if (tmp > 51)
			{
				// 如果随机数大于 51，变换成一个空格的 ASCII
				tmp = ' ';
			}
			else if (tmp < 26)
			{
				// 如果随机数小于 26，变换成一个小写字母的 ASCII
				tmp += 'a';
			}
			else
			{
				// 其他情况，变换成一个大写字母的 ASCII
				tmp -= 26;
				tmp += 'A';
			}
			const char tmps[] = {'a', 'b', 'c'};
			cout << tmps << endl;
			cout << "---------" << endl;
			a_string = a_string + tmps;
		}
		cout << a_string << endl;
		some_strings.push_back(a_string);
	}

	return some_strings;
}

//字符串装框
Vec<Str> frame(const Vec<Str>& some_strings)
{
	Vec<Str> ret;
	auto maxlen = maxWidth(some_strings);
	Str border(maxlen + 4, '*');

	//上边框
	ret.push_back(border);

	//内部行
	for (Vec<Str>::size_type i = 0; i != some_strings.size(); ++i)
	{
		ret.push_back("* " + some_strings[i] + Str(maxlen - some_strings[i].size(), ' ') + " *");
	}

	//下边框
	ret.push_back(border);

	return ret;
}

//字符串横向连接
Vec<Str> heat(const Vec<Str>& left_strings, const Vec<Str>& right_strings)
{
	Vec<Str> ret;

	string::size_type left_width = maxWidth(left_strings);

	Vec<Str>::size_type i = 0, j = 0;

	while (i != left_strings.size() || j != right_strings.size())
	{
		//用于保存连接后的新字符串
		Str s;

		if (i != left_strings.size())
			s = left_strings[i++];

		//填充，同时在左右之间留一个空格
		s += Str(left_width + 1 - s.size(), ' ');

		if (j != right_strings.size())
			s += right_strings[j++];

		ret.push_back(s);
	}

	return ret;
}

//字符串横向连接
Vec<Str> heat_change(const Vec<Str>& left_strings, const Vec<Str>& right_strings)
{
	Vec<Str> ret;

	Str::size_type left_width = maxWidth(left_strings);

	Vec<Str>::size_type i = 0, j = 0;

	//用于保存连接后的新字符串
	Str s;

	while (i != left_strings.size() || j != right_strings.size())
	{
		if (i != left_strings.size())
			s = left_strings[i++];

		//填充，同时在左右之间留一个空格
		s += Str(left_width + 1 - s.size(), ' ');

		if (j != right_strings.size())
			s += right_strings[j++];

		ret.push_back(s);
	}

	return ret;
}
