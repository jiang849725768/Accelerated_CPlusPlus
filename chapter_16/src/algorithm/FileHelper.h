#ifndef GUARD_FILEHELPER_H
#define GUARD_FILEHELPER_H

#include <string>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#endif

using TEXTFILETYPE = enum TextFileType
{
	TextFileType_ANSI = 0,
	TextFileType_UNICODE,
	TextFileType_UTF8
};

class FileHelper
{
public:
#ifdef _WIN32
	static std::string UTF8ToGB(const char* str);
#endif

	static TEXTFILETYPE GetTextFileType(const std::string& strFileName);
	static std::vector<std::string> ReadTextFile(const std::string& strFileName);
	static void WriteTextFile(const std::string& strFileName, const std::string& strContent);
};

#endif
