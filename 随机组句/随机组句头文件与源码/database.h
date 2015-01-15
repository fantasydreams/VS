

/*============================================================

随机组句
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/

#ifndef _SqliteDB
#define _SqliteDB

#include "sqlite3.h"
#include <Shlwapi.h>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "unicode2utf8.h"
#include <locale>


#pragma comment(lib,"sqlite3.lib")


//函数声明
sqlite3* CreateDb(sqlite3 * conn, char *sql, char * err_msg);
sqlite3* LinkDatabase(sqlite3 * conn, char *sql, char * err_msg);
void CloseDatabase(sqlite3 *conn);
void OperateDatabase(sqlite3 *conn, const char * sql, char *err_msg);
sqlite3* CreateDb(sqlite3 * conn, char *sql, char * err_msg);
void CreateTable(sqlite3 * conn, char *sql, char * err_msg);
int sqlite3_exec_callbackCount1(void *data, int nColumn, char **colValues, char **colNames);
int sqlite3_exec_callbackCount2(void *data, int nColumn, char **colValues, char **colNames);
int sqlite3_exec_callbackWord(void *data, int nColumn, char **colValues, char **colNames);
void CreatSentance(sqlite3 * conn, char * err_msg);


#endif // !_SqliteDB