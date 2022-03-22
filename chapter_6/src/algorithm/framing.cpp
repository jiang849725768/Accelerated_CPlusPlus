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
	uniform_int_distribution<int> random_string_length(1, 30);
	uniform_int_distribution<int> random_char(0, 35);

	for (int i = 0; i < length; i++) {
		a_string = "";
		int string_lenth = random_string_length(rng);
		for (int j = 0; j < string_lenth; j++) {
			tmp = random_char(rng) % 36;	// ���һ��С�� 36 ��������0-9��A-Z �� 36 ���ַ�
			if (tmp < 10) {			// ��������С�� 10���任��һ�����������ֵ� ASCII
				tmp += '0';
			}
			else {				// ���򣬱任��һ����д��ĸ�� ASCII
				tmp -= 10;
				tmp += 'A';
			}
			a_string += tmp;
		}
		some_strings.push_back(a_string);
	}

	return some_strings;
}