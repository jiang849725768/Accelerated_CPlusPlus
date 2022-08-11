// ReSharper disable CppInconsistentNaming
#include "question.h"

#include "answer.h"
#include "book.h"
#include "chapter_seven.h"

using namespace std;

//chapter_X
void question_zero()
{
	//8.4
	string s;
	while (getline(cin, s))
		split(s, ostream_iterator<string>(cout, "\n"));
}

//8-1
void question_one()
{
}

//8-2
void question_two()
{
}

//8-3
void question_three()
{
	//若保证性能则只支持随机访问迭代器，否则需遍历迭代器，性能变差
}

//8-4
void question_four()
{
}

//8-5
void question_five()
{
	//7.3
	//auto ret = xref(cin, ostream_iterator<int>(cout, ","));
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
	auto sentence = genSentence(readGrammar(cin),ostream_iterator<string>(cout," "));
	cout << endl;
}

//8-6
void question_six()
{
	//一个包含元素为数对的可产生输出迭代器的容器
	//一个包含元素为数对的可产生输入迭代器的容器
}

//8-7
void question_seven()
{
	//防止因两个类型无法比较产生的错误在编译时无法显示？
}

//8-8
void question_eight()
{
	// 可以避免溢出
	// https://stackoverflow.com/questions/38688028/why-prefer-start-end-start-2-over-start-end-2-when-calculating-the
}
