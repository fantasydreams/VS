/*============================================================

随机组句
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/

#include "database.h"



int subN = 0, verbN = 0;

//当RSG.db数据库文件不存在时，创建并对数据库添加几张表格
sqlite3* CreateDb(sqlite3 * conn, char *sql, char * err_msg)
{
	if (sqlite3_open("./RGS.db", &conn) != SQLITE_OK)
	{
		std::cout << "无法打开数据库，请尝试重启程序或者删除与此程序同一目录下的RSG.db文件！" << std::endl;
		exit(-1);
	}
	else
	{
		CreateTable(conn, sql, err_msg);
		std::cout << "数据空空如也，尝试手动添加数据吧！" << std::endl;
		return conn;
	}
}


//尝试连接数据库
sqlite3 * LinkDatabase(sqlite3 * conn, char *sql, char * err_msg)
{
	if (sqlite3_open("./RGS.db", &conn) != SQLITE_OK)
	{
		std::cout << "无法打开数据库，请尝试重启程序或者删除与此程序同一目录下的RSG.db文件！" << std::endl;
		exit(-1);
	}
	return conn;
}

// 关闭连接
void CloseDatabase(sqlite3 *conn)
{
	if (sqlite3_close(conn) != SQLITE_OK)
	{
		std::cout << "无法关闭，错误代码:" << sqlite3_errmsg(conn) << std::endl;
		exit(-1);
	}
}

//对数据库操作
void OperateDatabase(sqlite3 *conn, const char * sql, char *err_msg)
{
	if (sqlite3_exec(conn, sql, NULL, NULL, &err_msg) != SQLITE_OK)
	{
		std::cout << "程序操作失败，错误代码："<< err_msg<<std::endl;
		system("pause");
		//exit(-1);
	}
}

//在数据库中创建表格
void CreateTable(sqlite3 * conn, char * sql, char * err_msg)
{
	strcpy_s(sql, 200, "create table SubjectAndObject(id integer PRIMARY KEY AUTOINCREMENT DEFAULT 0,word varchar(50))");
	OperateDatabase(conn, sql, err_msg);
	strcpy_s(sql, 200, "create table verb(id integer PRIMARY KEY AUTOINCREMENT DEFAULT 0,word varchar(50))");
	OperateDatabase(conn, sql, err_msg);
}


//清理数据库文件（删除所有记录）//有很多方法可以实现，这里用删除表再建表的思路(因为表单仅有两张，不多)
void cleanDB(sqlite3 * conn,char * sql)
{
	strcpy_s(sql, 200, "drop table verb;drop table SubjectAndObject;");
	OperateDatabase(conn, sql, NULL);
	CreateTable(conn, sql, NULL);
	strcpy_s(sql, 200, "update sqlite_sequence set seq = 0;");
	OperateDatabase(conn, sql, NULL);
}


//利用随机函数组句
void CreatSentance(sqlite3 * conn, char * err_msg)
{
	int vflag,sflag,oflag;
	char c;
	sqlite3_exec(conn, "select count() from verb;", &sqlite3_exec_callbackCount1,0,&err_msg);
	sqlite3_exec(conn, "select count() from SubjectAndObject;", &sqlite3_exec_callbackCount2, 0, &err_msg);
	if (0 == verbN || 0 == subN)
	{
		if (0 == verbN)
			std::cout << "还没有谓语的词库哦，先添加后在试试吧~~~" << std::endl;
		else
			std::cout << "还没有主语宾语的词库哦，先添加后在试试吧~~~" << std::endl;
		return;
	}
	srand(time(NULL));
	char buffer[200];
	while (c = _getch())
	{
		if (27 != c)
		{
			vflag = rand() % verbN + 1;
			oflag = rand() % subN + 1;
			while (sflag = (rand() % subN + 1))   //得到的随机数，主语与宾语不同
				if (sflag == oflag)
					continue;
				else
					break;
			std::cout << "\t\t\t";
			strcpy_s(buffer,"select word from SubjectAndObject where id = ");
			chartostring(buffer, sflag);
			sqlite3_exec(conn, buffer, &sqlite3_exec_callbackWord, 0, &err_msg);
			strcpy_s(buffer, "select word from verb where id = ");
			chartostring(buffer, vflag);
			sqlite3_exec(conn, buffer, &sqlite3_exec_callbackWord, 0, &err_msg);
			strcpy_s(buffer, "select word from SubjectAndObject where id = ");
			chartostring(buffer, oflag);
			sqlite3_exec(conn, buffer, &sqlite3_exec_callbackWord, 0, &err_msg);
			std::cout<<std::endl;
		}
		else
			break;
	}

}

//sqlite3回调函数
int sqlite3_exec_callbackWord(void *data, int nColumn, char **colValues, char **colNames)
{
	std::wstring wstr;
	wstr = UTF8ToUnicode(colValues[0]);
	std::wcout.imbue(std::locale("chs"));
	std::wcout << wstr << "\t";
	return 0;
}

int sqlite3_exec_callbackCount1(void *data, int nColumn, char **colValues, char **colNames)
{
	std::string temp = colValues[0];
	int i = 0,sum = 0;
	for (; i < temp.length(); i++)
	{
		sum = sum * 10 + temp[i]-'0';
	}
	verbN = sum;
	return 0;
}

int sqlite3_exec_callbackCount2(void *data, int nColumn, char **colValues, char **colNames)
{
	std::string temp = colValues[0];
	int i = 0, sum = 0;
	for (; i < temp.length(); i++)
	{
		sum = sum * 10 + temp[i]-'0';
	}
	subN = sum;
	return 0;
}
