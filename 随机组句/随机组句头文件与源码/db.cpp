/*============================================================

������
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/

#include "database.h"



int subN = 0, verbN = 0;

//��RSG.db���ݿ��ļ�������ʱ�������������ݿ���Ӽ��ű��
sqlite3* CreateDb(sqlite3 * conn, char *sql, char * err_msg)
{
	if (sqlite3_open("./RGS.db", &conn) != SQLITE_OK)
	{
		std::cout << "�޷������ݿ⣬�볢�������������ɾ����˳���ͬһĿ¼�µ�RSG.db�ļ���" << std::endl;
		exit(-1);
	}
	else
	{
		CreateTable(conn, sql, err_msg);
		std::cout << "���ݿտ���Ҳ�������ֶ�������ݰɣ�" << std::endl;
		return conn;
	}
}


//�����������ݿ�
sqlite3 * LinkDatabase(sqlite3 * conn, char *sql, char * err_msg)
{
	if (sqlite3_open("./RGS.db", &conn) != SQLITE_OK)
	{
		std::cout << "�޷������ݿ⣬�볢�������������ɾ����˳���ͬһĿ¼�µ�RSG.db�ļ���" << std::endl;
		exit(-1);
	}
	return conn;
}

// �ر�����
void CloseDatabase(sqlite3 *conn)
{
	if (sqlite3_close(conn) != SQLITE_OK)
	{
		std::cout << "�޷��رգ��������:" << sqlite3_errmsg(conn) << std::endl;
		exit(-1);
	}
}

//�����ݿ����
void OperateDatabase(sqlite3 *conn, const char * sql, char *err_msg)
{
	if (sqlite3_exec(conn, sql, NULL, NULL, &err_msg) != SQLITE_OK)
	{
		std::cout << "�������ʧ�ܣ�������룺"<< err_msg<<std::endl;
		system("pause");
		//exit(-1);
	}
}

//�����ݿ��д������
void CreateTable(sqlite3 * conn, char * sql, char * err_msg)
{
	strcpy_s(sql, 200, "create table SubjectAndObject(id integer PRIMARY KEY AUTOINCREMENT DEFAULT 0,word varchar(50))");
	OperateDatabase(conn, sql, err_msg);
	strcpy_s(sql, 200, "create table verb(id integer PRIMARY KEY AUTOINCREMENT DEFAULT 0,word varchar(50))");
	OperateDatabase(conn, sql, err_msg);
}


//�������ݿ��ļ���ɾ�����м�¼��//�кܶ෽������ʵ�֣�������ɾ�����ٽ����˼·(��Ϊ���������ţ�����)
void cleanDB(sqlite3 * conn,char * sql)
{
	strcpy_s(sql, 200, "drop table verb;drop table SubjectAndObject;");
	OperateDatabase(conn, sql, NULL);
	CreateTable(conn, sql, NULL);
	strcpy_s(sql, 200, "update sqlite_sequence set seq = 0;");
	OperateDatabase(conn, sql, NULL);
}


//��������������
void CreatSentance(sqlite3 * conn, char * err_msg)
{
	int vflag,sflag,oflag;
	char c;
	sqlite3_exec(conn, "select count() from verb;", &sqlite3_exec_callbackCount1,0,&err_msg);
	sqlite3_exec(conn, "select count() from SubjectAndObject;", &sqlite3_exec_callbackCount2, 0, &err_msg);
	if (0 == verbN || 0 == subN)
	{
		if (0 == verbN)
			std::cout << "��û��ν��Ĵʿ�Ŷ������Ӻ������԰�~~~" << std::endl;
		else
			std::cout << "��û���������Ĵʿ�Ŷ������Ӻ������԰�~~~" << std::endl;
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
			while (sflag = (rand() % subN + 1))   //�õ������������������ﲻͬ
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

//sqlite3�ص�����
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
