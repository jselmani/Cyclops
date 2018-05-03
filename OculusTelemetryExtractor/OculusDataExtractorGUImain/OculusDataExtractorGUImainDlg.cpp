
// OculusDataExtractorGUImainDlg.cpp : Main dialog implementation file

#include "stdafx.h"
#include "OculusDataExtractorGUImain.h"
#include "OculusDataExtractorGUImainDlg.h"
#include "QuickGuide.h"
#include "afxdialogex.h"
#include <cstring>
#include <string>
#include <windef.h>
#include "Resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg class implements the About window Dialog
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
//Default constructor for the About Dialog window, which passes 
//in the designed about dialog box in the base dialog class
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX){}
//Data exchange between the base dialog class and the about dialog 
void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}
//Map key messages to the About Dialog.
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//Mapping the About Dialog Window and the OK button within the About Dialog Window
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


//COculusDataExtractorGUImainDlg class is the class that represents 
//the main dialog window (GUI) of the application

//This default constructor creates a single instance of the main dialog window
//pParent - parent dialog
COculusDataExtractorGUImainDlg::COculusDataExtractorGUImainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OCULUSDATAEXTRACTORGUIMAIN_DIALOG, pParent) {
	//Load the main Oculus icon that is used for the application
	m_hIcon = AfxGetApp()->LoadIcon(IDR_OCULUSICON);
}

//This method is the method that does data exchanges between different objects in the GUI
//pDX - Data exchange pointer
void COculusDataExtractorGUImainDlg::DoDataExchange(CDataExchange* pDX) {
	//Starting initial data exchange with the original base class of the dialog window: CDialogEx
	CDialogEx::DoDataExchange(pDX);
	//Data exchange between the GUI and relatable Object: Configuration File Selection
	DDX_Control(pDX, IDC_CONFPATHCTL, fileEdit_);
	//Data exchange between the GUI and relatable Object: Save Path for the Telemetry Data
	DDX_Control(pDX, IDC_SAVPATHCTL2, folderEdit_);
	//Data exchange between the GUI and relatable Object: Angular Acceleration Checkbox
	DDX_Control(pDX, IDC_CHK1, angAcc_);
	//Data exchange between the GUI and relatable Object: Angular Velocity Checkbox
	DDX_Control(pDX, IDC_CHK3, angVel_);
	//Data exchange between the GUI and relatable Object: Linear Acceleration Checkbox
	DDX_Control(pDX, IDC_CHK2, linAcc_);
	//Data exchange between the GUI and relatable Object: Linear Velocity Checkbox
	DDX_Control(pDX, IDC_CHK4, linVel_);
	//Data exchange between the GUI and relatable Object: Orientation Checkbox
	DDX_Control(pDX, IDC_CHK5, ori_);
	//Data exchange between the GUI and relatable Object: Table of Live Telemetry Data 
	DDX_Control(pDX, IDC_TDLIST, telemList);
}
//Message Mapping between created methods and their associated GUI object
BEGIN_MESSAGE_MAP(COculusDataExtractorGUImainDlg, CDialogEx)
	//Default Message Mapping for System
	ON_WM_SYSCOMMAND()
	//Default Message Mapping for the paint method
	ON_WM_PAINT()
	//Default Message Mapping for DragIcon
	ON_WM_QUERYDRAGICON()
	//Default Message Mapping for Color Control
	ON_WM_CTLCOLOR()
	//Message Mapping between the "Initialize Headset" button and its associated method
	ON_BN_CLICKED(IDC_HEADSETINIT, &COculusDataExtractorGUImainDlg::OnBnClickedHeadsetinit)
	//Message Mapping between the menu "Help"->"About" button and its associated method
	ON_BN_CLICKED(IDC_ABOUTBUT, &COculusDataExtractorGUImainDlg::OnBnClickedAboutbut)
	//Message Mapping between the "Begin Simulation" button and its associated method
	ON_BN_CLICKED(IDC_BEGSIM, &COculusDataExtractorGUImainDlg::OnBnClickedBegsim)
	//Default Message Mapping for Changing Font
	ON_WM_FONTCHANGE()
	//Message Mapping between the "Config File Path"s browse button and its associated method
	ON_EN_CHANGE(IDC_CONFPATHCTL, &COculusDataExtractorGUImainDlg::OnEnChangeConfpathctl)
	//Message Mapping between the "Telemetry Data Save Path"s browse button and its associated method
	ON_EN_CHANGE(IDC_SAVPATHCTL2, &COculusDataExtractorGUImainDlg::OnEnChangeSavpathctl2)
	//Message Mapping between the "Create" button that is part of "Create Configuration File" and its associated method
	ON_BN_CLICKED(IDC_CREATECONF, &COculusDataExtractorGUImainDlg::OnBnClickedCreateconf)
	//Message Mapping between the menu "Help"->"About" button and its associated method
	ON_COMMAND(ID_MABOUT, &COculusDataExtractorGUImainDlg::OnMabout)
	//Message Mapping between the menu "File"->"Close" button and its associated method
	ON_COMMAND(ID_MCLOSE, &COculusDataExtractorGUImainDlg::OnMclose)
	//Message Mapping between the menu "Help"->"Quick Guide" button and its associated method
	ON_COMMAND(ID_HELP_QUICKGUIDE, &COculusDataExtractorGUImainDlg::OnHelpQuickguide)
	//Message Mapping between the "Edit"->"Clear" button and its associated method
	ON_COMMAND(ID_EDIT_CLEAR32781, &COculusDataExtractorGUImainDlg::OnEditClear)
	END_MESSAGE_MAP()
//This method is responsible for translating the keys that are being pressed down
//msg - the incoming key press from input devices
//Return - True if successfull : False if otherwise
BOOL COculusDataExtractorGUImainDlg::PreTranslateMessage(MSG* msg) {
	if (msg->message == WM_KEYDOWN){
		if ((msg->wParam == VK_RETURN) || (msg->wParam == VK_ESCAPE))
			msg->wParam = VK_UP;
	}
	return CDialog::PreTranslateMessage(msg);
}

// COculusDataExtractorGUImainDlg class Initialization method on start
//Return - True if successfull : False if otherwise
BOOL COculusDataExtractorGUImainDlg::OnInitDialog() {
	//Call base dialog class initialization method
	CDialogEx::OnInitDialog();

	//Default Initialization process

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL){
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()){
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//COculusDataExtractorGUImainDlg class specific initialization process
	//Set welcome text with start instructions to get the telemetry data extractor started
	addToOutput(AfxGetMainWnd(), "---Welcome to The Oculus Rift Telemetry Extractor!", IDC_TXTOUTPUT);
	addToOutput(AfxGetMainWnd(), "---Check out the Quick Guide in the Help menu for detailed operating instructions!", IDC_TXTOUTPUT);
	addToOutput(AfxGetMainWnd(),"To begin simulation, please initialize the headset and specify the path to the configuration file and the path where the telemetry data will be saved. If no configuration file exists, please create one!",IDC_TXTOUTPUT,1);
	//Enable Browse Settings
	//Enables the browser dialog as a folder browser
	folderEdit_.EnableFolderBrowseButton();
	//Enables the browser dialog as a file browser showing only .csv files
	fileEdit_.EnableFileBrowseButton(_T("csv"),_T("CSV Files|*.csv||"));
	//Set default booleans that are used to determine whether or not a file or a folder path, 
	//has been selected in the GUI
	confFilePath = false;
	tdSavPath = false;
	//Set Telemetry Output Columns - Set the first column - "Time"
	telemList.InsertColumn(0, _T("Time"), LVCFMT_CENTER, 100);
	//Send the main dialog window into the data extractor dataEx to be set for outputting the telemetry data
	dataEx.setDlg(AfxGetMainWnd());
	return TRUE;  // return TRUE  unless you set the focus to a control
}
//Method that would ensure to call the default about dialog class when the about dialog class is initialized
//nID - instance of UINT object representing the process id
//lparam - instance of LPARAM object representing the executing command
void COculusDataExtractorGUImainDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	//Default process
	if ((nID & 0xFFF0) == IDM_ABOUTBOX){
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
		CDialogEx::OnSysCommand(nID, lParam);
}
//This method draws out the default contents of the dialog box - major changes to font/color/etc... would occur here
void COculusDataExtractorGUImainDlg::OnPaint() {
	//Default Paint process
	if (IsIconic()){
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
		CDialogEx::OnPaint();
}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
//Return - the instance of the cursor
HCURSOR COculusDataExtractorGUImainDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}
//This method is used to pause the simulation by manipulating the associated GUI button and
//changing the bPause boolean that would actually pause the simulation
//isPause_ - True if the simulation has been requested to pause : False if simulation has requested to continue
void COculusDataExtractorGUImainDlg::pauseSim(const bool isPause_) {
	if (isPause_) {
		//Change the button to "Continue Simulation" once the Pause has been activated in GUI
		GetDlgItem(IDC_HEADSETINIT)->SetWindowTextW(_T("Continue Simulation"));
		//Set the pause boolean to true so that the data extractor thread would pause
		bPause = true;
		//Send to the output window that Sim has been paused
		addToOutput(AfxGetMainWnd(), "Simulation Paused!", IDC_TXTOUTPUT, 1);
	}
	else {
		//Change the button to "Pause Simulation" once the Continue has been activated in GUI
		GetDlgItem(IDC_HEADSETINIT)->SetWindowTextW(_T("Pause Simulation"));
		//Set the pause boolean to true so that the data extractor thread would pause
		bPause = false;
		//Send to the output window that Sim has continued
		addToOutput(AfxGetMainWnd(), "Simulation Unpaused!", IDC_TXTOUTPUT, 1);
	}
}
//This method is intended to change the oculus rift picture with the red X
//into the oculus rift picture with the green checkmark once the headset has been initialized,
//as well as wait for oculus home to open
void COculusDataExtractorGUImainDlg::changeImageNWait() {
	CBitmap bitMapChg;
	//Load the image into the variable created above
	bitMapChg.LoadBitmap(IDB_BITMAPCHK);
	//Receive the picture frame form GUI
	CStatic* picDlg = (CStatic*)GetDlgItem(IDC_PICFRAME);
	//Ensure that the new image will be centered and it will be a bitmap image
	picDlg->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//Send to output window for user to wait
	addToOutput(AfxGetMainWnd(), "Please Wait for Oculus App to Open Before Starting Simulation", IDC_TXTOUTPUT, 1);
	//Sets the new "Pause Simulation" button to disabled - will be enabled on Begin Sim
	GetDlgItem(IDC_HEADSETINIT)->EnableWindow(false);
	//Change the waiting time for Ocuclus App to Open
	Sleep(10000);
	//Set the new picture into the picture frame
	picDlg->SetBitmap(bitMapChg);
	//Sleep in order to ensure that every process has come to a complete end to ensure no errors by means of GUI intervention
	Sleep(300);
}
//This method is responsible for processing multiple tasks related to the "Initialize Headset" button.
//During the simulation process, depending on what is needed at the time, the button's actions will change accordingly.
void COculusDataExtractorGUImainDlg::OnBnClickedHeadsetinit() {
	//This variable is used to hold the text of the button
	CString buttonText;
	//Call dialog method to receive the text of the button
	GetDlgItem(IDC_HEADSETINIT)->GetWindowText(buttonText);
	//If the button text is "Initialize Headset" continue...
	if (buttonText == _T("Initialize Headset")) {
		//Call Data Extractor method to intialize the headset. If the headset has been initialed continue...
		if (dataEx.initHeadset()/*true*/) {
			//Change the text of the button to represent the current action that is required
			//-the system will now have the ability to pause the simulation while the simulation is running
			GetDlgItem(IDC_HEADSETINIT)->SetWindowTextW(_T("Pause Simulation"));
			//Change the oculus image to have a green checkmark
			changeImageNWait();
			//Enables the "Begin Simulation" button
			GetDlgItem(IDC_BEGSIM)->EnableWindow(true);
			//Tell the user in the output window that Sim is ready to run
			addToOutput(AfxGetMainWnd(), "Oculus App Should Now be Open!", IDC_TXTOUTPUT, 1);
		}
		else
			//Provides an error into the output window that initialization has failed
			addToOutput(AfxGetMainWnd(), "Error: Headset Initialization has Failed!", IDC_TXTOUTPUT, 2);
	}
	//If the button text is "Pause Simulation" continue...
	else if (buttonText == _T("Pause Simulation")) 
		//Pause the simulation
		pauseSim(true);
	//If the button text is "Continue Simulation" continue...
	else if (buttonText == _T("Continue Simulation")) 
		//Continue the simulation
		pauseSim(false);
	
}
//This method is responsible for opening up the about dialog window by means of a menu option
//"Help" -> "About"
void COculusDataExtractorGUImainDlg::OnBnClickedAboutbut(){
	CWnd* AboutWin;
	CAboutDlg AboutDlg;
	AboutWin = &AboutDlg;
	AboutDlg.DoModal();
}
//This method is responsible for disabling or enabling the below GUI states,
//based on whether or not the simulation is enabled.
//state - True if requested to re-enable the involved frames : False if requested to disable the inovled frames
void COculusDataExtractorGUImainDlg::changeAllWinState(const bool state) {
	//Change state of browse for configuration file field
	GetDlgItem(IDC_CONFPATHCTL)->EnableWindow(state);
	//Change state of browse for telemetry data save folder path field
	GetDlgItem(IDC_SAVPATHCTL2)->EnableWindow(state);
	//Change state of create button within the "Create Configuration File"
	GetDlgItem(IDC_CREATECONF)->EnableWindow(state);
	//Change state of the GUI checkboxes
	GetDlgItem(IDC_CHK1)->EnableWindow(state);
	GetDlgItem(IDC_CHK2)->EnableWindow(state);
	GetDlgItem(IDC_CHK3)->EnableWindow(state);
	GetDlgItem(IDC_CHK4)->EnableWindow(state);
	GetDlgItem(IDC_CHK5)->EnableWindow(state);
}
//This method will call the appropriate methods to start the analysis
//analySet_ - True if requested to start the analysis mode : False if requested to end the analysis mode
void COculusDataExtractorGUImainDlg::isAnalysis(const bool analySet_) {
	//Analysis Start
	if (analySet_) {
		//Disable "Pause Simulation" button
		GetDlgItem(IDC_HEADSETINIT)->EnableWindow(false);
		//Change the "End Simulation" button
		GetDlgItem(IDC_BEGSIM)->SetWindowTextW(_T("End Analysis"));
		//Disable the above mentioned button
		GetDlgItem(IDC_BEGSIM)->EnableWindow(false);
		//Reset the "Pause Simulation" button to default 
		GetDlgItem(IDC_HEADSETINIT)->SetWindowTextW(_T("Pause Simulation"));
		//Disable the currently running thread
		bThreadRunning = false;
		//Send to output window that sim has ended and that analysis has started
		addToOutput(AfxGetMainWnd(), "Simulation has ended!", IDC_TXTOUTPUT, 1);
		addToOutput(AfxGetMainWnd(), "Analysis mode started!", IDC_TXTOUTPUT, 1);
		//Sleep to ensure that the extraction process has completely stopped
		Sleep(500);
		//Re-enable the changed Button to "End Analysis"
		GetDlgItem(IDC_BEGSIM)->EnableWindow(true);
	}
	//Once analysis mode has ended, the table will be cleared and all the buttons will be reset
	else {
		//Get the instance of the table within the GUI
		CListCtrl* list = (CListCtrl*)GetDlgItem(IDC_TDLIST);
		//Delete every item in the table
		while (list->DeleteItem(0));
		//Reset the row number
		rowNum = 0;
		//Reset window state to enabled
		changeAllWinState(true);
		//Reset "End Analysis" button to "Begin Simulation" 
		GetDlgItem(IDC_BEGSIM)->SetWindowTextW(_T("Begin Simulation"));
		//Send to output window analysis had ended and that the extraction is completed
		addToOutput(AfxGetMainWnd(), "Analysis has ended!", IDC_TXTOUTPUT, 1);
		//Added for GUI pause effect between messages
		Sleep(10);
		addToOutput(AfxGetMainWnd(), "Extraction Completed!", IDC_TXTOUTPUT, 1);
		//Ensure that the telemetry directory creater method - OnBnClickedBegsim - will know that the application
		//is in repeat mode
		repeatSim = true;
	}
}
//This method is responsible for setting the appropriate save folder path for the telemetry data
//*Note - repeatSim - True if simulation has been previously ran : False if otherwise
//If the simulation has been run, then the following process will exclude the code used to change
//the desired folder path
void COculusDataExtractorGUImainDlg::setTelemPath() {
	//Loop backwards until a slash representing the folder seperation is hit
	for (int i = (int)pathStorage[savPathTD].length() - 1; i > 0; i--) {
		//Once a slash has been hit
		if (pathStorage[savPathTD][i] == '\\') {
			//IFF repeatSim is false or tdFolderChanged is True continue...
			if (!repeatSim || tdFolderChanged) {
				//Reset folder changed
				tdFolderChanged = false;
				//Check to see if the folder path is a root directory
				if (pathStorage[savPathTD][i - 1] == ':') {
					pathStorage[savPathTD] += '\\';
					i++;
				}
				//Checks to see if i is at the end of the save path, if so set new path without slashes			
				if (i == pathStorage[savPathTD].length() - 1)
					pathStorage[savPathTD] += getCurrDate() + "-" + dataEx.getSerialNum();
				//Otherwise, push slashes prior to the save path
				else
					pathStorage[savPathTD] += '\\' + getCurrDate() + "-" + dataEx.getSerialNum();
			}
			//This process saves the pathStorage[savePathTD] folder path to folderPath variable,
			//which requires change from string to wchar_t object which is then used ot initialize folderPath
			//Get the length including the null bit
			int strlength = (int)pathStorage[savPathTD].length() + 1;
			//Sets the length in the appropriate format
			int length = MultiByteToWideChar(CP_ACP, 0, pathStorage[savPathTD].c_str(), strlength, 0, 0);
			//Initialize the temporary buffer
			wchar_t* tempBuf = new wchar_t[length];
			//Make the conversion of the tempBuf to the appropriate form
			MultiByteToWideChar(CP_ACP, 0, pathStorage[savPathTD].c_str(), strlength, tempBuf, length);
			//Initialize folderPath with tempBuf
			std::wstring folderPath(tempBuf);
			//Delete tempBuf
			delete[] tempBuf;
			//This native WINDOWS method is used to determine if a folder with the created path exists in directory
			//If it does not, it will create it : Otherwise, do nothing
			CreateDirectory(folderPath.c_str(), NULL);
			//Stops the loop
			i = -1;
		}
	}
}
//This method is responsible for Beginning the Simulation and changing the connected button accordignly.
void COculusDataExtractorGUImainDlg::OnBnClickedBegsim() {
	//Checks to ensure that config file and telem save path have been saved
	if (tdSavPath&&confFilePath) {
		//This variable is used to hold the text of the button
		CString buttonText_;
		//Get the text of the button
		GetDlgItem(IDC_BEGSIM)->GetWindowText(buttonText_);
		//If button text is "Begin Simulation" continue...
		if (buttonText_ == _T("Begin Simulation")) {
			//Change all window states
			changeAllWinState(false);
			//Enable the "Pause Simulation" button
			GetDlgItem(IDC_HEADSETINIT)->EnableWindow(true);
			//Change the current button text to "End Simulation"
			GetDlgItem(IDC_BEGSIM)->SetWindowTextW(_T("End Simulation"));
			//Call the method that sets the telemetry data folder path
			setTelemPath();
			//Call the DataExtractor method that gets the new telemetry data file ready for writing
			dataEx.openFileForWriting(pathStorage[savPathTD] + '\\');
			//Send to the output window that sim has started
			addToOutput(AfxGetMainWnd(),"Simulation has begun!",IDC_TXTOUTPUT,1);
			//Set the initial line number in the live table of the telemetry data
			lineCount = 0;
			//Set the initial row number in the live table of the telemetry data
			rowNum = 0;
			//Sets the global variable bThreadRunning to true, which allows the extraction loop to start
			bThreadRunning = true;
			//Start the main thread that deals with the extraction process of the telemetry data,
			//as well as the outputting to the live telemetry data table
			std::thread fileWriter(std::ref(dataEx),std::ref(bThreadRunning),std::ref(lineCount), 
				pathStorage[savPathTD] + '\\',std::ref(bPause),std::ref(rowNum));
			//Detaches the thread
			fileWriter.detach();
		}
		//If "End Simulation" button has been toggled, continue...
		else if (buttonText_ == _T("End Simulation")) 
			//Call associated method that starts and ends analysis
			isAnalysis(true);
		//If "End Analysis" button has been toggled, continue...
		else if (buttonText_ == _T("End Analysis")) 
			//Call associated method that starts and ends analysis
			isAnalysis(false);			
	}
	else
		//If the config file has not been loaded and the telemetry data folder path has not been selected, output error to output window 
		addToOutput(AfxGetMainWnd(),"Error: Please load the configuration file and set the save path for the telemetry data!", IDC_TXTOUTPUT, 2);
}
//This method is responsible for reading the configuration file and setting which telemetry data is going to be extracted
void COculusDataExtractorGUImainDlg::readConfigFile() {
	//Load the file into stream and start at the beginning
	std::ifstream confFile(pathStorage[configPath], std::ios::in);
	confFile.seekg(0, confFile.beg);
	//Read the file
	while (!confFile.eof()) {
		int tmp = 0;
		confFile >> tmp;
		if (tmp == 0)
			break;
		confFile.ignore();
		int type;
		//Check type with the DataExtractor determineTelType method
		type = dataEx.determineTelType(tmp);
		//Insert new columns into the live table based on the returned type
		switch (type) {
			//Angular Acceleration
		case AA:
			angAcc_.SetCheck(BST_CHECKED);
			telemList.InsertColumn(1, _T("Angular Acceleration"), LVCFMT_CENTER, 160);
			break;
			//Angular Velocity
		case AV:
			angVel_.SetCheck(BST_CHECKED);
			telemList.InsertColumn(2, _T("Angular Velocity"), LVCFMT_CENTER, 160);
			break;
			//Linear Acceleration
		case LA:
			linAcc_.SetCheck(BST_CHECKED);
			telemList.InsertColumn(3, _T("Linear Acceleration"), LVCFMT_CENTER, 160);
			break;
			//Linear Velocity
		case LV:
			linVel_.SetCheck(BST_CHECKED);
			telemList.InsertColumn(4, _T("Linear Velocity"), LVCFMT_CENTER, 160);
			break;
			//Orientation
		case OR:
			ori_.SetCheck(BST_CHECKED);
			telemList.InsertColumn(5, _T("YAW"), LVCFMT_CENTER, 80);
			telemList.InsertColumn(6, _T("PITCH"), LVCFMT_CENTER, 80);
			telemList.InsertColumn(7, _T("ROLL"), LVCFMT_CENTER, 80);
			break;
		default:
			break;
		}
	}
	//Send to output window that the configuration file has been loaded
	addToOutput(AfxGetMainWnd(), "Configuration File - " + pathStorage[configFile] + " - Loaded!", IDC_TXTOUTPUT, 1);
	//Set that a config file path has been loaded - True
	confFilePath = true;
	//Close the file
	confFile.close();
}
//This method is responsible for selecting the configuration file and passing off the needed properties from the file to the DataExtractor dataEx
void COculusDataExtractorGUImainDlg::OnEnChangeConfpathctl() {
	//Temporary variable used to get the selected file from the GUI
	CString temp;
	//Gets the selected file, if any
	fileEdit_.GetWindowTextW(temp);
	//If the file has been found in the directory, continue...
	if (findFile_.FindFile(temp)) {
		//Convert CString to std::String
		CT2CA convTemp(temp);
		//Set config path
		pathStorage[configPath] = std::string(convTemp);
		//Set file name
		char str_;
		//Get the file name of the configuration file and pass it to pathStorage[configFile]
		for (int counter = (int)(pathStorage[configPath].length() - 1); counter > 0; counter--) {
			str_ = pathStorage[configPath].at(counter);
			if (str_ == '\\') {
				pathStorage[configFile] = pathStorage[configPath].substr(counter + 1, pathStorage[configPath].length() - 1);
				counter = -1;
			}
		}
		//Clear any uneccessary data from dataEx
		dataEx.clearData();
		//Uncheck all checkboxes and delete any current columns within the live table, besides time
		angAcc_.SetCheck(BST_UNCHECKED);
		angVel_.SetCheck(BST_UNCHECKED);
		linAcc_.SetCheck(BST_UNCHECKED);
		linVel_.SetCheck(BST_UNCHECKED);
		ori_.SetCheck(BST_UNCHECKED);
		while (telemList.DeleteColumn(1));
		try {
			//Call method to read the configuration file
			readConfigFile();
		}
		//If there is an error, send it to the output window
		catch (std::string msg) {
			addToOutput(AfxGetMainWnd(),"Error: " + msg, IDC_TXTOUTPUT, 2);
		}
	}
	else
		//Send to the output window an error
		addToOutput(AfxGetMainWnd(),"Error: File Path Does NOT Exist!", IDC_TXTOUTPUT, 2);
}
//This method is responsible for changing the save folder path of the telemetry data
//This method will only be called once the OK button has been pressed on the folder browser button
//and if a new folder has been selected
void COculusDataExtractorGUImainDlg::OnEnChangeSavpathctl2() {
	//If this is a repition of a simulation then change the observer boolean to true in order to ensure folder creation works
	if (repeatSim)
		tdFolderChanged = true;
	CString temp;
	folderEdit_.GetWindowText(temp);
	CT2CA convTemp(temp);
	//Set config path
	pathStorage[savPathTD] = std::string(convTemp);
	//Set that a folder path has been selected
	tdSavPath = true;
	//Send to output window that the above has occured
	addToOutput(AfxGetMainWnd(),"Telemetry Data Save Path Set!", IDC_TXTOUTPUT, 1);
}
//This method is responsible for creating a new configuration file from the GUI checkboxes
void COculusDataExtractorGUImainDlg::OnBnClickedCreateconf() {
	bool chkCheck = false;
	//Variable that will be used to create a configuration file
	std::string conStr="";
	//Delete any current columns, besides time, from the live table
	while (telemList.DeleteColumn(1));
	//If Angular Acceleration is checked continue...
	if (angAcc_.GetCheck() == BST_CHECKED) {
		//Pushes the configuration setting to the variable 
		conStr += "1,";
		//Generates column based on user input
		telemList.InsertColumn(1, _T("Angular Acceleration"), LVCFMT_CENTER, 160);
		//Sets that a user has checked a checkbox
		chkCheck = true;
	}
	//If Angular Velocity is checked continue...
	if (angVel_.GetCheck() == BST_CHECKED) {
		//Pushes the configuration setting to the variable 
		conStr += "2,";
		//Generates column based on user input
		telemList.InsertColumn(2, _T("Angular Velocity"), LVCFMT_CENTER, 160);
		//Sets that a user has checked a checkbox
		chkCheck = true;
	}
	//If Linear Acceleration is checked continue...
	if (linAcc_.GetCheck() == BST_CHECKED) {
		//Pushes the configuration setting to the variable 
		conStr += "3,";
		//Generates column based on user input
		telemList.InsertColumn(3, _T("Linear Acceleration"), LVCFMT_CENTER, 160);
		//Sets that a user has checked a checkbox
		chkCheck = true;
	}
	//If Linear Velocity is checked continue...
	if (linVel_.GetCheck() == BST_CHECKED) {
		//Pushes the configuration setting to the variable 
		conStr += "4,";
		//Generates column based on user input
		telemList.InsertColumn(4, _T("Linear Velocity"), LVCFMT_CENTER, 160);
		//Sets that a user has checked a checkbox
		chkCheck = true;
	}
	//If Linear Orientation is checked continue...
	if (ori_.GetCheck() == BST_CHECKED) {
		//Pushes the configuration setting to the variable 
		conStr += "5,";
		//Generates column based on user input
		telemList.InsertColumn(5, _T("YAW"), LVCFMT_CENTER, 80);
		telemList.InsertColumn(6, _T("PITCH"), LVCFMT_CENTER, 80);
		telemList.InsertColumn(7, _T("ROLL"), LVCFMT_CENTER, 80);
		//Sets that a user has checked a checkbox
		chkCheck = true;
	}
	//If a user has checked a checkbox, continue...
	if (chkCheck) {
		//Create a configuration file with the desired GUI inputted name
		conStr = conStr.substr(0, conStr.length() - 1);
		CFileDialog saveConfFile(FALSE, _T("csv"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT, _T("CSV Files|*.csv||"));
		INT_PTR idCk=saveConfFile.DoModal();
		//Once the OK button has been pressed, continue...
		if (idCk == IDOK) {
			//Create configuration file
			CT2CA convTemp(saveConfFile.GetPathName());
			//Send to output window that new config file has been created
			addToOutput(AfxGetMainWnd(),"Configuration File Created!", IDC_TXTOUTPUT, 1);
			//Set new path of configuration file
			pathStorage[configPath] = convTemp;
			//Open configuration file for editing
			std::ofstream configFile(pathStorage[configPath], std::ofstream::out | std::ofstream::trunc);
			//Pass in the user desired telemetry data 
			configFile << conStr;
			//Close file
			configFile.close();
			//Clear any previous data in dataEx
			dataEx.clearData();
			//Change the filepath in the GUI to illustrate the new config file
			fileEdit_.SetWindowTextW(saveConfFile.GetPathName());
		}
		//Otherwise Error message
		else
			addToOutput(AfxGetMainWnd(),"Error: Save Window Closed!", IDC_TXTOUTPUT, 2);
	}
	else
		//Send to output window that user needs to check at least one of the checkboxes
		addToOutput(AfxGetMainWnd(),"Error: Please select the desired telemetry data for the configuration file!", IDC_TXTOUTPUT, 2);
}
//This method is responsible for opening the about dialog window through the menu
void COculusDataExtractorGUImainDlg::OnMabout(){
	CWnd* AboutWin;
	CAboutDlg AboutDlg;
	AboutWin = &AboutDlg;
	AboutDlg.DoModal();
}

//This method is responsible for closing the entire application through the menu
void COculusDataExtractorGUImainDlg::OnMclose(){
	//Disable the currently running thread
	bThreadRunning = false;
	Sleep(300);
	CDialogEx::OnCancel();
}
//THis method is responsible for opening the quick guide dialog window through the menu
void COculusDataExtractorGUImainDlg::OnHelpQuickguide(){
	CWnd* QGwin;
	CQuickGuide qgDlg;
	QGwin = &qgDlg;
	qgDlg.DoModal();	
}

//This method calls the clear button through the menu which clears the live telemetry data in the table
void COculusDataExtractorGUImainDlg::OnEditClear(){
	//If the simulation is not running, send an error message to the output window
	CString temp;
	GetDlgItem(IDC_HEADSETINIT)->GetWindowText(temp);
	if(temp == _T("Initialize Headset"))
		addToOutput(AfxGetMainWnd(), "Error: Start the simulation first!", IDC_TXTOUTPUT, 2);
	//If the simulation is running, continue...
	else {
		//Check to see if the simulation has been paused, continue...
		if (bPause) {
			//Let the program sleep so the thread can catch up then delete all items in the live table
			Sleep(200);
			while (telemList.DeleteItem(0));
			//Reset the row number to 0
			rowNum = 0;
			//Sleep once more
			Sleep(200);
		}
		//If simulation has not been paused, send an error message to the output window
		else 
			addToOutput(AfxGetMainWnd(), "Error: Pause the simulation first!", IDC_TXTOUTPUT, 2);
	}
}
//This method is responsible for the OK button in the About dialog window
void CAboutDlg::OnBnClickedOk(){
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
