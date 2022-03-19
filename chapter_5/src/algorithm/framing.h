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


#endif // !GUARD_framing_h
