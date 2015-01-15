/*============================================================

随机组句
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/
//头文件区
#include "database.h"
#include <atlbase.h>
#include "file.h"



//其他链接库
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"sqlite3.lib")

//函数声明区
void mainMenu(sqlite3 * conn, char * sql,char * err_msg);
void wordMenu(sqlite3 * conn, char * sql,char * err_msg);
void addWords(sqlite3* conn, char *err_msg, int ch);
void Add(sqlite3 * conn, char * err_msg, std::string * add);

int main()
{
	sqlite3 * conn = NULL;
	char * err_msg = NULL;
	char sql[200] = ""; 
	if (PathFileExists(_T("./RGS.db")))
		conn = LinkDatabase(conn, sql, err_msg);		//书库文件存在，尝试连接并打开数据库文件
	else
		conn = CreateDb(conn,sql,err_msg);      //当数据库文件不存在，建立数据库；
	LPCWSTR pw = T2W(_T("verb.txt"));   //判断是否存在verb.txt和SubjectAndObject.txt文件是否存在，若不存在，新建相应的文件；
	JudgeFile(pw);
	pw = T2W(_T("SubjectAndObject.txt"));
	JudgeFile(pw);
	while (true)
		mainMenu(conn, sql, err_msg);
	//ReadDaFromFToDB(conn,  err_msg);
	return 0;
}



//菜单

void mainMenu(sqlite3 * conn,char * sql,char * err_msg)
{
	char ch;
	std::cout << "=========================================================" << std::endl
		<< "+\t\t\t1、开始随机组句\t\t\t+" << std::endl
		<< "+\t\t\t2、手动添加词库\t\t\t+" << std::endl
		<< "+\t\t\t3、从文件添加词库\t\t+" << std::endl
		<< "+\t\t\t4、清楚数据库词库\t\t+" << std::endl
		<< "+\t\t\t5、退出程序\t\t\t+" << std::endl
		<< "=========================================================" << std::endl;
	while (std::cin >> ch  && !(ch >= '1' && ch <= '5'))
		std::cout << "输入有误，请输入正确的选项:";
	switch (ch)
	{
	case '1':CreatSentance(conn, err_msg);
		break;
	case '2':wordMenu(conn,sql,err_msg);
		break;
	case '3':ReadDaFromFToDB(conn,err_msg);
		break;
	case '4':cleanDB(conn, sql);
		std::cout << "数据已清空！" << std::endl;
		break;
	case '5':
		CloseDatabase(conn);	//调用关闭数据库函数，断开与数据库的连接；
		exit(0);
	}
}


// 添加词库菜单
void wordMenu(sqlite3 * conn,char * sql, char * err_msg)
{
	char ch;
	std::cout << "=========================================================" << std::endl
		<< "+\t\t\t1、主语、宾语\t\t\t+" << std::endl
		<< "+\t\t\t2、谓语\t\t\t\t" << std::endl
		<< "+\t\t\t3、返回上层菜单\\t\t\t+" << std::endl
		<< "=========================================================" << std::endl;
	while (std::cin >> ch  && !(ch >= '1' && ch <= '3'))
		std::cout << "输入有误，请输入正确的选项:";
	switch (ch)
	{
	case '1':addWords(conn, err_msg, 1);
		break;
	case '2':addWords(conn, err_msg, 2);
		break;
	case '3':mainMenu(conn, sql,err_msg);
	}
}


//手动添加词库
void addWords(sqlite3* conn, char *err_msg,int ch)
{
	std::string s[2] = { "insert into SubjectAndObject(word) values ( '", "insert into verb(word) values ( '" };
	if (1 == ch)
		Add(conn, err_msg, s);
	else
		Add(conn, err_msg, &s[1]);
}


//添加词库函数
void Add(sqlite3 * conn, char * err_msg, std::string * add)
{
	std::cout << "<提示：键入【//back】返回上层菜单>" << std::endl;
	std::string word, temp;
	std::wstring wstr;
	while (std::cin >> word)
	{
		if ("//back" != word)
		{
			temp = add[0] + word + "');";
			StringToWString(temp, wstr);
			temp = Unicode2Utf8(wstr);
			OperateDatabase(conn, temp.c_str(), err_msg);
		}
		else
		{
			std::cout << "已经完成对此项的添加！" << std::endl;
			break;
		}
			
	}
}

