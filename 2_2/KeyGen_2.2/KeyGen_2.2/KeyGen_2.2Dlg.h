
// KeyGen_2.2Dlg.h : header file
//

#pragma once
#include "KeyGen.h"

// CKeyGen22Dlg dialog
class CKeyGen22Dlg : public CDialogEx
{
// Construction
public:
	CKeyGen22Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KEYGEN_22_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	CEdit m_editCtrl;
	CString m_strTextCtrl;
	KeyGen Key;
};
