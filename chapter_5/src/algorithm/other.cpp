#include "other.h"
#include <cctype>

using namespace std;

//字符串分割
vector<string> split(const string& a_string)
{
	vector<string> ret;
	string::size_type i = 0;

	while (i != a_string.size())
	{
		//忽略前端空白，找到第一个非空格字符
		while (i != a_string.size() && isspace(a_string[i]))
			++i;

		//找到单词终结点
		auto j = i;
		while (j != a_string.size() && !isspace(a_string[j]))
			++j;

		if (i != j)
		{
			ret.push_back(a_string.substr(i, j - i));
			i = j;
		}
	}

	return ret;
}

//寻找并提取小写单词
vector<string> extractLower(vector<string>& words)
{
	vector<string> lower_words;

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
	{
		bool is_lower = true;
		for (string::size_type j = 0; j < (*it).size(); j++)
		{
			if (!islower((*it)[j]))
			{
				is_lower = false;
				break;
			}
		}

		//判断是否为小写单词
		if (is_lower)
		{
			lower_words.push_back(*it);
			it = words.erase(it);
			//防止无效指针
			if (it == words.end())
				break;
		}
	}

	return lower_words;
}

//寻找回文单词
vector<string> findPalindromes(const vector<string>& words)
{
	vector<string> palindromes;

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++)
	{
		//获取单词长度
		auto word_length = (*it).size();
		bool is_palindrome = true;

		//循环判断单词至长度一半
		for (string::size_type i = 0; i < word_length / 2; i++)
		{
			//回文：word[i] = word[length - i -1]
			if ((*it)[i] != (*it)[word_length - i - 1])
			{
				is_palindrome = false;
				break;
			}
		}

		if (is_palindrome)
			palindromes.push_back(*it);
	}

	return palindromes;
}

//寻找最长单词
string findLongestWord(const vector<string>& words)
{
	string::size_type maxlen = 0;
	string longest_word;
	for (auto it = words.begin(); it != words.end(); ++it)
	{
		if (maxlen < (*it).size())
		{
			maxlen = (*it).size();
			longest_word = *it;
		}
	}

	return longest_word;
}

//寻找上下行单词
bool isScender(const string& word)
{
	for (string::size_type i = 0; i < word.size(); i++)
	{
		switch (word[i])
		{
		case'a':
		case'b':
		case'd':
		case'f':
		case'h':
		case'k':
		case'l':
		case't':
			return true;
		case'g':
		case'j':
		case'p':
		case'q':
		case'y':
			return true;
		default:
			break;
		}
	}

	return false;
}