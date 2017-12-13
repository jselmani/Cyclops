#include "LinAccel.h"

namespace extractor {

	LinAccel::LinAccel() {
		laData.x = 0;
		laData.y = 0;
		laData.z = 0;
		getType().clear();
	}

	LinAccel::LinAccel(const std::string& str) : Telemetry(str) {}

	void LinAccel::setData(ovrSession& hmd, ovrTrackingState& trackState) {
		trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
		if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
			laData = trackState.HeadPose.LinearAcceleration;
	}

	// TODO: Write Date & Time stamp for each piece of telemetry
	// being pulled from HMD
	void LinAccel::writeToFile(std::ostream& output) const {
		output << laData.x << "," << laData.y << "," 
			<< laData.z << "," << getCurrTime() << ",";
	}

	std::ostream& operator<<(std::ostream& output, LinAccel& data) {
		data.writeToFile(output);
		return output;
	}
}