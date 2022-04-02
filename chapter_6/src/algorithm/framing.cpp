#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <numeric>
#include <iterator>

#include "framing.h"

using namespace std;

//������г���
string::size_type maxWidth(const vector<string>& some_strings)
{
	string::size_type maxlen = 0;
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
		maxlen = max(maxlen, (*it).size());
	return maxlen;
}

//����ַ�����
void printfOut(const vector<string>& some_strings)
{
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		cout << (*it) << endl;
	}
}

//��������ַ�����(ָ������)
//length: �����ַ�����ĳ���
vector<string> genRanStr(const int length)
{
	char tmp{};
	vector<string> some_strings{};
	string a_string;

	//�������ӷ�����
	random_device rd;
	//�������������������
	default_random_engine rng{ rd() };
	//ָ����������ͺͷ�Χ
	uniform_int_distribution<int> random_string_length(10, 40);
	uniform_int_distribution<int> random_char(0, 60);

	for (int i = 0; i < length; i++) {
		a_string = "";
		int string_lenth = random_string_length(rng);
		for (int j = 0; j < string_lenth; j++) {
			tmp = random_char(rng);			// ���һ�� 0-60 ��������a-z��A-Z �� 52 ���ַ�
			if (tmp > 51) {					// ������������ 51���任��һ���ո�� ASCII
				tmp = ' ';
			}
			else if (tmp < 26) {			// ��������С�� 26���任��һ��Сд��ĸ�� ASCII
				tmp += 'a';
			}
			else {							// ����������任��һ����д��ĸ�� ASCII
				tmp -= 26;
				tmp += 'A';
			}
			a_string += tmp;
		}
		some_strings.push_back(a_string);
	}

	return some_strings;
}

//�ַ���װ��
std::vector<std::string> frame(const std::vector<std::string>& some_strings)
{
	vector<string> ret;
	auto maxlen = maxWidth(some_strings);
	string border(maxlen + 4, '*');

	//�ϱ߿�
	ret.push_back(border);

	//�ڲ���
	for (vector<string>::size_type i = 0; i != some_strings.size(); ++i)
	{
		ret.push_back("* " + some_strings[i] + string(maxlen - some_strings[i].size(), ' ') + " *");
	}

	//�±߿�
	ret.push_back(border);

	return ret;
}

//�ַ�����������
vector<string> heat(const vector<string>& left_strings, const vector<string>& right_strings)
{
	vector<string> ret;

	string::size_type left_width = maxWidth(left_strings);

	vector<string>::size_type i = 0, j = 0;

	while (i != left_strings.size() || j != right_strings.size())
	{
		//���ڱ������Ӻ�����ַ���
		string s;

		if (i != left_strings.size())
			s = left_strings[i++];

		//��䣬ͬʱ������֮����һ���ո�
		s += string(left_width + 1 - s.size(), ' ');

		if (j != right_strings.size())
			s += right_strings[j++];

		ret.push_back(s);
	}

	return ret;
}

//�������ַ���װ��(6-1)
std::vector<std::string> frameIterator(const std::vector<std::string>& some_strings)
{
	vector<string> ret;
	auto maxlen = maxWidth(some_strings);
	string border(maxlen + 4, '*');

	//�ϱ߿�
	ret.push_back(border);

	//�ڲ���
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		ret.push_back("* " + (*it) + string(maxlen - (*it).size(), ' ') + " *");
	}

	//�±߿�
	ret.push_back(border);

	return ret;
}

//�������ַ�����������(6-1)
vector<string> heatIterator(const vector<string>& left_strings, const vector<string>& right_strings)
{
	vector<string> ret;

	string::size_type left_width = maxWidth(left_strings);

	auto lit = left_strings.begin();
	auto rit = right_strings.begin();

	while (lit != left_strings.end() || rit != right_strings.end())
	{
		//���ڱ������Ӻ�����ַ���
		string s;

		if (lit != left_strings.end())
			s = (*lit++);

		//��䣬ͬʱ������֮����һ���ո�
		s += string(left_width + 1 - s.size(), ' ');

		if (rit != right_strings.end())
			s += (*rit++);

		ret.push_back(s);
	}

	return ret;
}

//ƴ���ַ�����(6-9)
std::string conectStrings(const std::vector<std::string>& some_strings)
{
	string new_string;
	new_string = accumulate(some_strings.begin(), some_strings.end(), new_string);

	return new_string;
}