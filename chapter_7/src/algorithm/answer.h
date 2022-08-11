#ifndef GUARD_answer_h
#define GUARD_answer_h

#include <map>
#include <string>
#include <vector>
#include <list>

#include "book.h"

typedef std::list<std::string> RuleL;
typedef std::list<RuleL> RuleL_collection;
typedef std::map<std::string, RuleL_collection> GrammarL;

//查找指向输入中每一个单词的全部行(7-3)
std::map<std::string, std::vector<int> > xrefNew(std::istream&,
	std::vector<std::string> findWords(const std::string&) = split);

//分割字符串(7-5)
std::list<std::string> splitNew(const std::string&);

//从特定输入流读入文法(7-5)
GrammarL readGrammarL(std::istream&);

//辅助生成函数(7-5)
void genAux(const GrammarL&, const std::string&, std::list<std::string>&);

//生成完整句子(7-5)
std::list<std::string> genSentence(const GrammarL&);

//辅助生成函数(7-6)
void genAuxNew(const Grammar&, const std::string&, std::vector<std::string>&, std::vector<std::string>&);

//生成完整句子(7-6)
std::vector<std::string> genSentenceNew(const Grammar&);

//判断是否为url字符，不是则true(7-8)
bool notUrlChar(char);

//找到包含"://"的url的开头(7-8)
std::string::const_iterator urlBegin(std::string::const_iterator, std::string::const_iterator);

//定位url的结尾(7-8)
std::string::const_iterator urlEnd(std::string::const_iterator, std::string::const_iterator);

//查找url(7-8)
std::vector<std::string> findUrls(const std::string&);

#endif
