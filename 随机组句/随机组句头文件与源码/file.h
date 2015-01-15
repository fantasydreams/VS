/*============================================================

Ëæ»ú×é¾ä
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/

#ifndef _FILE
#define _FILE

#include <fstream>
#include <Shlwapi.h>
#include <tchar.h>
#include <windows.h>
#include "database.h"
#include "unicode2utf8.h"


#pragma comment(lib,"sqlite3.lib")

void ReadDaFromFToDB(sqlite3 * conn, char * err_msg);
void JudgeFile(LPCWSTR fileName);
void ClearFileData(char * str);
void cleanDB(sqlite3 * conn, char * sql);



#endif //!_FILE

