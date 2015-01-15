/*
Carol 2014-12-01
*/
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <tchar.h>
#include <conio.h>
#include "header.h"
#include <cmath>

HANDLE hComm;
OVERLAPPED m_ov;
COMSTAT comstat;
DWORD	m_dwCommEvents;

void ReceiveChar();
bool WriteChar(BYTE* m_szWriteBuffer, DWORD m_nToSend);

bool ProcessErrorMessage(char* ErrorText)
{
	char *Temp = new char[200];
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR)&lpMsgBuf,
		0,
		NULL
		);
	sprintf_s(Temp,sizeof(Temp), "WARNING:  %s Failed with the following error: \n%s\nPort: %d\n", (char*)ErrorText, lpMsgBuf, "com2");
	MessageBox(NULL, LPCWSTR(Temp), _T("Application Error"), MB_ICONSTOP);
	LocalFree(lpMsgBuf);
	delete[] Temp;
	return true;
}


DWORD WINAPI MyThread1(LPVOID pParam)
{
	ReceiveChar();
	return 0;
}

DWORD WINAPI MyThread2(LPVOID pParam)
{
	while (hComm != INVALID_HANDLE_VALUE)              // �����ѱ��ɹ���
	{
		unsigned char d;
		d = _getch();
		printf("%c", d);
		//system("pause");
		WriteChar(&d, 1);
	}
	return 0;
}


bool OpenPort(LPCWSTR portname)
{
	hComm = CreateFile(portname,  //���ں�
		GENERIC_READ | GENERIC_WRITE,   //�������д
		0,								//ͨѶ�豸�����Զ�ռ�ķ�ʽ��
		0,								//�ް�ȫ��������
		OPEN_EXISTING,					//ͨѶ�豸�Ѵ���
		FILE_FLAG_OVERLAPPED,			//ͬ��I/O              �첽I/O��ֱ������  0
		0);								//ͨѶ�豸������ģ���
	if (hComm == INVALID_HANDLE_VALUE)
	{
		CloseHandle(hComm);
		return FALSE;
	}
	else
		return TRUE;
}

bool setuptimeout(DWORD ReadInterval, DWORD ReadTotalMultiplier, DWORD ReadTotalconstant, DWORD WriteTotalMultiplier, DWORD WriteTotalconstant)
{
	COMMTIMEOUTS timeouts;
	timeouts.ReadIntervalTimeout = ReadInterval;
	timeouts.ReadTotalTimeoutConstant = ReadTotalconstant;
	timeouts.ReadTotalTimeoutMultiplier = ReadTotalMultiplier;
	timeouts.WriteTotalTimeoutConstant = WriteTotalconstant;
	timeouts.WriteTotalTimeoutMultiplier = WriteTotalMultiplier;
	if (!SetCommTimeouts(hComm, &timeouts))
	{
		ProcessErrorMessage("SetCommTimeouts()");
		return false;
	}

	else
		return true;
}


bool setupdcb(int rate_arg)//����DCB,�Ȼ�ȡDCB���ã������ã�����Ƿ�����//��
{
	DCB  dcb;
	int rate = rate_arg;
	memset(&dcb, 0, sizeof(dcb));//��һ���ڴ�������ĳ��������ֵ���ǶԽϴ�Ľṹ//�������������������һ����췽��
	if (!GetCommState(hComm, &dcb))//��ȡ��ǰDCB����
	{
		ProcessErrorMessage("GetCommState()");
		return FALSE;
	}
	// set DCB to configure the serial port
	dcb.DCBlength = sizeof(dcb);
	/* ---------- Serial Port Config ------- */
	dcb.BaudRate = rate;
	dcb.Parity = NOPARITY;
	dcb.fParity = 0;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;
	dcb.fOutxCtsFlow = 0;
	dcb.fOutxDsrFlow = 0;
	dcb.fDtrControl = DTR_CONTROL_DISABLE;
	dcb.fDsrSensitivity = 0;
	dcb.fRtsControl = RTS_CONTROL_DISABLE;
	dcb.fOutX = 0;
	dcb.fInX = 0;
	/* ----------------- misc parameters ----- */
	dcb.fErrorChar = 0;
	dcb.fBinary = 1;
	dcb.fNull = 0;
	dcb.fAbortOnError = 0;
	dcb.wReserved = 0;
	dcb.XonLim = 2;
	dcb.XoffLim = 4;
	dcb.XonChar = 0x13;
	dcb.XoffChar = 0x19;
	dcb.EvtChar = 0;
	// set DCB
	if (!SetCommState(hComm, &dcb))
	{
		ProcessErrorMessage("SetCommState()");
		return false;
	}

	else
		return true;
}


void ReceiveChar()
{
	BOOL  bRead = TRUE;
	BOOL  bResult = TRUE;
	DWORD dwError = 0;
	DWORD BytesRead = 0;
	char RXBuff;
	char Buffer[60];
	char i = 0;
	int j = 0, flag = 0,n=1;
	double distance, c ,sum = 0;
	for (i;;i++)
	{
		bResult = ClearCommError(hComm, &dwError, &comstat);
		// ��ʹ��ReadFile �������ж�����ǰ��Ӧ��ʹ��ClearCommError�����������

		if (comstat.cbInQue == 0)// COMSTAT�ṹ���ش���״̬��Ϣ
		{
			//����ֻ�õ���cbInQue��Ա�������ó�Ա������ֵ�������뻺�������ֽ���
			Sleep(1000);
			continue;
		}
		if (bRead)
		{
			bResult = ReadFile(hComm, // Handle to COMM port���ڵľ��

				&RXBuff,	// RX Buffer Pointer
				// ��������ݴ洢�ĵ�ַ������������ݽ���
				//�����Ը�ָ���ֵΪ�׵�ַ��һƬ�ڴ���

				1,		  // Read one byteҪ��������ݵ��ֽ���,

				&BytesRead, // Stores number of bytes read, ָ��һ��DWORD
				//��ֵ������ֵ���ض�����ʵ�ʶ�����ֽ���

				&m_ov);   		// pointer to the m_ov structure
			// �ص�����ʱ���ò���ָ��һ��OVERLAPPED�ṹ��ͬ������ʱ���ò���ΪNULL
			//printf("%c", RXBuff);

			
			if (j != 29)
			{
				Buffer[j++] = RXBuff;
			}
			else
			{
				//Buffer[j] = '\0';
				//puts(Buffer);
				j = 0;
			}
			if (j == 28)
			{
				
				c =abs( Buffer[j]);
				/*if (c < 0)
					c = -c;*/
				/*if (n > 1){
					double fc = c - 58.7135;
					double fn = fc * 0.2;
					sum += fn;

					std::cout << fn << "n:" << n-1 << "  " << "sum:" << sum << "  " << "agv:" << sum / (n-1)<< std::endl;
				}
				n++;*/
				double fd = (c-58.7135 )/28.4246;
				distance = pow(10, fd);
				std::cout << distance<<std::endl;
				
				/*std::cout << c<<'\t';
				sum += c;
				std::cout <<"ƽ��ֵ"<< sum / n <<"sum"<<sum<<"\tn"<<n<< std::endl;
				n++;*/
				
				if (n == 1000)
					system("pasue");
			}
			if (!bResult)// ��ReadFile��WriteFile����FALSEʱ����һ�����ǲ���ʧ//�ܣ��߳�Ӧ�õ���GetLastError�����������صĽ��
			{
				switch (dwError = GetLastError())
				{
				case ERROR_IO_PENDING:
				{
					bRead = FALSE;
					break;
				}
				default:
				{
					break;
				}
				}
			}
			else
			{
				bRead = TRUE;
			}
		}  // close if (bRead)
		if (!bRead)
		{
			bRead = TRUE;
			bResult = GetOverlappedResult(hComm,	// Handle to COMM port
				&m_ov,	// Overlapped structure
				&BytesRead,		// Stores number of bytes read
				TRUE); 			// Wait flag
		}
	}
}


bool WriteChar(BYTE* m_szWriteBuffer, DWORD m_nToSend)
{
	BOOL bWrite = TRUE;
	BOOL bResult = TRUE;
	DWORD BytesSent = 0;
	HANDLE	m_hWriteEvent = NULL;
	ResetEvent(m_hWriteEvent);
	if (bWrite)
	{
		m_ov.Offset = 0;
		m_ov.OffsetHigh = 0;
		// Clear buffer
		bResult = WriteFile(hComm,	// Handle to COMM Port, ���ڵľ��

			m_szWriteBuffer,	// Pointer to message buffer in calling finction
			// ���Ը�ָ���ֵΪ�׵�ַ��nNumberOfBytesToWrite
			// ���ֽڵ����ݽ�Ҫд�봮�ڵķ������ݻ�����

			m_nToSend,	// Length of message to send, Ҫд������ݵ��ֽ���

			&BytesSent,	 // Where to store the number of bytes sent
			// ָ��ָ��һ��DWORD��ֵ������ֵ����ʵ��д����ֽ���

			&m_ov);	    // Overlapped structure
		// �ص�����ʱ���ò���ָ��һ��OVERLAPPED�ṹ��
		// ͬ������ʱ���ò���ΪNULL
		if (!bResult)  // ��ReadFile��WriteFile����FALSEʱ����һ�����ǲ���ʧ
			//�ܣ��߳�Ӧ�õ���GetLastError�����������صĽ��
		{
			DWORD dwError = GetLastError();
			switch (dwError)
			{
			case ERROR_IO_PENDING: //GetLastError��������
				//ERROR_IO_PENDING����˵���ص�������δ���
			{
				// continue to GetOverlappedResults()
				BytesSent = 0;
				bWrite = FALSE;
				break;
			}
			default:
			{
				// all other error codes
				// all other error codes
				ProcessErrorMessage("WriteFile()");
				break;
			}
			}
		}
	} // end if(bWrite)
	if (!bWrite)
	{
		bWrite = TRUE;
		bResult = GetOverlappedResult(hComm,	// Handle to COMM port
			&m_ov,		// Overlapped structure
			&BytesSent,		// Stores number of bytes sent
			TRUE); 			// Wait flag

		// deal with the error code
		if (!bResult)
		{
			ProcessErrorMessage("GetOverlappedResults() in WriteFile()");
		}
	} // end if (!bWrite)

	// Verify that the data size send equals what we tried to send
	if (BytesSent != m_nToSend)
	{
		printf("WARNING: WriteFile() error.. Bytes Sent: %d; Message Length: %d\n", BytesSent, strlen((char*)m_szWriteBuffer));
	}
	return true;
}



void main(int argv,char *argc[])
{
	bool open;

	/*std::cout << argv;
	int i = 0;
	while (i < argv)
	{
		std::cout << argc[i] << std::endl;
		i++;
	}*/
	//printcommand();
	
	open = OpenPort(_T("com3"));
	if (open)
	{
		std::cout << "open comport success" << std::endl;
		if (setupdcb(38420))    //38240�ǲ�����
			printf("setupDCB success\n");
		if (setuptimeout(0, 0, 0, 0, 0))
			printf("setuptimeout success\n");
	}
	else
		std::cout << "cannot open the com port" << std::endl;
	SetCommMask(hComm, EV_RXCHAR); //�����ַ���inbuf��ʱ��������¼�
	//������ڵ����в���
	PurgeComm(hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
	// �ڶ�д����֮ǰ����Ҫ��PurgeComm()������ջ�����
	//PURGE_TXABORT	  �ж�����д�������������أ���ʹд������û����ɡ�
	//PURGE_RXABORT	  �ж����ж��������������أ���ʹ��������û����ɡ�
	//PURGE_TXCLEAR	  ������������
	//PURGE_RXCLEAR	  ������뻺����
	HANDLE hThread1 = CreateThread(NULL, 0, MyThread1, 0, 0, NULL);  //���߳�
	//HANDLE hThread2 = CreateThread(NULL, 0, MyThread2, 0, 0, NULL);  //д�߳�
	Sleep(100000000);
	CloseHandle(hThread1);
	//CloseHandle(hThread2);
	
	system("pause");
}