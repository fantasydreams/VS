#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <tchar.h>
#include <conio.h>
#include <cmath>
#include <cstdio>
#include <string>


class Comm
{
private :
	HANDLE hComm;
	OVERLAPPED m_ov;
	COMSTAT comstat;
	bool open;
	std::string filename;
	FILE *fp;
	int id;
	bool * state;
public:
	Comm(LPCWSTR,bool *);
	~Comm();
	void ReceiveChar();
	bool WriteChar(BYTE* m_szWriteBuffer, DWORD m_nToSend);
	bool ProcessErrorMessage(char* ErrorText);
	bool OpenPort(LPCWSTR portname);
	bool setuptimeout(DWORD ReadInterval, DWORD ReadTotalMultiplier, DWORD ReadTotalconstant, DWORD WriteTotalMultiplier, DWORD WriteTotalconstant);
	bool setupdcb(int rate_arg);//设置DCB,先获取DCB配置，再设置，最后看是否设置//好
	HANDLE GethComm();
	void WriteToFile(char *);
};

struct Coord{
	double x;
	double y;
};

Coord CalPoint(double* distance, char* fgetNo);//计算出点的坐标
void Calcu(unsigned int tote);
//DWORD WINAPI Commrece(LPVOID pParam);//接收串口线程
void GetRSSI(unsigned int i, double* RSSI, char* fgetNo);
void GetDistance(double* Distance, double* RSSI, char* fgetNo);//RSSI转换成距离
double RSSIToD(double RSSI);//将RSSI转换成distance
Coord CalPoin3(double* distance, char* fgetNo);//三个节点时
Coord CalPoin4(double* distance);//两各节点时

DWORD WINAPI Commrece(LPVOID pParam);//串口接收线程
