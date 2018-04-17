#ifndef _TELEMETRY_H_
#define _TELEMETRY_H_	

#include "stdafx.h"
#include "Timestamp.h"


using namespace OVR;

class Telemetry {
private:
	std::string type;
protected:
	Telemetry();
	Telemetry(const std::string&);
public:
	virtual ~Telemetry();
	//CWnd - used to set the mainDlg
	virtual void setData(ovrSession&, ovrTrackingState&, CWnd*) = 0;
	//CWnd - instance of the live table for manipulation
	//LVITEMW - the current row item that is being inserted to
	virtual void writeToFile(std::ostream&, CWnd*, LVITEMW) const = 0;
	std::string getType() const;
};
#endif
