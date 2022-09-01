#include <cstdio>
#include <iostream>

#include "question.h"

using namespace std;

int main()
{
	//printf_s("输入题号(1~x):");
	while (true)
	{
		cin.clear();
		printf_s("输入题号(1~11): (q退出,t for 10, e for 11)");
		char label;
		cin >> label;
		cin.clear();

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
			//练习13-1
			questionOne();
			break;
		case '2':
			//练习13-2
			questionTwo();
			break;
		case '3':
			//练习13-3
			questionThree();
			break;
		case '4':
			//练习13-4
			questionFour();
			break;
		case '5':
			//练习13-5
			questionFive();
			break;
		case '6':
			//练习13-6
			questionSix();
			break;
		case '7':
			//练习13-7
			questionSeven();
			break;
		case '8':
			//练习13-8
			questionEight();
			break;
		case '9':
			//练习13-9
			questionNine();
			break;
		case 't':
			//练习13-10
			questionTen();
			break;
		case 'e':
			//练习13-11
			questionEleven();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}
	}

	return 0;
}
