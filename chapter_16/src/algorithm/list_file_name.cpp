#include "list_file_name.h"

#include <string>
#include <vector>
#include <io.h>
#include <iostream>
#include <Windows.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

//核心代码
void getFileNames(string path, vector<string>& files)
{
	//文件句柄
	//注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
	//文件信息
	intptr_t hFile = 0;
	_finddata_t file_info;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &file_info)) != -1)
	{
		do
		{
			//如果是目录,递归查找
			//如果不是,把文件绝对路径存入vector中
			if ((file_info.attrib & _A_SUBDIR))
			{
				if (strcmp(file_info.name, ".") != 0 && strcmp(file_info.name, "..") != 0)
					getFileNames(p.assign(path).append("\\").append(file_info.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(file_info.name));
			}
		}
		while (_findnext(hFile, &file_info) == 0);
		_findclose(hFile);
	}
}

void printFileNames()
{
	vector<string> fileNames;
	string path(".."); //自己选择目录测试
	getFileNames(path, fileNames);
	for (const auto& ph : fileNames)
	{
		cout << ph << endl;
	}
}

WCHAR* utf8ToUnicode(const char* str)
{
	const int i = MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS, str, -1, nullptr, 0);

	const auto str_unicode = new WCHAR[i];

	MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS, str, -1, str_unicode, i);

	return str_unicode;
}
