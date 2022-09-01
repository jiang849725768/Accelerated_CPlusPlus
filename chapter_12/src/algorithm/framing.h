#ifndef GUARD_framing_h
#define GUARD_framing_h

#include <string>
#include <vector>

#include "Vec.h"
#include "Str_new.h"

//求最大行长度
Str_new::size_type maxWidth(const Vec<Str_new>&);

//居中填充字符串组
Vec<Str_new> center(const Vec<Str_new>&);

//输出字符串组
void printfOut(Vec<Str_new>&);

//随机生成字符串组
Vec<Str_new> genRanStr(int);

//字符串装框
Vec<Str_new> frame(const Vec<Str_new>&);

//字符串横向连接
Vec<Str_new> heat(const Vec<Str_new>&, const Vec<Str_new>&);

//字符串横向连接(5.8)
Vec<Str_new> heat_change(const Vec<Str_new>&, const Vec<Str_new>&);

#endif // !GUARD_framing_h
