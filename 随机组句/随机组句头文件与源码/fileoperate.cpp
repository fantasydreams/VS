/*============================================================

������
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/

#include "file.h"


//����Ƿ�����ļ����粻���ڣ������µ��ļ�
void JudgeFile(LPCWSTR fileName)
{
	if (!PathFileExists(fileName))
	{
		HANDLE hFile = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		CloseHandle(hFile);
	}
}

//���ļ��ж�ȡ���ݵ����ݿ���
void ReadDaFromFToDB(sqlite3 * conn, char * err_msg)
{
	std::fstream txtFile;
	txtFile.open("./verb.txt", std::ios::in);
	std::string str,temp;
	std::wstring Wstr;
	bool flag = false;
	while (txtFile >> str)
	{
		flag = true;
		temp = "insert into verb(word) values ('" + str + "');";
		StringToWString(temp,Wstr);
		str = Unicode2Utf8(Wstr);
		OperateDatabase(conn, str.c_str(), err_msg);      //�������ݿ�ִ�к����������ݿ������Ӧ���޸ģ�
	}
	txtFile.close();
	if (!flag)
		std::cout << "verb.txt�ļ���û�п��������ݿ���ӵ����ݣ�����Ӻ����ԣ�" << std::endl;
	else
	{
		std::cout << "verb������ӳɹ�!" << std::endl;
		ClearFileData("verb.txt");    //�����verb�е�����
	}
	flag = false;
	txtFile.open("./SubjectAndObject.txt", std::ios::in);
	while (txtFile >> str)
	{
		flag = true;
		temp = "insert into SubjectAndObject(word) values ('" + str + "');";
		StringToWString(temp, Wstr);
		str = Unicode2Utf8(Wstr);
		OperateDatabase(conn, str.c_str(), err_msg);      //�������ݿ�ִ�к����������ݿ������Ӧ���޸ģ�
	}
	txtFile.close();
	if (!flag)
		std::cout << "SubjectAndObject.txt�ļ���û�п��������ݿ���ӵ����ݣ�����Ӻ����ԣ�" << std::endl;
	else
	{
		std::cout << "SubjectAndObject������ӳɹ�!" << std::endl;
		ClearFileData("SubjectAndObject.txt");
	}
}


//����ļ��е�����
void ClearFileData(char * str)
{
	std::ofstream txtFile;
	std::string s = "";
	txtFile.open(str);
	txtFile << s;
	txtFile.close();
}