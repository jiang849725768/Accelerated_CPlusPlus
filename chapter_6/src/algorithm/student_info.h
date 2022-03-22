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
bool compareStudents(const Student_info& , const Student_info&);

//����ѧ������
bool readStudents(Student_info&);

//�������һ����Ϊ��nobody����ѧ������ɼ�
Student_info randomStudent();

//5.1.1�е�extract_fails����
std::vector<Student_info> extract_fails_origin(std::vector<Student_info>&);

//ϰ��5.6��дextract_fails����
std::vector<Student_info> extract_fails_new(std::vector<Student_info>&);

#endif