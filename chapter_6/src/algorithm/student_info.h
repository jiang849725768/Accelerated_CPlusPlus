#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <string>
#include <vector>
#include <list>

struct Student_info {
	std::string name;
	double midterm_grade = 0;
	double final_grade = 0;
	std::vector<double> homework_grades;
};

//����ѧ��������������
bool compareStudents(const Student_info&, const Student_info&);

//�ҵ�ͨ�����Ե�ѧ��
bool pgrade(const Student_info&);

//�ҵ�δͨ�����Ե�ѧ��
bool fgrade(const Student_info&);

//����ѧ������
bool readStudents(Student_info&);

//�������һ����Ϊ��nobody����ѧ������ɼ�
Student_info randomStudent();

//��ȡ�ҿ�ѧ��(6.3.1)��2�ɼ�����ÿѧ��ÿ�Σ�
std::vector<Student_info> extractFails(std::vector<Student_info>&);

//��ȡ�ҿ�ѧ��(6.3.2)��1�ɼ�����ÿѧ��ÿ�Σ�
std::vector<Student_info> greaterExtractFails(std::vector<Student_info>&);

//�ж�ѧ���Ƿ��������еļ�ͥ��ҵ(6.2.1)
bool didAllHomework(const Student_info&);

//��ȡδ���ȫ����ͥ��ҵѧ��(6-7)��1�ɼ�����ÿѧ��ÿ�Σ�
std::vector<Student_info> extractDidnt(std::vector<Student_info>&);

#endif