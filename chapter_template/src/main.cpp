#include <cstdio>
#include <iostream>

#include "question.h"

using namespace std;

int main()
{
	//printf_s("输入题号(1~x):");
	while (true)
	{
		printf_s("输入题号(1~x): (输入q退出)");
		char label = getchar();
		//读取并忽略回车
		char cl = getchar();

		printf_s("题目 %c:\n", label);

		switch (label)
		{
		case '1':
			//练习x.1
			question_one();
			break;
		default:
			break;
		}

		if (label == 'q')
			break;
	}

	return 0;
}