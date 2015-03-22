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
	bool setupdcb(int rate_arg);//����DCB,�Ȼ�ȡDCB���ã������ã�����Ƿ�����//��
	HANDLE GethComm();
	void WriteToFile(char *);
};

struct Coord{
	double x;
	double y;
};

Coord CalPoint(double* distance, char* fgetNo);//������������
void Calcu(unsigned int tote);
//DWORD WINAPI Commrece(LPVOID pParam);//���մ����߳�
void GetRSSI(unsigned int i, double* RSSI, char* fgetNo);
void GetDistance(double* Distance, double* RSSI, char* fgetNo);//RSSIת���ɾ���
double RSSIToD(double RSSI);//��RSSIת����distance
Coord CalPoin3(double* distance, char* fgetNo);//�����ڵ�ʱ
Coord CalPoin4(double* distance);//�����ڵ�ʱ

DWORD WINAPI Commrece(LPVOID pParam);//���ڽ����߳�
