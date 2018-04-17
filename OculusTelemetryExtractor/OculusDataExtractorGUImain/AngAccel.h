#ifndef _ANG_ACCEL_H_
#define _ANG_ACCEL_H_

#include "Telemetry.h"
#include "OutputDialog.h"

class AngAccel : public Telemetry {
private:
	Vector3f aaData;
	//Main dialog of the application
	CWnd* mainDlg;
public:
	AngAccel();
	AngAccel(const std::string&);
	~AngAccel();
	//CWnd - used to set the mainDlg
	void setData(ovrSession&, ovrTrackingState&, CWnd*);
	//CWnd - instance of the live table for manipulation
	//LVITEMW - the current row item that is being inserted to
	void writeToFile(std::ostream&, CWnd*, LVITEMW) const;
};

#endif
