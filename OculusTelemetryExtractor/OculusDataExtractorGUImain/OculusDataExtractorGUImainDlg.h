
// OculusDataExtractorGUImainDlg.h : header file
#include"DataExtractor.h"

#pragma once

// COculusDataExtractorGUImainDlg dialog
class COculusDataExtractorGUImainDlg : public CDialogEx
{
private:
	//Enum used to get the appropriate pathStorage call
	enum{configFile,configPath,savPathTD};
	//Enum for the telemetry data type
	enum telType { AA = 1, AV, LA, LV, OR };
	//Instance of the DataExtractor
	DataExtractor dataEx;
	//bThreadRunning - Boolean which starts the loop within the main thread
	//confFilePath - Boolean which determines if the configuration file has been set or not
	//tdSavPath - Boolean which determines if the telemetry data save folder path has been set or not
	//bPause - Boolean which determines if the simulation has been paused or not
	//fileExist_ - Boolea which determine if the selected file exists or not - in .cpp
	//repeatSim - Boolean which determines if the simulation has been intitially ran or not
	//tdFolderChanged - Boolean which determines if the folder has been changed if repeatSim = true
	bool bThreadRunning, confFilePath, tdSavPath,
		bPause = false, fileExist_ = false,
		repeatSim = false, tdFolderChanged = false;
	//lineCount - the linecount within the telemetry data
	//rowNum - the row number within the live table
	int lineCount, rowNum;
	//A string array which holds the main file and folder paths -> check line 12 for enum
	std::string pathStorage[3];
	//Object used to find a file based on a file path
	CFileFind findFile_;
	//Objects used to communicate with the GUI config file path and telemetry data save folder path
	CMFCEditBrowseCtrl folderEdit_,fileEdit_;
	//Objects used to communicate with the GUI checkboxes
	CButton angAcc_, angVel_, linAcc_, linVel_, ori_,simCon_;
	//Object used to communicate with the live table 
	CListCtrl telemList;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OCULUSDATAEXTRACTORGUIMAIN_DIALOG };
#endif

// Implementation
protected:
	//Main icon
	HICON m_hIcon;
	//Method used to change window state - check cpp file for more documentation
	void changeAllWinState(const bool);
	//Method used to pause the simulation - check cpp file for more documentation
	void pauseSim(const bool);
	//Method used to change image - check cpp file for more documentation
	void changeImageNWait();
	//Method used to check if analysis mode is enabled - check cpp file for more documentation
	void isAnalysis(const bool);
	//Method used to set the telemetry data folder save path - check cpp file for more documentation
	void setTelemPath();
	//Method used to read and use the configuration file - check cpp file for more documentation
	void readConfigFile();
	//Main data exchange method
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	// Generated message map functions
	//Dialog Initialization method
	virtual BOOL OnInitDialog();
	//System command method
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//Paint method
	afx_msg void OnPaint();
	//Show icon when dragging method
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//Main Construction
	COculusDataExtractorGUImainDlg(CWnd* pParent = NULL);
	//Method used to translate key presses from input devices
	BOOL PreTranslateMessage(MSG * msg);
	//Method used to communicate with a button
	afx_msg void OnBnClickedHeadsetinit();
	//Method used to communicate with the about window
	afx_msg void OnBnClickedAboutbut();
	//Method used to communicate with a button
	afx_msg void OnBnClickedBegsim();
	//Method used to communicate with the configuration file browser
	afx_msg void OnEnChangeConfpathctl();
	//Method used to communicate with the telemetry data folder browser
	afx_msg void OnEnChangeSavpathctl2();
	//Method used to communicate with the create button in creating configuration file
	afx_msg void OnBnClickedCreateconf();
	//Method used to communicate with the menu button for about
	afx_msg void OnMabout();
	//Method used to communicate with the menu button for close
	afx_msg void OnMclose();
	//Method used to communicate with the menu button for quickguide
	afx_msg void OnHelpQuickguide();
	//Method used to communicate with the menu button for clear
	afx_msg void OnEditClear();
};
