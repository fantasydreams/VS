// Common.h: interface for the CCommon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMON_H__D9E1918F_1913_4DA5_9303_BDF22FED44C5__INCLUDED_)
#define AFX_COMMON_H__D9E1918F_1913_4DA5_9303_BDF22FED44C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define		THUMWIDTH		32
#define		THUMHEIGHT		32

#define _DELETE_(x) if(x){delete x;x = NULL;}
#define _DEL_ARRAY_(x) if(x){delete [] x; x = NULL;}
#define MEM_ZERO(stu) memset(&stu, 0, sizeof(stu))
#define SET_SIZE(stu) stu.dwSize = sizeof(stu)

typedef enum _VIDEO_STANDARD    //��Ƶ��ʽ 
{
	PAL = 0,
	NTSC
} VIDEO_STANDARD;

typedef struct tagRESOLUTION
{
    CAPTURE_SIZE	emType;		//�ֱ�����
	int		nWidth;
	int		nHeight;
	char*   pTypeName;
} RESOLUTION, *PRESOLUTION, *LPRESOLUTION;

void Change_Utf8_Unicode(unsigned char * pUTF8, char *destbuf, int nUTF8Len, int nUniCodeLen);
void Change_Unicode_UTF8(char *pStrGBKData, int nlen, char *pbuf, int buflen);
void Change_Utf8_Assic(unsigned char * pUTF8, char *destbuf, int nUTF8Len, int nUnicodeLen);
void Change_Assic_UTF8(char *pStrGBKData, int nlen, char *pbuf, int buflen);

class CCommon  
{
public:
	int GetStrUTF8LengthFromGBK(char *pStrGBKData);
	CCommon();
	virtual ~CCommon();

	CString GetSysDataString(int nYear, int nMonth, int nDay);
		
	//CComboBox
	static int InitComboBox(CComboBox *pCComboBox , int nIndex, LPCTSTR lpszString, DWORD dwData = 0);

	//�����ڲ�����
	static int SetCurSelByData(CComboBox *pCComboBox, DWORD dwData);

	//��ȡIP
	CString GetIP(CIPAddressCtrl* pIPAddressCtrl);
	//��ʾIP��ַ
	void ShowIP(CIPAddressCtrl* pIPAddressCtrl, LPCTSTR lpszIP);

	CString GetCStringLeft(LPCTSTR lpszString, int nCount = -1);//-1������ȡ�ַ����ս��Ϊֹ
	
	//��ȡ����µ�����
	int GetMonthDays(DWORD dwYear, DWORD dwMonth);
	
	void CheckEditLimitNum(CWnd* pWnd, DWORD dwMin, DWORD dwMax);

	CString GetEditTextByLimit(CWnd* pWnd);

	BOOL FilterSpecialWord(char *pStrInput, int len );

	//��������ǲ�������
	BOOL CheckEditIsNum(CWnd* pWnd);
	//ȥ����β�ո�
	BOOL CheckEditSpace(CWnd* pWnd , int nType = 1);//0Ϊȥ�����пո�  1Ϊ��ȥ�� �м�ո� 
	
//	HBITMAP LoadPicture(CString theFileName, CWnd* pWnd, long lWidth = THUMWIDTH, long lHeight = THUMHEIGHT);

	CString Get_Utf8_To_Unicode(unsigned char * pUTF8);
    
	BOOL CheckAllChr(CWnd* pWnd);
	BOOL CheckAllNum(CWnd* pWnd);
	

	int log2i(unsigned long x);
	//д����  
	BOOL		WriteStructInfo(  LPCTSTR lpszSection,  // section name
								  LPCTSTR lpszKey,      // key name
								  char*   lpStruct,     // data buffer
								  UINT    uSizeStruct,  // size of data buffer
								  LPCTSTR szFile        // initialization file
								);

	//������
	BOOL		ReadStructInfo(	  LPCTSTR lpszSection,  // section name
								  LPCTSTR lpszKey,      // key name
								  char*   lpStruct,     // return buffer
								  UINT	  uSizeStruct,  // size of return buffer
								  LPCTSTR szFile        // initialization file name
								);


		/************************************************************************
	*	�������ƣ�	ReadResolution
	*	����������	��ȡ�ֱ��ʽṹ��
	*	�����б�	lpszResolution	����[IN, OUT]�ֱ��ʽṹ��
	*				emVideoStandard	����[IN]��Ƶ��ʽ, Ĭ��PAL
	*				bSort			����[IN]�Ƿ�����Ĭ�ϲ�����
	*	����ֵ��	��ȡ�ɹ�����TRUE��ʧ�ܷ���FALSE;
	************************************************************************/
	BOOL ReadResolution( LPRESOLUTION    lpszResolution,         // ���صķֱ��ʽṹ��
						 int             nResoStructSize,        // �ֱ��ʽṹ���С
						 VIDEO_STANDARD  emVideoStandard = PAL,  // ��Ƶ��ʽ
						 BOOL            bSort = FALSE           // �Ƿ�����Ĭ�ϲ�����
						);
protected:

	int m_nDataMode;
private:
	static int compare(const void *arg1, const void *arg2); // ��������ֱ��ʵıȽϺ���
};

#endif // !defined(AFX_COMMON_H__D9E1918F_1913_4DA5_9303_BDF22FED44C5__INCLUDED_)
