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
			questionZero();
			break;
		case '1':
			//练习X.1
			questionOne();
			break;
		case '2':
			//练习X.2
			questionTwo();
			break;
		case '3':
			//练习X.3
			questionThree();
			break;
		case '4':
			//练习X.4
			questionFour();
			break;
		case '5':
			//练习X.5
			questionFive();
			break;
		case '6':
			//练习X.6
			questionSix();
			break;
		case '7':
			//练习X.7
			questionSeven();
			break;
		case '8':
			//练习X.8
			questionEight();
			break;
		case '9':
			//练习X.9
			questionNine();
			break;
		case 't':
			//练习X.10
			questionTen();
			break;
		case 'e':
			//练习X.11
			questionEleven();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}