#include "book.h"
#include <cctype>
#include <algorithm>

using namespace std;

//判断非空格字符
bool isNotSpace(char c)
{
	return !isspace(c);
}

//分割字符串
std::vector<std::string> split(const std::string& a_string)
{
	vector<string> ret;
	auto i = a_string.begin();
	while (i != a_string.end())
	{
		i = find_if(i, a_string.end(), isNotSpace);			//定位非空开头
		auto j = find_if(i, a_string.end(), isspace);		//定位单词结尾

		//复制[i, j)中字符
		if (i != a_string.end())
			ret.push_back(string(i, j));
		i = j;
	}

	return ret;
}

//判断是否为url字符，不是则true
bool notUrlChar(char c)
{
	//除字母数字外其他可能出现在url里的字符
	static const string url_char = "~;/?:@=&$-_.+!*'(),";

	//判断c字符是否为url字符，返回取反结果
	return !(isalnum(c) || find(url_char.begin(), url_char.end(), c) != url_char.end());
}

//找到包含"://"的url的开头
std::string::const_iterator urlBegin(std::string::const_iterator b,
	std::string::const_iterator e)
{
	static const string sep = "://";
	string::const_iterator i = b;			//i为分隔符开头位置

	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		if (i != b && i + sep.size() != e)
		{
			string::const_iterator beg = i;	//beg为url开头位置

			while (beg != b && isalpha(beg[-1]))
				--beg;

			//确保分隔符前后非空
			if (beg != i && !notUrlChar(i[sep.size()]))
				return beg;
		}

		i += sep.size();
	}

	return e;
}

//定位url的结尾
std::string::const_iterator urlEnd(std::string::const_iterator b,
	std::string::const_iterator e)
{
	return find_if(b, e, notUrlChar);
}

//查找url
std::vector<std::string> findUrls(const string& long_string)
{
	vector<string> ret;
	auto b = long_string.begin(), e = long_string.end();

	while (b != e)
	{
		//找到包含"://"的url的开头
		b = urlBegin(b, e);

		if (b != e) {
			//定位url的结尾
			auto after = urlEnd(b, e);
			//添加url
			ret.push_back(string(b, after));
			//推进b至当前url的结尾继续查找
			b = after;
		}
	}
	return ret;
}