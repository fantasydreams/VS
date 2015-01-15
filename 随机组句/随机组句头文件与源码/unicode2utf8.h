/*============================================================

Ëæ»ú×é¾ä
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/


#ifndef _uni
#define _uni


#include <windows.h>
#include <string>
#include <vector>

std::string Unicode2Utf8(const std::wstring& widestring);
BOOL StringToWString(const std::string &str, std::wstring &wstr);
std::wstring UTF8ToUnicode(const std::string& str);
void chartostring(char * buffer, int num);


#endif