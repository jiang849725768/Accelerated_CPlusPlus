#include "other.h"
#include <cctype>

using namespace std;

//�ַ����ָ�
vector<string> split(const string& a_string)
{
	vector<string> ret;
	string::size_type i = 0;

	while (i != a_string.size())
	{
		//����ǰ�˿հף��ҵ���һ���ǿո��ַ�
		while (i != a_string.size() && isspace(a_string[i]))
			++i;

		//�ҵ������ս��
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

//Ѱ�Ҳ���ȡСд����
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

		//�ж��Ƿ�ΪСд����
		if (is_lower)
		{
			lower_words.push_back(*it);
			it = words.erase(it);
			//��ֹ��Чָ��
			if (it == words.end())
				break;
		}
	}

	return lower_words;
}

//Ѱ�һ��ĵ���
vector<string> findPalindromes(const vector<string>& words)
{
	vector<string> palindromes;

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++)
	{
		//��ȡ���ʳ���
		auto word_length = (*it).size();
		bool is_palindrome = true;

		//ѭ���жϵ���������һ��
		for (string::size_type i = 0; i < word_length / 2; i++)
		{
			//���ģ�word[i] = word[length - i -1]
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

//Ѱ�������
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

//Ѱ�������е���
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