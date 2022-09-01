#ifndef GUARD_framing_h
#define GUARD_framing_h

#include <string>
#include <vector>

#include "Vec.h"
#include "Str.h"

bool isNotSpace(char ch);

//求最大行长度
Str::size_type maxWidth(const Vec<Str>&);

//居中填充字符串组
Vec<Str> center(const Vec<Str>&);

//输出字符串组
void printfOut(Vec<Str>&);

//随机生成字符串组
Vec<Str> genRanStr(int);

//字符串装框
Vec<Str> frame(const Vec<Str>&);

//字符串横向连接
Vec<Str> heat(const Vec<Str>&, const Vec<Str>&);

//字符串横向连接(5.8)
Vec<Str> heat_change(const Vec<Str>&, const Vec<Str>&);

#endif // !GUARD_framing_h
