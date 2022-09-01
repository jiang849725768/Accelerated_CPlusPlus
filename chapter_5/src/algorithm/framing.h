#ifndef GUARD_framing_h
#define GUARD_framing_h

#include <string>
#include <vector>

//求最大行长度
std::string::size_type maxWidth(const std::vector<std::string>&);

//居中填充字符串组
std::vector<std::string> center(const std::vector<std::string>&);

//输出字符串组
void printfOut(const std::vector<std::string>&);

//随机生成字符串组
std::vector<std::string> genRanStr(const int);

//字符串装框
std::vector<std::string> frame(const std::vector<std::string>&);

//字符串横向连接
std::vector<std::string> heat(const std::vector<std::string>&, const std::vector<std::string>&);

//字符串横向连接(5.8)
std::vector<std::string> heat_change(const std::vector<std::string>&, const std::vector<std::string>&);

#endif // !GUARD_framing_h
