﻿#include <cstdio>
#include <iostream>
#include <string>

#include "question.h"

using namespace std;

int main()
{
	while (true)
	{
		printf_s("输入题号(1~11): (q退出,t for 10, e for 11)");
		char label = getchar();
		//读取并抛弃回车
		char cl = getchar();

		cout << label << endl;

		switch (label)
		{
		case '1':
			//练习5.1
			question_one();
			break;
		case '2':
			//练习5.2
			question_two();
			break;
		case '3':
			//练习5.3
			question_two();
			break;
		case '4':
			//练习5.4
			question_two();
			break;
		case '5':
			//练习5.5
			question_five();
			break;
		case '6':
			//练习5.6
			question_six();
			break;
		case '7':
			//练习5.7
			question_seven();
			break;
		case '8':
			//练习5.8
			question_eight();
			break;
		case '9':
			//练习5.9
			question_nine();
			break;
		case 't':
			//练习5.10
			question_ten();
			break;
		case 'e':
			//练习5.11
			question_eleven();
			break;
		default:
			break;
		}

		if (label == 'q')
			break;
	}

	//练习5.8
	//练习5.9
	//练习5.10
	//练习5.11

	return 0;
}