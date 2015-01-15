/*============================================================

������
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/
//ͷ�ļ���
#include "database.h"
#include <atlbase.h>
#include "file.h"



//�������ӿ�
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"sqlite3.lib")

//����������
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
		conn = LinkDatabase(conn, sql, err_msg);		//����ļ����ڣ��������Ӳ������ݿ��ļ�
	else
		conn = CreateDb(conn,sql,err_msg);      //�����ݿ��ļ������ڣ��������ݿ⣻
	LPCWSTR pw = T2W(_T("verb.txt"));   //�ж��Ƿ����verb.txt��SubjectAndObject.txt�ļ��Ƿ���ڣ��������ڣ��½���Ӧ���ļ���
	JudgeFile(pw);
	pw = T2W(_T("SubjectAndObject.txt"));
	JudgeFile(pw);
	while (true)
		mainMenu(conn, sql, err_msg);
	//ReadDaFromFToDB(conn,  err_msg);
	return 0;
}



//�˵�

void mainMenu(sqlite3 * conn,char * sql,char * err_msg)
{
	char ch;
	std::cout << "=========================================================" << std::endl
		<< "+\t\t\t1����ʼ������\t\t\t+" << std::endl
		<< "+\t\t\t2���ֶ���Ӵʿ�\t\t\t+" << std::endl
		<< "+\t\t\t3�����ļ���Ӵʿ�\t\t+" << std::endl
		<< "+\t\t\t4��������ݿ�ʿ�\t\t+" << std::endl
		<< "+\t\t\t5���˳�����\t\t\t+" << std::endl
		<< "=========================================================" << std::endl;
	while (std::cin >> ch  && !(ch >= '1' && ch <= '5'))
		std::cout << "����������������ȷ��ѡ��:";
	switch (ch)
	{
	case '1':CreatSentance(conn, err_msg);
		break;
	case '2':wordMenu(conn,sql,err_msg);
		break;
	case '3':ReadDaFromFToDB(conn,err_msg);
		break;
	case '4':cleanDB(conn, sql);
		std::cout << "��������գ�" << std::endl;
		break;
	case '5':
		CloseDatabase(conn);	//���ùر����ݿ⺯�����Ͽ������ݿ�����ӣ�
		exit(0);
	}
}


// ��Ӵʿ�˵�
void wordMenu(sqlite3 * conn,char * sql, char * err_msg)
{
	char ch;
	std::cout << "=========================================================" << std::endl
		<< "+\t\t\t1���������\t\t\t+" << std::endl
		<< "+\t\t\t2��ν��\t\t\t\t" << std::endl
		<< "+\t\t\t3�������ϲ�˵�\\t\t\t+" << std::endl
		<< "=========================================================" << std::endl;
	while (std::cin >> ch  && !(ch >= '1' && ch <= '3'))
		std::cout << "����������������ȷ��ѡ��:";
	switch (ch)
	{
	case '1':addWords(conn, err_msg, 1);
		break;
	case '2':addWords(conn, err_msg, 2);
		break;
	case '3':mainMenu(conn, sql,err_msg);
	}
}


//�ֶ���Ӵʿ�
void addWords(sqlite3* conn, char *err_msg,int ch)
{
	std::string s[2] = { "insert into SubjectAndObject(word) values ( '", "insert into verb(word) values ( '" };
	if (1 == ch)
		Add(conn, err_msg, s);
	else
		Add(conn, err_msg, &s[1]);
}


//��Ӵʿ⺯��
void Add(sqlite3 * conn, char * err_msg, std::string * add)
{
	std::cout << "<��ʾ�����롾//back�������ϲ�˵�>" << std::endl;
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
			std::cout << "�Ѿ���ɶԴ������ӣ�" << std::endl;
			break;
		}
			
	}
}

