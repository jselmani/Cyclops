#include "AngAccel.h"

namespace extractor {

	AngAccel::AngAccel() {
		aaData.x = 0;
		aaData.y = 0;
		aaData.z = 0;
		getType().clear();
	}

	AngAccel::AngAccel(const std::string& str) : Telemetry(str) {}

	void AngAccel::setData(ovrSession& hmd, ovrTrackingState& trackState) {
		trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
		if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
			aaData = trackState.HeadPose.AngularAcceleration;
	}

	// TODO: Write Date & Time stamp for each piece of telemetry
	// being pulled from HMD
	void AngAccel::writeToFile(std::ostream& output) const {
		output << aaData.x << "," << aaData.y << "," 
			<< aaData.z << ",";
	}

	/*std::ostream& operator<<(std::ostream& output, const AngAccel& data) {
		data.writeToFile(output);
		return output;
	}*/
}