#include "FileHelper.h"

#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

TEXTFILETYPE FileHelper::GetTextFileType(const std::string& strFileName)
{
	TEXTFILETYPE fileType = TextFileType_ANSI;
	std::ifstream file;
	file.open(strFileName.c_str(), std::ios_base::in);
	bool bUnicodeFile = false;

	if (file.good())
	{
		char szFlag[3] = {0};
		file.read(szFlag, sizeof(char) * 3);
		if (static_cast<unsigned char>(szFlag[0]) == 0xFF
			&& static_cast<unsigned char>(szFlag[1]) == 0xFE)
		{
			fileType = TextFileType_UNICODE;
		}
		else if (static_cast<unsigned char>(szFlag[0]) == 0xEF
			&& static_cast<unsigned char>(szFlag[1]) == 0xBB
			&& static_cast<unsigned char>(szFlag[2]) == 0xBF)
		{
			fileType = TextFileType_UTF8;
		}
	}

	file.close();
	return fileType;
}

vector<string> FileHelper::ReadTextFile(const std::string& strFileName)
{
	TEXTFILETYPE fileType = GetTextFileType(strFileName);
	if (fileType != TextFileType_UTF8)
	{
		cout << "UTF-8 file needed...!" << endl;
		return {};
	}

	FILE* fp = nullptr;
	fp = fopen(strFileName.c_str(), "rb");
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	vector<string> result;

	if (fp != nullptr)
	{
		// UTF-8 file should offset 3 byte from start position.
		fseek(fp, sizeof(char) * 3, 0);
		int buferSize = static_cast<int>(size) - 3;
		auto szBuf = new char[buferSize + 1];
		memset(szBuf, 0, sizeof(char) * (buferSize + 1));
		fread(szBuf, sizeof(char), buferSize, fp);
		result.emplace_back(szBuf);
		delete[] szBuf;
	}

	fclose(fp);

#ifdef _WIN32
	for (auto& sentence : result)
		sentence = UTF8ToGB(sentence.c_str());
#endif

	return result;
}

void FileHelper::WriteTextFile(const std::string& strFileName, const std::string& strContent)
{
	FILE* pFile;
	char buffer[] = {0xEF, 0xBB, 0xBF};
	pFile = fopen(strFileName.c_str(), "wb");
	fwrite(buffer, sizeof(char), sizeof(buffer), pFile);
	fwrite(strContent.c_str(), sizeof(char), strContent.size(), pFile);
	fclose(pFile);
}

#ifdef _WIN32
string FileHelper::UTF8ToGB(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, nullptr, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, nullptr, 0, nullptr, nullptr);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, nullptr, nullptr);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
#endif
