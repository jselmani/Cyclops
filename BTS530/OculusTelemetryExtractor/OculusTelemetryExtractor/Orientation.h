#ifndef _ORIENTATION_H_
#define _ORIENTATION_H_

#include "Telemetry.h"

namespace extractor {

	class Orientation : public Telemetry {
	private:
		ovrPosef pose;
		Quatf quaternion;
		float yaw;
		float pitch;
		float roll;
	public:
		Orientation();
		void printToFile(std::ofstream&);
	};
}

#endif
