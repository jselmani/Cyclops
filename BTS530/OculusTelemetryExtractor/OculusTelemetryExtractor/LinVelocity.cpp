#include "LinVelocity.h"

namespace extractor {
	
	LinVelocity::LinVelocity() {
		lvData.x = 0;
		lvData.y = 0;
		lvData.z = 0;
		getType().clear();
	}

	LinVelocity::LinVelocity(const std::string& str) : Telemetry(str) {}

	void LinVelocity::setData(ovrSession& hmd, ovrTrackingState& trackState) {
		trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
		if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
			lvData = trackState.HeadPose.LinearVelocity;
	}

	// TODO: Write Date & Time stamp for each piece of telemetry
	// being pulled from HMD
	void LinVelocity::writeToFile(std::ostream& output) const {
		output << lvData.x << "," << lvData.y << "," << lvData.z << ",";
	}

	std::ostream& operator<<(std::ostream& output, const LinVelocity& data) {
		data.writeToFile(output);
		return output;
	}
}