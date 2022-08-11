#include "answer.h"

using namespace std;

//查找指向输入中每一个单词的全部行(7-3)
std::map<std::string, std::vector<int> > xrefNew(std::istream& in, std::vector<std::string> findWords(const std::string&))
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while (getline(in, line))
	{
		++line_number;
		vector<string> words = findWords(line);
		for (auto it = words.begin(); it != words.end(); it++)
		{
			auto& word_line = ret[*it];
			//向量为空或无当前行数值则添加当前行数至向量
			if (word_line.empty())
				word_line.push_back(line_number);
			auto repeat_line = find(word_line.begin(), word_line.end(), line_number);
			if (repeat_line == word_line.end())
				word_line.push_back(line_number);
		}
	}

	return ret;
}

//分割字符串(7-5)
std::list<std::string> splitNew(const std::string& a_string)
{
	list<string> ret;
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

//从特定输入流读入文法(7-5)
GrammarL readGrammarL(std::istream& in)
{
	GrammarL ret;
	string line;

	while (getline(in, line)) {
		list<string> entry = splitNew(line);

		if (!entry.empty())
		{
			//将输入每行的第一个词作为键，其余作为值
			auto rule_name = *entry.begin();
			entry.erase(entry.begin());
			ret[rule_name].push_back(entry);
		}
	}

	return ret;
}

//辅助生成函数(7-5)
void genAux(const GrammarL& grammar_list, const std::string& word, std::list<std::string>& final_sentense)
{
	if (!bracketed(word))
	{
		final_sentense.push_back(word); //返回单词而非种类
	}
	else
	{
		GrammarL::const_iterator it = grammar_list.find(word);
		if (it == grammar_list.end())
			throw logic_error("empty rule");
		const RuleL_collection& rule_collection_list = it->second;
		auto rc_iter = rule_collection_list.begin();
		advance(rc_iter, nrand(rule_collection_list.size()));
		const RuleL& r = *rc_iter;

		for (auto i = r.begin(); i != r.end(); i++)
			genAux(grammar_list, *i, final_sentense);
	}
}

//生成完整句子(7-5)
std::list<std::string> genSentence(const GrammarL& the_grammar)
{
	list<string> final_sentense;
	//辅助生成函数
	genAux(the_grammar, "<sentence>", final_sentense);
	return final_sentense;
}

//辅助生成函数（7-6）
void gen_aux(const Grammar& g, const string& token,
	vector<string>& sentence, vector<string>& tokens) {
	if (!bracketed(token)) {
		sentence.push_back(token);
	}
	else {
		// locate the rule that corresponds to `token'
		Grammar::const_iterator it = g.find(token);

		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// from which we select one at random
		const Rule& r = c[nrand(c.size())];

		// push rule's tokens onto stack of tokens
		// (in reverse order, because we're pushing and popping from the back)
		for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
			tokens.push_back(*i);
	}
}

//生成完整句子(7-6)
std::vector<std::string> genSentenceNew(const Grammar& g)
{
	// 没想出来，答案来自 http://mathalope.co.uk/2014/10/19/accelerated-c-solution-to-exercise-7-6/
	vector<string> sentence;
	vector<string> tokens;
	tokens.push_back("<sentence>");

	while (!tokens.empty()) {
		string token = tokens.back();
		tokens.pop_back();
		gen_aux(g, token, sentence, tokens);
	}

	return sentence;
}

//判断是否为url字符，不是则true(7-8)
bool notUrlChar(char c)
{
	//除字母数字外其他可能出现在url里的字符
	static const string url_char = "~;/?:@=&$-_.+!*'(),";

	//判断c字符是否为url字符，返回取反结果
	return !(isalnum(c) || find(url_char.begin(), url_char.end(), c) != url_char.end());
}

//找到包含"://"的url的开头(7-8)
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

//定位url的结尾(7-8)
std::string::const_iterator urlEnd(std::string::const_iterator b,
	std::string::const_iterator e)
{
	return find_if(b, e, notUrlChar);
}

//查找url(7-8)
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