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


#endif // !GUARD_framing_h
