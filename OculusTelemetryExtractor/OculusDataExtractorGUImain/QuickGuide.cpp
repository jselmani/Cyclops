// Default MFC dialog class implementation
// QuickGuide.cpp : implementation file

#include "stdafx.h"
#include "OculusDataExtractorGUImain.h"
#include "QuickGuide.h"
#include "afxdialogex.h"

// CQuickGuide dialog

IMPLEMENT_DYNAMIC(CQuickGuide, CDialogEx)

CQuickGuide::CQuickGuide(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_QGDIALOG, pParent)
{
}

CQuickGuide::~CQuickGuide()
{
}

void CQuickGuide::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CQuickGuide, CDialogEx)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

BOOL CQuickGuide::OnInitDialog() {
	//Resizes the window
	SetWindowPos(&CWnd::wndTop, 380,45, 1100, 980, SWP_FRAMECHANGED);
	return TRUE;
}

// CQuickGuide message handlers
