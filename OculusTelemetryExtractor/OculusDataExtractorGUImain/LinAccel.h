#ifndef _LIN_ACCEL_H_
#define _LIN_ACCEL_H_

#include "Telemetry.h"
#include "OutputDialog.h"

class LinAccel : public Telemetry {
private:
	Vector3f laData;
	//Main dialog of the application
	CWnd* mainDlg;
public:
	LinAccel();
	LinAccel(const std::string&);
	~LinAccel();
	//CWnd - used to set the mainDlg
	void setData(ovrSession&, ovrTrackingState&, CWnd*);
	//CWnd - instance of the live table for manipulation
	//LVITEMW - the current row item that is being inserted to
	void writeToFile(std::ostream&, CWnd*, LVITEMW) const;
};

#endif
