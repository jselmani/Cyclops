#include "stdafx.h"
#include "AngAccel.h"

AngAccel::AngAccel() {
	aaData.x = 0;
	aaData.y = 0;
	aaData.z = 0;
	getType().clear();
}

AngAccel::AngAccel(const std::string& str) : Telemetry(str) {}

AngAccel::~AngAccel() {}

void AngAccel::setData(ovrSession& hmd, ovrTrackingState& trackState, CWnd* mainDlg_) {
	mainDlg = mainDlg_;
	trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
	if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
		aaData = trackState.HeadPose.AngularAcceleration;
}

void AngAccel::writeToFile(std::ostream& output,CWnd* mainDlg, LVITEMW rowItem) const {
	std::stringstream stream;
	//Output to file
	output << aaData.x << "," << aaData.y << "," << aaData.z << ",";
	//Output to live table
	stream << aaData.x << " , " << aaData.y << " , " << aaData.z;
	addToColumn(mainDlg, stream.str(),_T("Angular Acceleration"),rowItem);
}
