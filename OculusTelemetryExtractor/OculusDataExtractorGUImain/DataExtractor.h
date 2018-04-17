#ifndef _DATAEXTRACTOR_H_
#define _DATAEXTRACTOR_H_

#include "stdafx.h"
#include "OutputDialog.h"

/*
	TODO:
	- delete memory in DataExtractor::vector data by writing function
	- delete file memory
	- finish writing destructor
	- add date to file name
	- DEBUG/TEST WITH OCULUS
*/

static std::mutex guard;

class DataExtractor {
private:
	ovrSession hmd;
	ovrGraphicsLuid luid;
	ovrTrackingState trackState;
	ovrBool HmdPresent;
	//Main dialog of the application
	CWnd* mainDlg;
	std::ofstream* file;
	std::vector<std::unique_ptr<Telemetry>> data;
	std::string serialNum;
	int counter; // used to change file name
public:
	DataExtractor();
	~DataExtractor();
	std::string getSerialNum();
	std::ofstream& getFileObject();
	ovrBool headsetPresent();
	bool initHeadset();
	int determineTelType(int);
	void closeFile();
	void clearData();
	//Set the row number in the live table
	void setRow(CListCtrl&, LVITEMW&, int);
	void openFileForWriting(const std::string&);
	//Set mainDlg to the incoming dialog
	void setDlg(CWnd*);
	void operator()(bool&, int&, const std::string,bool&,int&);
};

#endif