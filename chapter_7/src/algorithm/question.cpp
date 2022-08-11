#include "question.h"

using namespace std;

//chapter_7
void question_zero()
{
	/* 7.3
	auto ret = xref(cin);

	for (auto it = ret.begin(); it != ret.end(); it++)
	{
		cout << it->first << " occurs in lines: ";
		auto line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			cout << "," << *line_it;
			++line_it;
		}
		cout << endl;	//换新行
	}
	*/

	/* 7.4.3 */
	vector<string> sentence = genSentence(readGrammar(cin));

	//若第一个单词存在，输出它
	auto it = sentence.begin();
	if (!sentence.empty())
	{
		cout << *it;
		it++;
	}

	//输出剩余单词，以空格分割
	while (it != sentence.end())
	{
		cout << " " << *it;
		++it;
	}

	cout << endl;
	/**/
}

//7-1
void question_one()
{
	string the_sentense;
	map<string, int> counters;
	map<int, vector<string>> words_list;

	the_sentense.resize(100); //scanf读取string，预先分配空间
	getline(cin, the_sentense);
	auto i = the_sentense.begin();
	while (i != the_sentense.end())
	{
		i = find_if(i, the_sentense.end(), isNotSpace);			//定位非空开头
		auto j = find_if(i, the_sentense.end(), isspace);		//定位单词结尾

		//复制[i, j)中字符
		if (i != the_sentense.end())
			++counters[string(i, j)];
		i = j;
	}

	for (auto it = counters.begin(); it != counters.end(); it++) {
		words_list[it->second].push_back(it->first);
	}
	int word_num = 1;
	while (words_list.find(word_num) != words_list.end()) {
		printf_s("%d\t", word_num);
		for (auto it = words_list[word_num].begin(); it != words_list[word_num].end(); it++) {
			printf_s((*it).c_str());
		}
		putchar('\n');
		word_num++;
	}
}

//7-2
void question_two()
{
}

//7-3
void question_three()
{
	auto ret = xrefNew(cin);

	for (auto it = ret.begin(); it != ret.end(); it++)
	{
		cout << it->first << " occurs in lines: ";
		auto line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			cout << "," << *line_it;
			++line_it;
		}
		cout << endl;	//换新行
	}
}

//7.4
void question_four()
{
	auto ret = xrefNew(cin);

	for (auto it = ret.begin(); it != ret.end(); it++)
	{
		cout << it->first;
		if (it->first.length() >= 10)
			cout << '\n';
		else
			cout << ' ';
		cout << "occurs in lines: ";
		auto line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			cout << "," << *line_it;
			++line_it;
		}
		cout << endl;	//换新行
	}
}

//7.5
void question_five()
{
	ifstream ifs;
	ifs.open("../../resource/grammar.txt", ios::in);
	list<string> sentence = genSentence(readGrammarL(ifs));
	ifs.close();

	//若第一个单词存在，输出它
	auto it = sentence.begin();
	if (!sentence.empty())
	{
		cout << *it;
		it++;
	}

	//输出剩余单词，以空格分割
	while (it != sentence.end())
	{
		cout << " " << *it;
		++it;
	}

	cout << endl;
}

//7.6
void question_six()
{
	ifstream ifs;
	ifs.open("../../resource/grammar.txt", ios::in);
	vector<string> sentence = genSentenceNew(readGrammar(ifs));
	ifs.close();

	//若第一个单词存在，输出它
	auto it = sentence.begin();
	if (!sentence.empty())
	{
		cout << *it;
		it++;
	}

	//输出剩余单词，以空格分割
	while (it != sentence.end())
	{
		cout << " " << *it;
		++it;
	}

	cout << endl;
}

//7.7
void question_seven()
{
	auto ret = xrefNew(cin);

	for (auto it = ret.begin(); it != ret.end(); it++)
	{
		if (it->second.size() == 1)
			cout << it->first << " occurs in line: ";
		else
			cout << it->first << " occurs in lines: ";
		auto line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			cout << "," << *line_it;
			++line_it;
		}
		cout << endl;	//换新行
	}
}

//7.8
void question_eight()
{
	auto ret = xrefNew(cin, findUrls);

	for (auto it = ret.begin(); it != ret.end(); it++)
	{
		cout << it->first << " occurs in lines: ";
		auto line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			cout << "," << *line_it;
			++line_it;
		}
		cout << endl;	//换新行
	}
}

//7.9
void question_nine()
{
	//pass
}