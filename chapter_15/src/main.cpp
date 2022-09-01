#include <cstdio>
#include <iostream>

#include "question.h"

using namespace std;

int main()
{
	cout << "输入题号(1~11): (q退出,t for 10, e for 11): ";
	char label{};
	while (cin >> label)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (label == 'q')
			break;

		cout << "题目 " << label << ":" << endl;

		switch (label)
		{
		case '0':
			//chapter_15
			questionZero();
			break;
		case '1':
			//练习15-1
			questionOne();
			break;
		case '2':
			//练习15-2
			questionTwo();
			break;
		case '3':
			//练习15-3
			questionThree();
			break;
		case '4':
			//练习15-4
			questionFour();
			break;
		case '5':
			//练习15-5
			questionFive();
			break;
		case '6':
			//练习15-6
			questionSix();
			break;
		case '7':
			//练习15-7
			questionSeven();
			break;
		case '8':
			//练习15-8
			questionEight();
			break;
		case '9':
			//练习15-9
			questionNine();
			break;
		case 't':
			//练习15-10
			questionTen();
			break;
		case 'e':
			//练习15-11
			questionEleven();
			break;
		default:
			printf_s("无该题目\n");
			break;
		}

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.clear();
		cout << "输入题号(1~11): (q退出,t for 10, e for 11): ";
	}

	return 0;
}
