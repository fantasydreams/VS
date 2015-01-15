#pragma once
#include <map>
#include <list>
#pragma warning(disable : 4786)


// CItemPanel
class CMatchItem; 
//�м������ذ�ť�߶�
#define HIDDING_HEIGHT		24
//�б�ĸ߶�
#define  PANELHIGHT			225
//ÿ�еĸ߶�
#define UNIT_HEIGHT			225
//���
#define UNIT_SPACE			15
//ͼƬ�ĸ߶�
#define IMAGE_HEIGHT		190
//ͼƬ�Ŀ��
#define IMAGE_WIDTH			130
//����������С
#define SCROLL_UNIT			5
//ͼƬ�ı߿�
#define IMAGE_MARGIN		15
#define MARGIN_ENLARGE		7
#define IMAGE_ENLARGE		IMAGE_MARGIN - MARGIN_ENLARGE
#define IMAGE_SPACE			10
//�������
#define BACKGROUND_CTWO		RGB(0x39,0x4c,0x6c)
#define BACKGROUND_CONE		RGB(0x39,0x4c,0x6c)
//����ƹ�ʱ����ɫ
#define BACKGROUND_COVER	RGB(0x46,0x5e,0x86) 
//�еı�����ɫ
#define PANELBACKGROUND		RGB(0x96,0xc7,0xef)
//�����ٶȣ��²�������ʱ���ٶȣ�
#define INSERTCONFIGSPEED	30

//������������
#define MAX_ROW				100
//ÿ����չ60����λ����
#define BUFFER_ROW			MAX_ROW/10
//ÿ�β�������
#define CLEARRANGE			MAX_ROW/10

#define MAX_ITEM_NUM        60  

typedef struct srt 
{ 
	char strSrcImgPath[256];		// ��Ҫ��ƥ���ͼƬ�ı���·��
	char strFoundImgPath[256];	    // ƥ���ͼƬ�ı���·��
	char strName[16];               // ��Ա����
	char strIdCode[32];		    	// ���֤ID
	char strSex[64];                // �Ա�
	char strBirthday[64];		    // ����	
	int		nIndex;					// ���б��е�����
} Item;

class CItemPanel : public CWnd
{
	DECLARE_DYNAMIC(CItemPanel)
public:
//	Tools::CPicBuffer  test;
	typedef std::map<int,CMatchItem*> ActiveList_t;
	typedef std::list<Item> m_pList;
public:
	CItemPanel();
	~CItemPanel();

	virtual BOOL Create(CWnd* pParentWnd);

	//���¼������ݴ�С���͸��¹�������
	virtual void Update(); 
protected:
	ActiveList_t	m_ItemUIList;//����ʾ���б�
	Item**			m_pItems;//�б�
	DWORD			m_nItems;//������
	DWORD			m_nIncreaseSection;//ÿ�����ӵĻ����С
	int				m_nCountPerPage;//ÿҳ������ 
	DWORD			m_nScrollCountPerPage;
	int				m_nScrollClipHight;
	int				m_nAccelerate;
	DWORD			m_nTopIndex;
	DWORD			m_nHitIndex;
	DWORD			m_nBottomIndex;
	DWORD			m_nFocus;
	CFont			m_font;
	int				m_nBuffer;
	BOOL			m_nInserting;
public:
	void	InsertItem(Item stItem); //��¶������ķ���
	void    DeleteAllItems();

	void	UpdateVScroll(DWORD nScroll);
	void	ScrollVToPosition(DWORD nIndex);
	void	ScrollByVertical(int nDelta);
	void	ScrollToVertical(DWORD nIndex);
	void	InitialItems();
	BOOL	TestPtInWnd();
	void	DrawEmptyNotification(CDC& dc, CRect& rcClient,int ndebug = 0);

protected:
	DECLARE_MESSAGE_MAP()
	int	m_nScrollWheelLines;	// �����ֹ���һ�λ���������

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

class CMatchItem : public CWnd
{
	DECLARE_DYNAMIC(CMatchItem)

public:
	CMatchItem();
	~CMatchItem();
	Item *m_pItem;
	virtual BOOL Create(CWnd* pParentWnd,CRect rc);

public:
	void DrawImage(CDC *pDC,CRect,BOOL isSrc = TRUE);
	void DrawText(CDC *pDC,CRect);
	BOOL TestPtInImageMatch(CPoint point);
	BOOL TestPtInImageSrc(CPoint point);
	void TestPtInWnd();
	void DrawBackground(CDC *pDC,CRect rc);
	void ExcludeFrame(CRect& rcClient);

protected:
	BOOL  m_bOver;
	BOOL  m_bOverPicSrc;
	BOOL  m_bOverPicMatch;
	CRect m_rcRangeSrc;
	CRect m_rcRangeMatch;
	CFont m_font;
	CFont m_fontBold;
	CRect m_rcFrameSrc;
	CRect m_rcContentSrc;

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

