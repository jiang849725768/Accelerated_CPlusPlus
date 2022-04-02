#include "book.h"
#include <cctype>
#include <algorithm>

using namespace std;

//�жϷǿո��ַ�
bool isNotSpace(char c)
{
	return !isspace(c);
}

//�ָ��ַ���
std::vector<std::string> split(const std::string& a_string)
{
	vector<string> ret;
	auto i = a_string.begin();
	while (i != a_string.end())
	{
		i = find_if(i, a_string.end(), isNotSpace);			//��λ�ǿտ�ͷ
		auto j = find_if(i, a_string.end(), isspace);		//��λ���ʽ�β

		//����[i, j)���ַ�
		if (i != a_string.end())
			ret.push_back(string(i, j));
		i = j;
	}

	return ret;
}

//�ж��Ƿ�Ϊurl�ַ���������true
bool notUrlChar(char c)
{
	//����ĸ�������������ܳ�����url����ַ�
	static const string url_char = "~;/?:@=&$-_.+!*'(),";

	//�ж�c�ַ��Ƿ�Ϊurl�ַ�������ȡ�����
	return !(isalnum(c) || find(url_char.begin(), url_char.end(), c) != url_char.end());
}

//�ҵ�����"://"��url�Ŀ�ͷ
std::string::const_iterator urlBegin(std::string::const_iterator b,
	std::string::const_iterator e)
{
	static const string sep = "://";
	string::const_iterator i = b;			//iΪ�ָ�����ͷλ��

	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		if (i != b && i + sep.size() != e)
		{
			string::const_iterator beg = i;	//begΪurl��ͷλ��

			while (beg != b && isalpha(beg[-1]))
				--beg;

			//ȷ���ָ���ǰ��ǿ�
			if (beg != i && !notUrlChar(i[sep.size()]))
				return beg;
		}

		i += sep.size();
	}

	return e;
}

//��λurl�Ľ�β
std::string::const_iterator urlEnd(std::string::const_iterator b,
	std::string::const_iterator e)
{
	return find_if(b, e, notUrlChar);
}

//����url
std::vector<std::string> findUrls(const string& long_string)
{
	vector<string> ret;
	auto b = long_string.begin(), e = long_string.end();

	while (b != e)
	{
		//�ҵ�����"://"��url�Ŀ�ͷ
		b = urlBegin(b, e);

		if (b != e) {
			//��λurl�Ľ�β
			auto after = urlEnd(b, e);
			//���url
			ret.push_back(string(b, after));
			//�ƽ�b����ǰurl�Ľ�β��������
			b = after;
		}
	}
	return ret;
}