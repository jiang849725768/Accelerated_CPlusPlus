#ifndef GUARD_CHAPTER_SEVEN_H
#define GUARD_CHAPTER_SEVEN_H

#include <map>
#include <string>
#include <vector>
#include <random>
#include <list>
#include <iterator>


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

//从特定输入流读入文法
Grammar readGrammar(std::istream&);

//辅助生成函数
std::list<std::string> genAux(const Grammar&, const std::string&, std::ostream_iterator<std::string>&);

#endif