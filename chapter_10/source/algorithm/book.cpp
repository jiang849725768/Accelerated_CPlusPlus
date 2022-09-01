#include "book.h"

#include <string>
#include <algorithm>

using std::string;
using std::copy;

std::string letter_grade(double grade)
{
	//分数成绩的界限
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};
	//字母成绩表示
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};
	//根据数组大小及单个元素大小计算成绩个数
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
	//根据分数成绩得到相应字母成绩
	for (size_t i = 0; i < ngrades; i++)
	{
		if (grade >= numbers[i])
			return letters[i];
	}
	return "?\?\?";
}

//10.6.1
// ReSharper disable once CppInconsistentNaming
int* pointer_to_dynamic()
{
	return new int(0);
}

//10.6.2
char* duplicate_chars(const char* p)
{
	size_t length = strlen(p) + 1;
	auto result = new char[length];
	copy(p, p + length, result);
	return result;
}
