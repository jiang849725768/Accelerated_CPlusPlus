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

//��ѧ���б����Ͷ���Ϊlist/vector
typedef std::vector<Student_info> students_type;

//����ѧ��������������
bool compareStudents(const Student_info& , const Student_info&);

//����ѧ������
bool readStudents(Student_info&);

//�������һ����Ϊ��nobody����ѧ������ɼ�
Student_info randomStudent();

//��ȡ�ҿ�ѧ����¼
students_type extractFailStudents(students_type&);

#endif