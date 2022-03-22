#ifndef GUARD_framing_h
#define GUARD_framing_h

#include <string>
#include <vector>

//������г���
std::string::size_type maxWidth(const std::vector<std::string>&);

//��������ַ�����
std::vector<std::string> center(const std::vector<std::string>&);

//����ַ�����
void printfOut(const std::vector<std::string>&);

//��������ַ�����
std::vector<std::string> genRanStr(const int);

//�ַ���װ��
std::vector<std::string> frame(const std::vector<std::string>&);

//�ַ�����������
std::vector<std::string> heat(const std::vector<std::string>&, const std::vector<std::string>&);

//�ַ�����������(5.8)
std::vector<std::string> heat_change(const std::vector<std::string>&, const std::vector<std::string>&);

#endif // !GUARD_framing_h
