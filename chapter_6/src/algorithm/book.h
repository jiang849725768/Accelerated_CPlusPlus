#ifndef GUARD_book_h
#define GUARD_book_h

#include <vector>
#include <string>

//判断非空格字符
bool isNotSpace(char);

//分割字符串
std::vector<std::string> split(const std::string&);

//判断是否为url字符，不是则true
bool notUrlChar(char);

//找到包含"://"的url的开头
std::string::const_iterator urlBegin(std::string::const_iterator, std::string::const_iterator);

//定位url的结尾
std::string::const_iterator urlEnd(std::string::const_iterator, std::string::const_iterator);

//查找url
std::vector<std::string> findUrls(const std::string&);

#endif