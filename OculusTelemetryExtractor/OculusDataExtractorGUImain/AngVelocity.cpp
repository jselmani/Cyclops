#include "stdafx.h"
#include "AngVelocity.h"

AngVelocity::AngVelocity() {
	avData.x = 0;
	avData.y = 0;
	avData.z = 0;
	getType().clear();
}

AngVelocity::AngVelocity(const std::string& str) : Telemetry(str) {}

AngVelocity::~AngVelocity() {}

void AngVelocity::writeToFile(std::ostream& output, CWnd* mainDlg, LVITEMW rowItem) const {
	std::stringstream stream;
	//Output to file
	output << avData.x << "," << avData.y << "," << avData.z << ",";
	//Output to live table
	stream << avData.x << " , " << avData.y << " , " << avData.z;
	//Add stream to column in live table
	addToColumn(mainDlg, stream.str(), _T("Angular Velocity"), rowItem);
}

void AngVelocity::setData(ovrSession& hmd, ovrTrackingState& trackState, CWnd* mainDlg_) {
	mainDlg = mainDlg_;
	trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
	if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
		avData = trackState.HeadPose.AngularVelocity;
}
