#include "list_file_name.h"

#include <string>
#include <vector>
#include <io.h>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

//核心代码
void getFileNames(string path, vector<string>& files)
{
	//文件句柄
	//注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
	intptr_t hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,递归查找
			//如果不是,把文件绝对路径存入vector中
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFileNames(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		}
		while (_findnext(hFile, &fileinfo) == 0);
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
