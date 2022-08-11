#include "book.h"

using namespace std;

//生成[0,n)间的随机整数
size_t nrand(int n)
{
	/* book way
	if (n <= 0 || n > RAND_MAX) //RAND_MAX:<cstdlib>中定义的大整数
		throw domain_error("Argument to nrand is out of range");

	const size_t bucket_size = RAND_MAX / n;
	size_t r = 0;

	do {
		r = rand() / bucket_size;
	} while (r >= n);
	*/

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> uint_dist(0, n - 1); // distribution in range [0, n)

	auto r = uint_dist(rng);

	return r;
}

//判断非空格字符
bool isNotSpace(char c)
{
	return !isspace(c);
}

//判断单词是否代表种类
bool bracketed(const std::string s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
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

//查找指向输入中每一个单词的全部行(7.3)
std::map<std::string, std::vector<int> > xref(std::istream& in,
	std::vector<std::string> findWords(const std::string&))
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while (getline(in, line))
	{
		++line_number;
		vector<string> words = findWords(line);
		for (auto it = words.begin(); it != words.end(); it++)
			ret[*it].push_back(line_number);
	}

	return ret;
}

//从特定输入流读入文法
Grammar readGrammar(std::istream& in)
{
	/* 程序的输入
	<noun> cat
	<noun> dog
	<noun> table
	<noun-phrase> <noun>
	<noun-phrase> <adjective> <noun-phrase>
	<adjective> large
	<adjective> brown
	<adjective> absurd
	<verb> jumps
	<verb> sits
	<location> on the stairs
	<location> under the sky
	<location> wherever it wants
	<sentence> the <noun-phrase> <verb> <location>

	*/
	Grammar ret;
	string line;
	while (getline(in, line)) {
		vector<string> entry = split(line);

		if (!entry.empty())
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end())); //将输入每行的第一个词作为键，其余作为值
	}

	return ret;
}

//辅助生成函数
void genAux(const Grammar& g, const std::string& word, std::vector<std::string>& ret)
{
	if (!bracketed(word))
	{
		ret.push_back(word); //返回单词而非种类
	}
	else
	{
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		const Rule_collection& c = it->second;
		const Rule& r = c[nrand(c.size())];

		for (auto i = r.begin(); i != r.end(); i++)
			genAux(g, *i, ret);
	}
}

//生成完整句子
std::vector<std::string> genSentence(const Grammar& the_grammar)
{
	vector<string> ret;
	//辅助生成函数
	genAux(the_grammar, "<sentence>", ret);
	return ret;
}