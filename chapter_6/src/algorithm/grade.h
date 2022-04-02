#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "student_info.h"

//����ɼ�ƽ����(6.2.3)
double averageGrade(const std::vector<double>);

//����ɼ���λ��
double medianGrade(std::vector<double>);

//����ѧ���ܳɼ���ָ�����㷽ʽ
double grade(const double, const double, const std::vector<double>&, double calculateGrade(const std::vector<double>));

double grade(const Student_info&);

//ָ��grade�汾�ĸ�������(6.2.2)
double gradeAux(const Student_info&);

//������ƽ���������ͥ��ҵ�ɼ�����ܳɼ�
double gradeAverage(const Student_info&);

//����ѧ���ֹ���ֵ���Ƴɼ�������0�֣���6.2.4��
double gradeOptimisticMedian(const Student_info&);

//��ȡѧ���ܳɼ�������λ������ͥ��ҵ����λ�����㣩��6.2.2��
double medianAnalysis(const std::vector<Student_info>&);

//��ȡѧ���ܳɼ�������λ������ͥ��ҵ��ƽ�������㣩��6.2.3��
double averageAnalysis(const std::vector<Student_info>&);

//��ȡѧ���ܳɼ�������λ������ͥ��ҵ���ֹ���λ�����㣩��6-5��
double optimisticGradeAnalysis(const std::vector<Student_info>&);

//��ȡѧ���ܳɼ�������λ������ͥ��ҵ��ָ����ʽ���㣩��6-6��
double gradeAnalysis(const std::vector<Student_info>&, double specialAnalysis(const Student_info&));

//���ѧ�����ϼ�ĳɼ����죨6.2.2��
void writeAnalysis(const std::string&, double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>&, const std::vector<Student_info>&);
#endif