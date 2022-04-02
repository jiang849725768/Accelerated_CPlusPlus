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
		case '1':
			//练习X.1
			question_one();
			break;
		case '2':
			//练习X.2
			question_two();
			break;
		case '3':
			//练习X.3
			question_two();
			break;
		case '4':
			//练习X.4
			question_two();
			break;
		case '5':
			//练习X.5
			question_five();
			break;
		case '6':
			//练习X.6
			question_six();
			break;
		case '7':
			//练习X.7
			question_seven();
			break;
		case '8':
			//练习X.8
			question_eight();
			break;
		case '9':
			//练习X.9
			question_nine();
			break;
		case 't':
			//练习X.10
			question_ten();
			break;
		case 'e':
			//练习X.11
			question_eleven();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}