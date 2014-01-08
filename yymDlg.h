// yymDlg.h : header file
//
#include "MyPeFile.h"

#if !defined(AFX_YYMDLG_H__1FB734B4_063A_454A_AA4F_00275AB94060__INCLUDED_)
#define AFX_YYMDLG_H__1FB734B4_063A_454A_AA4F_00275AB94060__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CYymDlg dialog

class CYymDlg : public CDialog
{
// Construction
public:
	CYymDlg(CWnd* pParent = NULL);	// standard constructor
	
	MyPeFile myPeFile;
	CFile file;

// Dialog Data
	//{{AFX_DATA(CYymDlg)
	enum { IDD = IDD_YYM_DIALOG };
	CEdit	m_Text2;
	CListBox	m_listBox;
	CEdit	m_Text;
	CString	m_JM;
	CString	m_JQS;
	CString	m_RYCD;
	CString	m_RYQS;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYymDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CYymDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuQuit();
	afx_msg void OnSelchangeList1();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnMENUITEMyincangwenjian();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YYMDLG_H__1FB734B4_063A_454A_AA4F_00275AB94060__INCLUDED_)
