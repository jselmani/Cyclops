#include "stdafx.h"
#include "LinAccel.h"



LinAccel::LinAccel() {
	laData.x = 0;
	laData.y = 0;
	laData.z = 0;
	getType().clear();
}

LinAccel::LinAccel(const std::string& str) : Telemetry(str) {}

LinAccel::~LinAccel() {}

void LinAccel::setData(ovrSession& hmd, ovrTrackingState& trackState, CWnd* mainDlg_) {
	mainDlg = mainDlg_;
	trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
	if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
		laData = trackState.HeadPose.LinearAcceleration;
}

void LinAccel::writeToFile(std::ostream& output, CWnd* mainDlg, LVITEMW rowItem) const {
	std::stringstream stream;
	//Output to file
	output << laData.x << "," << laData.y << "," << laData.z << ",";
	//Output to live table
	stream << laData.x << " , " << laData.y << " , " << laData.z;
	//Add stream to column in live table
	addToColumn(mainDlg, stream.str(), _T("Linear Acceleration"), rowItem);
}
