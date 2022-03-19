#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>
#include <ctime>
#include <typeinfo>
#include <exception>

#include "question.h"
#include "grade.h"
#include "student_info.h"
#include "framing.h"

using namespace std;

//5.1
int question_one()
{
	//nothing
	return 0;
}

//5.2  5.3
//����ѧ���ɼ�
void question_two()
{
	//��ѧ���б����Ͷ���Ϊlist/vector
	//printf_s("����ѧ���б�����('l'for list, 'v' for vector):");
	//char label = getchar();
	//char cl = getchar();
	//if (label == 'l')
	//{
	//	printf_s("\nѧ������: list\n");
	//	typedef std::list<Student_info> students_type;
	//	extern students_type;
	//}
	//else if (label == 'v'){
	//	printf_s("\nѧ������: vector\n");
	//	typedef std::vector<Student_info> students_type;
	//	extern students_type;
	//}
	//else
	//	throw domain_error("Wrong Enter");

	//��ѧ���б����Ͷ���Ϊlist/vector
	typedef std::vector<Student_info> students_type;
	//typedef std::list<Student_info> students_type;

	students_type students{};

	printf_s(typeid(students).name());
	putchar('\n');

	//ѧ������
	int students_num = 10000;

	for (int i = 0; i < students_num; i++)
	{
		students.push_back(randomStudent());
	}

	//��ʱ��ʼ
	clock_t start_time = clock();

	//��ȡ�ҿ�ѧ��
	students_type fail_students{};

	students_type::const_iterator iter = students.begin();

	while (iter != students.end())
	{
		if (grade(*iter) < 60)
		{
			fail_students.push_back(*iter);
			iter = students.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	//��ʱ����
	clock_t end_time = clock();

	double consumeTime = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;//ע��ת��Ϊdouble��λ��

	auto fail_students_count = fail_students.size();

	printf_s("�ҿ�ѧ����: %llu\n", fail_students_count);
	printf_s("������ʱ��%.2lf\n", consumeTime);
}

void question_five()
{
	auto some_strings = genRanStr(9);
	//vector<string> some_strings = {"a", "b", "c"};
	auto center_strings = center(some_strings);
	auto maxlen = maxWidth(some_strings);
	cout << maxlen << endl;
	printfOut(center_strings);
}

void question_six()
{
	vector<Student_info> students_origin{};
	vector<Student_info> students_new{};
	int students_num = 10000;  //���ѧ������

	//�������ѧ��
	for (int i = 0; i < students_num; i++)
	{
		students_origin.push_back(randomStudent());
	}

	//��ʱ��ʼ
	clock_t start_time_origin = clock();

	auto fail_origin = extract_fails_origin(students_origin);

	//��ʱ����
	clock_t end_time_origin = clock();

	double duration_origin = (double)(end_time_origin - start_time_origin) * 1000.0 / CLOCKS_PER_SEC;

	printf_s("ԭ������ʱ��%.2lf\n", duration_origin);
	printf_s("������: %llu\n", fail_origin.size() + students_origin.size());

	//�������ѧ��
	for (int i = 0; i < students_num; i++)
	{
		students_new.push_back(randomStudent());
	}

	//��ʱ��ʼ
	clock_t start_time_new = clock();

	auto fail_new = extract_fails_new(students_new);

	//��ʱ����
	clock_t end_time_new = clock();

	double duration_new = (double)(end_time_new - start_time_new) * 1000.0 / CLOCKS_PER_SEC;

	printf_s("�³�����ʱ��%.2lf\n", duration_new);
	printf_s("������: %llu\n", fail_new.size() + students_new.size());
}