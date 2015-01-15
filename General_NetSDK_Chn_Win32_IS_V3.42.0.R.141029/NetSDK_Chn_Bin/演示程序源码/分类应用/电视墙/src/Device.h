// Device.h: interface for the CDevice class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __DEVICE_H__
#define __DEVICE_H__

#include "Util.h"

class CDevice;
class CDeviceFactory
{
public:
	enum { Decoder, Encoder };

	static CDevice* Create(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL, LPCTSTR lpszDevClass = "Unknown", UINT nType = Decoder);
};

// �����豸ͨ��
class CDecChannel
{
public:
	CDecChannel(int _nChannelID = -1, int _nCardID = -1, int _nCardSlot = -1, int _nMaxSources = 0);
	
	LPCTSTR ToString() const;
	
public:
	int						m_nChannelID;				// ͨ����
	int						m_nCardID;					// ����
	int						m_nCardSlot;				// ����
	int						m_nMaxSources;				// ֧�ֵ������ʾԴ������
	UINT					m_nSplitModes[32];			// ֧�ֵķָ�ģʽ, ��0��β
	BOOL					m_bPartOfSpliceScreen;		// �ں�������ɲ���, ����ͨ��������ͨ��һ�����һ���ں���
	BOOL					m_bSpliceScreen;			// �Ƿ��ں���
	CString					m_strName;					// �ں�������
};
typedef std::map<int, CDecChannel> CDecChnMap;

// �����豸ͨ��
class CEncChannel
{
public:
	CEncChannel(int _nChannelID = -1, int _nCardID = -1, int _nCardSlot = -1);
	
	LPCTSTR ToString() const;
	
public:
	int						m_nChannelID;				// ͨ����
	int						m_nCardID;					// ����
	int						m_nCardSlot;				// ����
	CString					m_strName;					// ͨ����
	CString					m_strAnalogMatrix;			// ����ģ�����, ������Ч
	CString					m_strRemoteDevice;			// ����Զ���豸ID, ������Ч
	CString					m_strDevID;					// �豸ID, AnalogMatrixID or RemoteDeviceID
};
typedef std::map<int, CEncChannel> CEncChnMap;

// �����豸��Ϣ
class CDevice
{	
public:
	CDevice(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL, LPCTSTR lpszDevClass = "Unknown");
	
	LPCTSTR GetDeviceClass() const { return m_pszDeviceClass; }

	LLONG	GetHandle() const { return m_lLoginID; }

	LPCTSTR GetIP() const { return m_strIP; }
	int		GetPort() const { return m_nPort; }
	LPCTSTR GetUser() const { return m_strUser; }
	LPCTSTR GetPwd() const { return m_strPwd; }

	void	SetHandle(LLONG lLoginID) { m_lLoginID = lLoginID; }
	void	SetLoginInfo(LPCTSTR lpszIP, int nPort, LPCTSTR lpszUser, LPCTSTR lpszPwd);
	
protected:
	LLONG		m_lLoginID;
	UINT		m_nPort;
	CString		m_strIP;
	CString		m_strUser;
	CString		m_strPwd;
	LPCTSTR		m_pszDeviceClass;	// �豸����
};

#define DECLARE_DEVICE_CLASS(s)	static LPCTSTR DCID() { return s; }

// �����豸
class CDecoder : public CDevice
{
public:
	CDecoder(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL, LPCTSTR lpszDevClass = NULL);
	
	DECLARE_DEVICE_CLASS("Decoder");

	virtual BOOL Update();
	virtual BOOL UpdateCompositeChannel();
	virtual BOOL UpdateNormalChannel();

	CDecChannel* GetDecodeChannel(int nChannel); 
	const CDecChannel* GetDecodeChannel(int nChannel) const; 

	CDecChnMap&	 GetDecChnMap() { return m_mapDecChn; }
	const CDecChnMap& GetDecChnMap() const { return m_mapDecChn; }
	
protected:
	CDecChnMap	m_mapDecChn;		// ����ͨ����Ϣ
	DH_PRODUCTION_DEFNITION m_stuProdDef;
	int			m_nSpliceCount;		// ƴ��������
};

// �������
class CDecoderMatrix : public CDecoder
{
public:
	CDecoderMatrix(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);

	DECLARE_DEVICE_CLASS("Matrix");

	virtual BOOL UpdateNormalChannel();
};

// ����NVR
class CDecoderNVR : public CDecoder
{
public:
	CDecoderNVR(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);

	DECLARE_DEVICE_CLASS("NVR");

	virtual BOOL UpdateCompositeChannel();
};

// ����NVD
class CDecoderNVD : public CDecoder
{
public:
	CDecoderNVD(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);
	
	DECLARE_DEVICE_CLASS("NVD");

	virtual BOOL UpdateCompositeChannel();
};

// �������������
class CDecoderDSCON : public CDecoder
{
public:
	CDecoderDSCON(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);
	
	DECLARE_DEVICE_CLASS("DSCON");
	
	virtual BOOL UpdateNormalChannel();
};







/************************************************************************/
/*                              �����豸                                */
/************************************************************************/

// �����豸
class CEncoder : public CDevice
{
public:
	CEncoder(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL, LPCTSTR lpszDevClass = NULL);

	DECLARE_DEVICE_CLASS("Encoder");

	virtual BOOL Update();
	virtual BOOL UpdateNormalChannel();
	
	CEncChannel* GetEncodeChannel(int nChannel); 
	CEncChnMap&	 GetEncChnMap() { return m_mapEncChn; }

	void		Online(BOOL bOnline = TRUE) { m_bOnline = bOnline; }
	BOOL		IsOnline() const { return m_bOnline; }
	
protected:
	CEncChnMap	m_mapEncChn;		// ����ͨ����Ϣ
	BOOL		m_bOnline;			// ����״̬

public:
	CString		m_strDevClass;		// �豸����, ����豸ʱ���û�����
	CString		m_strDevModel;		// �豸�ͺ�, ����豸ʱ���û�����
};

// �������
class CEncoderMatrix : public CEncoder
{
public:
	CEncoderMatrix(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);
	
	DECLARE_DEVICE_CLASS("Matrix");

	virtual BOOL UpdateNormalChannel();
	
protected:
};

// ����NVR
class CEncoderNVR : public CEncoder
{
public:
	CEncoderNVR(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);
	
	DECLARE_DEVICE_CLASS("NVR");
	
protected:
};

// ����NVD
class CEncoderNVD : public CEncoder
{
public:
	CEncoderNVD(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);
	
	DECLARE_DEVICE_CLASS("NVD");

	virtual BOOL UpdateNormalChannel();
	
protected:
};

// �������������
class CEncoderDSCON : public CEncoder
{
public:
	CEncoderDSCON(LLONG lLoginID, LPCTSTR lpszIP, int nPort = 37777, LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);
	
	DECLARE_DEVICE_CLASS("DSCON");
	
	virtual BOOL UpdateNormalChannel();
	
protected:
};

#endif
