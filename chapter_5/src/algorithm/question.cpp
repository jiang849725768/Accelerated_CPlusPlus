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
//����ѧ���ɼ�
int question_two()
{

	students_type students{};

	//ѧ������
	int students_num = 10000;

	for (int i = 0; i < students_num; i++)
	{
		students.push_back(randomStudent());
	}

	//��ʱ��ʼ
	clock_t start_time = clock();

	//��ȡ�ҿ�ѧ��
	auto fail_students = extractFailStudents(students);

	//��ʱ����
	clock_t end_time = clock();

	double consumeTime = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;//ע��ת��Ϊdouble��λ��
	
	auto fail_students_count = fail_students.size();

	printf_s("�ҿ�ѧ����: %llu", fail_students_count);
	printf_s("������ʱ��%.2lf", consumeTime);


	return 0;
}