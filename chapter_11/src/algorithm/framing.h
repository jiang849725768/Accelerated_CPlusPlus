#ifndef GUARD_FRAMING_H
#define GUARD_FRAMING_H

#include <string>
#include <vector>

#include "Vec.h"

//求最大行长度
std::string::size_type maxWidth(const Vec<std::string>&);

//居中填充字符串组
Vec<std::string> center(const Vec<std::string>&);

//输出字符串组
void printfOut(const Vec<std::string>&);

//随机生成字符串组
Vec<std::string> genRanStr(int);

//字符串装框
Vec<std::string> frame(const Vec<std::string>&);

//字符串横向连接
Vec<std::string> heat(const Vec<std::string>&, const Vec<std::string>&);

//字符串横向连接(5.8)
Vec<std::string> heatChange(const Vec<std::string>&, const Vec<std::string>&);

#endif
