#include "chapter_seven.h"

#include <algorithm>
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

//生成[0,n)间的随机整数
size_t nrand(const int n)
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

	const auto r = uint_dist(rng);

	return r;
}

//判断非空格字符
bool isNotSpace(const char c)
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
			ret.push_back(string(i, j));  // NOLINT(modernize-use-emplace)
		i = j;
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
std::list<std::string> genAux(const Grammar& g, const std::string& word, ostream_iterator<string>& out)
{
	list<string> ret;
	if (!bracketed(word))
	{
		*out++ = word; //返回单词而非种类给输出迭代器
		ret.push_back(word);
	}
	else
	{
		const auto it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		const Rule_collection& c = it->second;

		for (const Rule& r = c[nrand(static_cast<int>(c.size()))]; const auto& i : r)
			genAux(g, i, out);
	}

	return ret;
}