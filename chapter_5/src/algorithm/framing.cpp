#include <iostream>
#include <string>
#include <vector>
#include <random>

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

//��������ַ���
vector<string> center(const vector<string>& some_strings)
{
	auto maxlen = maxWidth(some_strings);
	vector<string> new_strings{};

	//����ϱ߿�
	string border(maxlen + 2, '*');
	new_strings.push_back(border);

	//��*���
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		string::size_type left_part_length = (maxlen - (*it).size()) / 2;
		auto right_part_length = maxlen - left_part_length - (*it).size();
		new_strings.push_back(string(left_part_length + 1, '*') + (*it) + string(right_part_length + 1, '*'));
	}

	//����±߿�
	new_strings.push_back(border);

	return new_strings;
}

//����ַ�����
void printfOut(const vector<string>& some_strings)
{
	for (auto it = some_strings.begin(); it != some_strings.end(); ++it)
	{
		cout << (*it) << endl;
	}
}

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

//�ַ�����������
vector<string> heat_change(const vector<string>& left_strings, const vector<string>& right_strings)
{
	vector<string> ret;

	string::size_type left_width = maxWidth(left_strings);

	vector<string>::size_type i = 0, j = 0;

	//���ڱ������Ӻ�����ַ���
	string s;

	while (i != left_strings.size() || j != right_strings.size())
	{
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