#include "stdafx.h"
#include "LinVelocity.h"



LinVelocity::LinVelocity() {
	lvData.x = 0;
	lvData.y = 0;
	lvData.z = 0;
	getType().clear();
}

LinVelocity::LinVelocity(const std::string& str) : Telemetry(str) {}

LinVelocity::~LinVelocity() {}

void LinVelocity::setData(ovrSession& hmd, ovrTrackingState& trackState, CWnd* mainDlg_) {
	mainDlg = mainDlg_;
	trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
	if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
		lvData = trackState.HeadPose.LinearVelocity;
}

void LinVelocity::writeToFile(std::ostream& output, CWnd* mainDlg, LVITEMW rowItem) const {
	std::stringstream stream;
	//Output to file
	output << lvData.x << "," << lvData.y << "," << lvData.z << ",";
	//Output to live table
	stream << lvData.x << " , " << lvData.y << " , " << lvData.z;
	//Add stream to column in live table
	addToColumn(mainDlg, stream.str(), _T("Linear Velocity"), rowItem);
}
