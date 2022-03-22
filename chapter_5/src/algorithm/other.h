#ifndef GUARD_other_h
#define GUARD_other_h

#include <vector>
#include <string>

//�ַ����ָ�
std::vector<std::string> split(const std::string&);

//Ѱ�Ҳ���ȡСд����
std::vector<std::string> extractLower(std::vector<std::string>&);

//Ѱ�һ��ĵ���
std::vector<std::string> findPalindromes(const std::vector<std::string>&);

//Ѱ�������
std::string findLongestWord(const std::vector<std::string>&);

//Ѱ�������е���
bool isScender(const std::string&);

#endif