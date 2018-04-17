#include "stdafx.h"
#include "DataExtractor.h"

// initialize hmd and other member variables
DataExtractor::DataExtractor() {
	serialNum.clear();
	counter = 0;
	HmdPresent = false;
	file = nullptr;
}

void DataExtractor::clearData() {
	data.clear();
}

// Destructor
DataExtractor::~DataExtractor() {
	ovr_Destroy(hmd);
	ovr_Shutdown();
	data.clear();
}

// returns serial number of headset to be used as filename
// can only be called after initialization of hmd
std::string DataExtractor::getSerialNum() {
	ovrHmdDesc desc = ovr_GetHmdDesc(hmd);
	return desc.SerialNumber;
}

// open file with dynamic name
void DataExtractor::openFileForWriting(const std::string& path) {
	std::string result = path;
	result += getCurrTime() + ".csv";
	file = new std::ofstream(result.c_str());
}

// determine telemetry type to push into vector
// vector will be iterated through to print data to file
// Return - the telemetry data type
int DataExtractor::determineTelType(int telType) {
	int ret = telType;
	switch (telType) {
	case 1:
		data.push_back(std::unique_ptr<Telemetry>(new AngAccel("Angular Acceleration")));
		break;
	case 2:
		data.push_back(std::unique_ptr<Telemetry>(new AngVelocity("Angular Velocity")));
		break;
	case 3:
		data.push_back(std::unique_ptr<Telemetry>(new LinAccel("Linear Acceleration")));
		break;
	case 4:
		data.push_back(std::unique_ptr<Telemetry>(new LinVelocity("Linear Velocity")));
		break;
	case 5:
		data.push_back(std::unique_ptr<Telemetry>(new Orientation("Orientation")));
		break;
	default:
		throw new std::string("The configuration file has been corrupted.");
		ret = -1;
		break;
	}
	return ret;
}
//Return - if the headset has been initialized
bool DataExtractor::initHeadset() {
	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
		return false;

	result = ovr_Create(&hmd, &luid);
	if (OVR_FAILURE(result)) {
		ovr_Shutdown();
		return false;
	}
	HmdPresent = true;
	return true;
}
// Set the current row of the live table
// list - the live table control
// row - the current row object of the live table
// rowNum - the current row number of the live table
void DataExtractor::setRow(CListCtrl& list, LVITEMW& row, int rowNum) {
	std::string tempOutput;
	row.iItem = rowNum;
	row.iSubItem = 0;
	row.mask = LVIF_TEXT;
	getTime(tempOutput);
	wchar_t tempString[20];
	mbstowcs(tempString, tempOutput.c_str(), tempOutput.length() + 1);
	row.pszText = tempString;
	list.InsertItem(&row);
}
// bContThread - Boolean used to initialize the while loop
// lineCount - used to set the line count in the file
// path - stores the telemetry data file path
// setPause - will pause or unpause the simulation
// rowNum - the current row number in the live table
void DataExtractor::operator()(bool &bContThread, int &lineCount,const std::string path,bool &setPause,int &rowNum) {
	guard.lock();
	//Calling live table
	CListCtrl* tempList = (CListCtrl*)mainDlg->GetDlgItem(IDC_TDLIST);
	LVITEMW rowItem;
	bool bRun = bContThread;
	
	*file << "Time";
	for (auto i = data.begin(); i != data.end(); i++) {
		*file << "," << "-," << (*i)->getType();
		if (i == data.end() - 1)
			*file << std::endl;
		else
			*file << "-,";
	}
	

	while (bRun) {
		setRow(*tempList, rowItem, rowNum);
		*file << getCurrTime() <<",";
		for (auto it = data.begin(); it != data.end(); it++) {
			(*it)->setData(hmd, trackState, mainDlg);
			(*it)->writeToFile(*file, mainDlg, rowItem);
		}
		*file << std::endl;
		lineCount++;
		if (lineCount == 10000) {
			closeFile();
			openFileForWriting(path);
			lineCount = 0;
		}
		tempList->EnsureVisible(rowNum, true);
		rowNum++;
		CEdit* tempEdit = (CEdit*)mainDlg->GetDlgItem(IDC_TDLIST);
		tempEdit->LineScroll(tempEdit->GetLineCount());
		Sleep(50);
		while (setPause) {
			Sleep(1);
		}
		if (!bContThread) {
			bRun = false;
			closeFile();
		}
	}
	guard.unlock();
}

void DataExtractor::closeFile() {
	if (file->is_open()) {
		file->clear();
		file->close();
		delete file;
		file = nullptr;
	}
}

std::ofstream& DataExtractor::getFileObject() {
	return *file;
}

ovrBool DataExtractor::headsetPresent() {
	return HmdPresent;
}

void DataExtractor::setDlg(CWnd* mainDlg_) {
	mainDlg = mainDlg_;
}

