#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

#include "question.h"

using namespace std;

int main(int argc, char** argv)
{
	/*
	//10.4
	//显示可能存在的命令行参数
	if (argc > 1)
	{
		cout << argv[1];
		for (int i = 2; i != argc; i++)
		{
			cout << " " << argv[i];
		}
		cout << endl;
		return 0;
	}

	//10.5.2
	int fail_count = 0;
	for (int i = 1; i < argc; ++i)
	{
		ifstream in(argv[i]);
		//如果文件存在，复制其内容，否则生成错误信息
		if (in)
		{
			string s;
			while (getline(in, s))
				cout << s << endl;
		}
		else
		{
			cerr << "cannot open file " << argv[i] << endl;
			++fail_count;
		}
	}
	cout << "复制失败文件" << fail_count << "个" << endl;
*/

	//printf_s("输入题号(1~x):");
	while (true)
	{
		printf_s("输入题号(1~11): (q退出,t for 10, e for 11)");
		char label = getchar();
		//读取并忽略回车
		char cl = getchar();

		if (label == 'q')
			break;

		printf_s("题目 %c:\n", label);

		switch (label)
		{
		case '0':
			//chapter_10
			questionZero();
			break;
		case '1':
			//练习10-1
			questionOne();
			break;
		case '2':
			//练习10-2
			questionTwo();
			break;
		case '3':
			//练习10-3
			questionThree();
			break;
		case '4':
			//练习10-4
			questionFour();
			break;
		case '5':
			//练习10-5
			questionFive();
			break;
		case '6':
			//练习10-6
			questionSix();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}
