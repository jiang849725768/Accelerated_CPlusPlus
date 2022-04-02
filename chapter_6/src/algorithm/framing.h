#ifndef GUARD_framing_h
#define GUARD_framing_h

#include <string>
#include <vector>

//求最大行长度
std::string::size_type maxWidth(const std::vector<std::string>&);

//输出字符串组
void printfOut(const std::vector<std::string>&);

//随机生成字符串组(指定数量)
std::vector<std::string> genRanStr(const int);

//字符串装框
std::vector<std::string> frame(const std::vector<std::string>&);

//字符串横向连接
std::vector<std::string> heat(const std::vector<std::string>&, const std::vector<std::string>&);

//迭代器字符串装框(6-1)
std::vector<std::string> frameIterator(const std::vector<std::string>&);

//迭代器字符串横向连接(6-1)
std::vector<std::string> heatIterator(const std::vector<std::string>&, const std::vector<std::string>&);

//拼接字符串组(6-9)
std::string conectStrings(const std::vector<std::string>&);

#endif // !GUARD_framing_h
