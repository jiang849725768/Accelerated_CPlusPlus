#ifndef GUARD_book_h
#define GUARD_book_h

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <cctype>
#include <cstdlib>

typedef std::vector <std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

//生成[0,n)间的随机整数
size_t nrand(int);

//判断非空格字符
bool isNotSpace(char c);

//判断单词是否代表种类（以"<>"括起）
bool bracketed(const std::string s);

//分割字符串
std::vector<std::string> split(const std::string&);

//查找指向输入中每一个单词的全部行(7.3)
std::map<std::string, std::vector<int> > xref(std::istream&,
	std::vector<std::string> findWords(const std::string&) = split);

//从特定输入流读入文法
Grammar readGrammar(std::istream&);

//辅助生成函数
void genAux(const Grammar&, const std::string&, std::vector<std::string>&);

//生成完整句子
std::vector<std::string> genSentence(const Grammar&);

#endif