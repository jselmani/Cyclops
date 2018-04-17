#pragma once
//Default dialog window for the quickguide

// CQuickGuide dialog

class CQuickGuide : public CDialogEx
{
	DECLARE_DYNAMIC(CQuickGuide)

public:
	CQuickGuide(CWnd* pParent = NULL);   // standard constructor
	virtual ~CQuickGuide();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QGDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//Initialization method
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
};
