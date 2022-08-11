#include "answer.h"

using std::vector;	using std::map;
using std::string;	using std::ostream_iterator;
using std::list;	using std::istream;
using std::cout;	using std::endl;

//查找指向输入中每一个单词的全部行(7.3)
map<string, vector<int> > xref(istream& in, ostream_iterator<int> out,
	vector<string> find_words(const std::string&))
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while (getline(in, line))
	{
		++line_number;
		for (vector<string> words = find_words(line); auto & word : words)
			ret[word].push_back(line_number);
	}
	for (auto & [fst, snd]:ret)
	{
		cout << fst << " occur in lines: ";
		for (const int& num : snd)
			*out++ = num;
		cout << endl;
	}

	return ret;
}

//生成完整句子
list<string> genSentence(const Grammar& the_grammar, ostream_iterator<string> out)
{
	//辅助生成函数
	list<string> ret = genAux(the_grammar, "<sentence>", out);
	return ret;
}