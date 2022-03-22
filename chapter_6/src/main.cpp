#include <cstdio>
#include <iostream>

#include "question.h"

using namespace std;

int main()
{
	//printf_s("输入题号(1~9):");
	while (true)
	{
		printf_s("输入题号(1~9): (输入q退出)");
		char label = getchar();
		//读取并抛弃回车
		char cl = getchar();

		cout << label << endl;

		switch (label)
		{
		case '1':
			//练习6.1
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