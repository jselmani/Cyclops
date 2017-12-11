#include "Orientation.h"

namespace extractor {

	Orientation::Orientation() {
		initOrientationValues(pose);
		initPositionValues(pose);
		yaw = 0;
		pitch = 0;
		roll = 0;
	}

	Orientation::Orientation(const std::string& str) : Telemetry(str) {}

	void Orientation::initOrientationValues(ovrPosef& p) {
		p.Orientation.w = 0;
		p.Orientation.x = 0;
		p.Orientation.y = 0;
		p.Orientation.z = 0;
	}

	void Orientation::initPositionValues(ovrPosef& p) {
		p.Position.x = 0;
		p.Position.y = 0;
		p.Position.z = 0;
	}

	void Orientation::setData(ovrSession& hmd, ovrTrackingState& trackState) {
		trackState = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
		if (trackState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
			pose = trackState.HeadPose.ThePose;
			quaternion = pose.Orientation;
			quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);
		}
	}

	void Orientation::writeToFile(std::ostream& output) const {
		output << RadToDegree(yaw) << "," << RadToDegree(pitch) << "," << RadToDegree(roll);
	}

	std::ostream& operator<<(std::ostream& output, const Orientation& data) {
		data.writeToFile(output);
		return output;
	}
}