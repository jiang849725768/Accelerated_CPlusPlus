#include "answer.h"

#include <cctype>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

//判断非空格字符
bool isNotSpace(const char c)
{
	return !isspace(c);
}

//分割字符串
String_list split(const std::string& a_string)
{
	String_list ret;
	auto i = a_string.begin();
	while (i != a_string.end())
	{
		i = find_if(i, a_string.end(), isNotSpace); //定位非空开头
		auto j = find_if(i, a_string.end(), isspace); //定位单词结尾

		//复制[i, j)中字符
		if (i != a_string.end())
		{
			ret.push_back(string(i, j)); // NOLINT(modernize-use-emplace)
			cout << "add " << string(i, j) << endl;
		}
		i = j;
	}
	ret.self_print();
	return ret;
}
