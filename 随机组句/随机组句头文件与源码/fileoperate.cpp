/*============================================================

随机组句
powered by carol  (luoshengwen)

platform : windows 8.1 && visual studio 2013 with update 4

2014-12-04
==============================================================
*/

#include "file.h"


//检测是否存在文件，如不存在，则建立新的文件
void JudgeFile(LPCWSTR fileName)
{
	if (!PathFileExists(fileName))
	{
		HANDLE hFile = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		CloseHandle(hFile);
	}
}

//从文件中读取数据到数据库中
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
		OperateDatabase(conn, str.c_str(), err_msg);      //调用数据库执行函数，对数据库进行相应的修改；
	}
	txtFile.close();
	if (!flag)
		std::cout << "verb.txt文件中没有可以向数据库添加的数据，请添加后重试！" << std::endl;
	else
	{
		std::cout << "verb类型添加成功!" << std::endl;
		ClearFileData("verb.txt");    //清除在verb中的数据
	}
	flag = false;
	txtFile.open("./SubjectAndObject.txt", std::ios::in);
	while (txtFile >> str)
	{
		flag = true;
		temp = "insert into SubjectAndObject(word) values ('" + str + "');";
		StringToWString(temp, Wstr);
		str = Unicode2Utf8(Wstr);
		OperateDatabase(conn, str.c_str(), err_msg);      //调用数据库执行函数，对数据库进行相应的修改；
	}
	txtFile.close();
	if (!flag)
		std::cout << "SubjectAndObject.txt文件中没有可以向数据库添加的数据，请添加后重试！" << std::endl;
	else
	{
		std::cout << "SubjectAndObject类型添加成功!" << std::endl;
		ClearFileData("SubjectAndObject.txt");
	}
}


//清除文件中的数据
void ClearFileData(char * str)
{
	std::ofstream txtFile;
	std::string s = "";
	txtFile.open(str);
	txtFile << s;
	txtFile.close();
}