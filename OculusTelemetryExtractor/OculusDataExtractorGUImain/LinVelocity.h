#ifndef _LIN_VELOCITY_H_
#define _LIN_VELOCITY_H_

#include "Telemetry.h"
#include "OutputDialog.h"


class LinVelocity : public Telemetry {
private:
	Vector3f lvData;
	//Main dialog of the application
	CWnd* mainDlg;
public:
	LinVelocity();
	LinVelocity(const std::string&);
	~LinVelocity();
	//CWnd - used to set the mainDlg
	void setData(ovrSession&, ovrTrackingState&, CWnd*);
	//CWnd - instance of the live table for manipulation
	//LVITEMW - the current row item that is being inserted to
	void writeToFile(std::ostream&, CWnd*, LVITEMW) const;
};

#endif
