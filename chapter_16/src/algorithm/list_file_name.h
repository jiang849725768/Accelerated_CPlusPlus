#ifndef GUARD_LIST_FILE_NAME_H
#define GUARD_LIST_FILE_NAME_H
#include <string>
#include <vector>
#include <Windows.h>


//核心函数
void getFileNames(std::string path, std::vector<std::string>& files);

//测试代码
void printFileNames();

WCHAR* utf8ToUnicode(const char* str);

#endif
