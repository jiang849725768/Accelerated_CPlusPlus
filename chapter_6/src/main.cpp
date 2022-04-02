#include <cstdio>
#include <iostream>

#include "question.h"
#include "book.h"

using namespace std;

int main()
{
	while (true)
	{
		printf_s("输入题号(1~9): (输入q退出)");
		char label = getchar();
		//读取并忽略回车
		char cl = getchar();

		if (label == 'q')
			break;

		printf_s("题目 %c:\n", label);

		switch (label)
		{
		case '0':
			question_zero();
			break;
		case '1':
			//练习6.1
			question_one();
			break;
		case '2':
			//练习6.2
			question_two();
			break;
		case '3':
			//练习6.3
			question_three();
			break;
		case '4':
			//练习6.4
			question_four();
			break;
		case '5':
			//练习6.5
			question_five();
			break;
		case '6':
			//练习6.4
			question_six();
			break;
		case '7':
			//练习6.7
			question_seven();
			break;
		case '8':
			//练习6.8
			question_eight();
			break;
		case '9':
			//练习6.9
			question_nine();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}