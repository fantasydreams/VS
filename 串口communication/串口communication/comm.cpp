#include "header.h"

void Comm::ReceiveChar()
{
	BOOL  bRead = TRUE;
	BOOL  bResult = TRUE;
	DWORD dwError = 0;
	DWORD BytesRead = 0;
	char Buffer[13];
	while (true)
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

				&Buffer,	// RX Buffer Pointer
				// 读入的数据存储的地址，即读入的数据将存
				//储在以该指针的值为首地址的一片内存区

				12,		  // Read one byte要读入的数据的字节数,

				&BytesRead, // Stores number of bytes read, 指向一个DWORD
				//数值，该数值返回读操作实际读入的字节数

				&m_ov);   		// pointer to the m_ov structure
			// 重叠操作时，该参数指向一个OVERLAPPED结构，同步操作时，该参数为NULL
			//printf("%c", RXBuff);

			Buffer[12] = 0;
			//Buffer[9] = ' ';
			/*
			std::cout << Buffer << " "
			<< Buffer + 5;
			*/
			/*
			printf(Buffer);
			printf(" ");
			printf(Buffer + 5);
			*/
			printf("%d\n", Buffer[10]);
			
			WriteToFile(Buffer);
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

bool Comm::WriteChar(BYTE* m_szWriteBuffer, DWORD m_nToSend)
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


Comm::Comm(LPCWSTR Port,bool *state)
{
	this->state = state;
	open = OpenPort(Port);
	if (open)
	{
		std::cout << "open comport success" << std::endl;
		if (setupdcb(38420))    //38240是波特率
			printf("setupDCB success\n");
		if (setuptimeout(0, 0, 0, 0, 0))
			printf("setuptimeout success\n");
		SetCommMask(GethComm(), EV_RXCHAR); //当有字符在inbuf中时产生这个事件
		//清除串口的所有操作
		PurgeComm(GethComm(), PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
		// 在读写串口之前，还要用PurgeComm()函数清空缓冲区
		//PURGE_TXABORT	  中断所有写操作并立即返回，即使写操作还没有完成。
		//PURGE_RXABORT	  中断所有读操作并立即返回，即使读操作还没有完成。
		//PURGE_TXCLEAR	  清除输出缓冲区
		//PURGE_RXCLEAR	  清除输入缓冲区
		
	}
	else
		std::cout << "cannot open the com port" << std::endl;
	
}


Comm::~Comm()
{

}

bool Comm::ProcessErrorMessage(char* ErrorText)
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
	sprintf_s(Temp, sizeof(Temp), "WARNING:  %s Failed with the following error: \n%s\nPort: %d\n", (char*)ErrorText, lpMsgBuf, "com2");
	MessageBox(NULL, LPCWSTR(Temp), _T("Application Error"), MB_ICONSTOP);
	LocalFree(lpMsgBuf);
	delete[] Temp;
	return true;
}





bool Comm::OpenPort(LPCWSTR portname)
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

bool Comm::setuptimeout(DWORD ReadInterval, DWORD ReadTotalMultiplier, DWORD ReadTotalconstant, DWORD WriteTotalMultiplier, DWORD WriteTotalconstant)
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

bool Comm::setupdcb(int rate_arg)//设置DCB,先获取DCB配置，再设置，最后看是否设置//好
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



HANDLE Comm::GethComm()
{
	return hComm;
}


void Comm::WriteToFile(char *buffer)
{
	int id = (buffer[0] - '0') + (buffer[1] - '0') * 10 + (buffer[2] - '0') * 100 + (buffer[3] - '0') * 100;
	if (state[id] == false)
	{
		fopen_s(&fp, buffer, "a+");
		buffer[9] = ' ';
		fwrite(buffer+5, 7, 1,fp);
		//std::cout << ftell(fp) << std::endl;
		if (ftell(fp) == 32)
		{
			fclose(fp);
			state[id] = true;
		}
		else
			fclose(fp);
	}
}