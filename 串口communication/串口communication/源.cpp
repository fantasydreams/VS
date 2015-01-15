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
	while (hComm != INVALID_HANDLE_VALUE)              // 串口已被成功打开
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
	hComm = CreateFile(portname,  //串口号
		GENERIC_READ | GENERIC_WRITE,   //允许读和写
		0,								//通讯设备必须以独占的方式打开
		0,								//无安全保护机制
		OPEN_EXISTING,					//通讯设备已存在
		FILE_FLAG_OVERLAPPED,			//同步I/O              异步I/O是直接设置  0
		0);								//通讯设备不能用模板打开
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


bool setupdcb(int rate_arg)//设置DCB,先获取DCB配置，再设置，最后看是否设置//好
{
	DCB  dcb;
	int rate = rate_arg;
	memset(&dcb, 0, sizeof(dcb));//在一段内存块中填充某个给定的值，是对较大的结构//体或数组进行清零操作的一种最快方法
	if (!GetCommState(hComm, &dcb))//获取当前DCB配置
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
		// 在使用ReadFile 函数进行读操作前，应先使用ClearCommError函数清除错误

		if (comstat.cbInQue == 0)// COMSTAT结构返回串口状态信息
		{
			//本文只用到了cbInQue成员变量，该成员变量的值代表输入缓冲区的字节数
			Sleep(1000);
			continue;
		}
		if (bRead)
		{
			bResult = ReadFile(hComm, // Handle to COMM port串口的句柄

				&RXBuff,	// RX Buffer Pointer
				// 读入的数据存储的地址，即读入的数据将存
				//储在以该指针的值为首地址的一片内存区

				1,		  // Read one byte要读入的数据的字节数,

				&BytesRead, // Stores number of bytes read, 指向一个DWORD
				//数值，该数值返回读操作实际读入的字节数

				&m_ov);   		// pointer to the m_ov structure
			// 重叠操作时，该参数指向一个OVERLAPPED结构，同步操作时，该参数为NULL
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
				std::cout <<"平均值"<< sum / n <<"sum"<<sum<<"\tn"<<n<< std::endl;
				n++;*/
				
				if (n == 1000)
					system("pasue");
			}
			if (!bResult)// 当ReadFile和WriteFile返回FALSE时，不一定就是操作失//败，线程应该调用GetLastError函数分析返回的结果
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
		bResult = WriteFile(hComm,	// Handle to COMM Port, 串口的句柄

			m_szWriteBuffer,	// Pointer to message buffer in calling finction
			// 即以该指针的值为首地址的nNumberOfBytesToWrite
			// 个字节的数据将要写入串口的发送数据缓冲区

			m_nToSend,	// Length of message to send, 要写入的数据的字节数

			&BytesSent,	 // Where to store the number of bytes sent
			// 指向指向一个DWORD数值，该数值返回实际写入的字节数

			&m_ov);	    // Overlapped structure
		// 重叠操作时，该参数指向一个OVERLAPPED结构，
		// 同步操作时，该参数为NULL
		if (!bResult)  // 当ReadFile和WriteFile返回FALSE时，不一定就是操作失
			//败，线程应该调用GetLastError函数分析返回的结果
		{
			DWORD dwError = GetLastError();
			switch (dwError)
			{
			case ERROR_IO_PENDING: //GetLastError函数返回
				//ERROR_IO_PENDING。这说明重叠操作还未完成
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
		if (setupdcb(38420))    //38240是波特率
			printf("setupDCB success\n");
		if (setuptimeout(0, 0, 0, 0, 0))
			printf("setuptimeout success\n");
	}
	else
		std::cout << "cannot open the com port" << std::endl;
	SetCommMask(hComm, EV_RXCHAR); //当有字符在inbuf中时产生这个事件
	//清除串口的所有操作
	PurgeComm(hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
	// 在读写串口之前，还要用PurgeComm()函数清空缓冲区
	//PURGE_TXABORT	  中断所有写操作并立即返回，即使写操作还没有完成。
	//PURGE_RXABORT	  中断所有读操作并立即返回，即使读操作还没有完成。
	//PURGE_TXCLEAR	  清除输出缓冲区
	//PURGE_RXCLEAR	  清除输入缓冲区
	HANDLE hThread1 = CreateThread(NULL, 0, MyThread1, 0, 0, NULL);  //读线程
	//HANDLE hThread2 = CreateThread(NULL, 0, MyThread2, 0, 0, NULL);  //写线程
	Sleep(100000000);
	CloseHandle(hThread1);
	//CloseHandle(hThread2);
	
	system("pause");
}