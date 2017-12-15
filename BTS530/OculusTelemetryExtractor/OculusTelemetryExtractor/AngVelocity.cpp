#include "AngVelocity.h"

namespace extractor {

	AngVelocity::AngVelocity() {
		avData.x = 0;
		avData.y = 0;
		avData.z = 0;
		getType().clear();
	}

	AngVelocity::AngVelocity(const std::string& str) : Telemetry(str) {}

	// TODO: Write Date & Time stamp for each piece of telemetry
	// being pulled from HMD
	void AngVelocity::writeToFile(std::ostream& output) const {
		output << avData.x << "," << avData.y << "," 
			<< avData.z << ",";
	}

	void AngVelocity::setData(ovrSession& hmd, ovrTrackingState& trackState) {
		trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
		if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
			avData = trackState.HeadPose.AngularVelocity;
	}
}
