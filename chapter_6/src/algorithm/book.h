#ifndef GUARD_book_h
#define GUARD_book_h

#include <vector>
#include <string>

//�жϷǿո��ַ�
bool isNotSpace(char);

//�ָ��ַ���
std::vector<std::string> split(const std::string&);

//�ж��Ƿ�Ϊurl�ַ���������true
bool notUrlChar(char);

//�ҵ�����"://"��url�Ŀ�ͷ
std::string::const_iterator urlBegin(std::string::const_iterator, std::string::const_iterator);

//��λurl�Ľ�β
std::string::const_iterator urlEnd(std::string::const_iterator, std::string::const_iterator);

//����url
std::vector<std::string> findUrls(const std::string&);

#endif