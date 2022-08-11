#include <cstdio>
#include <iostream>

#include "question.h"

using namespace std;

int main()
{
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
			//chapter_X
			question_zero();
			break;
		case '1':
			//练习8-1
			question_one();
			break;
		case '2':
			//练习8-2
			question_two();
			break;
		case '3':
			//练习8-3
			question_three();
			break;
		case '4':
			//练习8-4
			question_four();
			break;
		case '5':
			//练习8-5
			question_five();
			break;
		case '6':
			//练习8-6
			question_six();
			break;
		case '7':
			//练习8-7
			question_seven();
			break;
		case '8':
			//练习8-8
			question_eight();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}