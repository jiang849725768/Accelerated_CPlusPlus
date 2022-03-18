#include <cstdio>
#include <list>
#include <vector>
#include <random>
#include <ctime>

#include "question.h"
#include "student_info.h"

using namespace std;

//5.1
int question_one()
{
	//nothing
	return 0;
}

//5.2  5.3
//计算学生成绩
int question_two()
{

	students_type students{};

	//学生总数
	int students_num = 10000;

	for (int i = 0; i < students_num; i++)
	{
		students.push_back(randomStudent());
	}

	//计时开始
	clock_t start_time = clock();

	//提取挂科学生
	auto fail_students = extractFailStudents(students);

	//计时结束
	clock_t end_time = clock();

	double consumeTime = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;//注意转换为double的位置
	
	auto fail_students_count = fail_students.size();

	printf_s("挂科学生数: %llu", fail_students_count);
	printf_s("程序用时：%.2lf", consumeTime);


	return 0;
}