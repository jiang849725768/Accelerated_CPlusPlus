#ifndef GUARD_other_h
#define GUARD_other_h

#include <vector>
#include <string>

//字符串分割
std::vector<std::string> split(const std::string&);

//寻找并提取小写单词
std::vector<std::string> extractLower(std::vector<std::string>&);

//寻找回文单词
std::vector<std::string> findPalindromes(const std::vector<std::string>&);

//寻找最长单词
std::string findLongestWord(const std::vector<std::string>&);

//寻找上下行单词
bool isScender(const std::string&);

#endif