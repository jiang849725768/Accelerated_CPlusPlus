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
			//chapter_7
			question_zero();
			break;
		case '1':
			//练习7.1
			question_one();
			break;
		case '2':
			//练习7.2
			question_two();
			break;
		case '3':
			//练习7.3
			question_two();
			break;
		case '4':
			//练习7.4
			question_two();
			break;
		case '5':
			//练习7.5
			question_five();
			break;
		case '6':
			//练习7.6
			question_six();
			break;
		case '7':
			//练习7.7
			question_seven();
			break;
		case '8':
			//练习7.8
			question_eight();
			break;
		case '9':
			//练习7.9
			question_nine();
			break;
		case 't':
			//练习7.10
			question_ten();
			break;
		case 'e':
			//练习7.11
			question_eleven();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}