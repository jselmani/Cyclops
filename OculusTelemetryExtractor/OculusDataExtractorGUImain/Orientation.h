#ifndef _ORIENTATION_H_
#define _ORIENTATION_H_

#include "Telemetry.h"
#include "OutputDialog.h"

class Orientation : public Telemetry {
private:
	ovrPosef pose;
	Quatf quaternion;
	float yaw;
	float pitch;
	float roll;
	//Main dialog of the application
	CWnd* mainDlg;
public:
	Orientation();
	Orientation(const std::string&);
	~Orientation();
	void initOrientationValues(ovrPosef&);
	void initPositionValues(ovrPosef&);
	//CWnd - used to set the mainDlg
	void setData(ovrSession&, ovrTrackingState&, CWnd*);
	//CWnd - instance of the live table for manipulation
	//LVITEMW - the current row item that is being inserted to
	void writeToFile(std::ostream&, CWnd*, LVITEMW) const;
};

#endif
