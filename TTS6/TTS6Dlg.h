// TTS6Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "agentctlex.h"
//}}AFX_INCLUDES

#if !defined(AFX_TTS6DLG_H__CDE69FC4_A13B_4627_AB13_C1D3217BE79C__INCLUDED_)
#define AFX_TTS6DLG_H__CDE69FC4_A13B_4627_AB13_C1D3217BE79C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "agentctlcharacters.h"
#include "agentctlcharacterex.h"
#include "agentctlrequest.h"

/////////////////////////////////////////////////////////////////////////////
// CTTS6Dlg dialog

class CTTS6Dlg : public CDialog
{
// Construction
public:
	CTTS6Dlg(CWnd* pParent = NULL);	// standard constructor
public:
	void ModifyFont( );
	BOOL Spreak();
	BOOL Recognition(LPVOID pParam);
	static UINT RegThread(LPVOID pParam);//ʶ��ѭ���߳�
	static UINT RespondThread( LPVOID pParam );//����ʶ���������Ӧ�߳�
	static UINT ReadThread(LPVOID pParam);//�ʶ��߳�
	BOOL Move_To(int x,int y,LPVOID pParam=NULL);//�����ƶ�����
public:
	CAgentCtlCharacters m_Characters;
	CAgentCtlCharacterEx m_Ex;
	CAgentCtlRequest m_Request;
	static CAgentCtlCharacterEx *m_Static_m_Ex;
public:
	int m_x;
	int m_y;
	CString m_strListen;//����ʶ��������ַ�����Ŵ�
	BOOL m_stop;//����ʶ�𿪹�
// Dialog Data
	//{{AFX_DATA(CTTS6Dlg)
	enum { IDD = IDD_TTS6_DIALOG };
	CRichEditCtrl	m_wndRichEdit;
	CAgentCtlEx	m_Agent;//����ؼ�
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTTS6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTTS6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetfont();
	afx_msg void OnRead();
	afx_msg void OnFont2();
	afx_msg void OnRecognition();
	afx_msg void OnSpiritInit();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStopreg();
	afx_msg void OnStartreg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTS6DLG_H__CDE69FC4_A13B_4627_AB13_C1D3217BE79C__INCLUDED_)
