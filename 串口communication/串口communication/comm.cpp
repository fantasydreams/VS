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

				&Buffer,	// RX Buffer Pointer
				// ��������ݴ洢�ĵ�ַ������������ݽ���
				//�����Ը�ָ���ֵΪ�׵�ַ��һƬ�ڴ���

				12,		  // Read one byteҪ��������ݵ��ֽ���,

				&BytesRead, // Stores number of bytes read, ָ��һ��DWORD
				//��ֵ������ֵ���ض�����ʵ�ʶ�����ֽ���

				&m_ov);   		// pointer to the m_ov structure
			// �ص�����ʱ���ò���ָ��һ��OVERLAPPED�ṹ��ͬ������ʱ���ò���ΪNULL
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


Comm::Comm(LPCWSTR Port,bool *state)
{
	this->state = state;
	open = OpenPort(Port);
	if (open)
	{
		std::cout << "open comport success" << std::endl;
		if (setupdcb(38420))    //38240�ǲ�����
			printf("setupDCB success\n");
		if (setuptimeout(0, 0, 0, 0, 0))
			printf("setuptimeout success\n");
		SetCommMask(GethComm(), EV_RXCHAR); //�����ַ���inbuf��ʱ��������¼�
		//������ڵ����в���
		PurgeComm(GethComm(), PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
		// �ڶ�д����֮ǰ����Ҫ��PurgeComm()������ջ�����
		//PURGE_TXABORT	  �ж�����д�������������أ���ʹд������û����ɡ�
		//PURGE_RXABORT	  �ж����ж��������������أ���ʹ��������û����ɡ�
		//PURGE_TXCLEAR	  ������������
		//PURGE_RXCLEAR	  ������뻺����
		
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

bool Comm::setupdcb(int rate_arg)//����DCB,�Ȼ�ȡDCB���ã������ã�����Ƿ�����//��
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