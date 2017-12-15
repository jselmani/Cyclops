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
			Orientation(const std::string&);
			void initOrientationValues(ovrPosef&);
			void initPositionValues(ovrPosef&);
			void setData(ovrSession&, ovrTrackingState&);
			void writeToFile(std::ostream&) const;
	};
}

#endif
