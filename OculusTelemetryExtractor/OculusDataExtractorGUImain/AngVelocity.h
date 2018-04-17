#ifndef _ANG_VELOCITY_H_
#define _ANG_VELOCITY_H_

#include "Telemetry.h"
#include "OutputDialog.h"

class AngVelocity : public Telemetry {
private:
	Vector3f avData;
	//Main dialog of the application
	CWnd* mainDlg;
public:
	AngVelocity();
	AngVelocity(const std::string& str);
	~AngVelocity();
	//CWnd - used to set the mainDlg
	void setData(ovrSession&, ovrTrackingState&, CWnd*);
	//CWnd - instance of the live table for manipulation
	//LVITEMW - the current row item that is being inserted to
	void writeToFile(std::ostream&,CWnd*, LVITEMW) const;
};

#endif
