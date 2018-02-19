#ifndef _TELEMETRY_H_
#define _TELEMETRY_H_	

#include <iostream>
#include "Timestamp.h"
#include "../../OculusSDK/LibOVR/Include/OVR_CAPI.h"
#include "../../OculusSDK/LibOVR/Include/Extras/OVR_Math.h"

using namespace OVR;

namespace extractor {

	class Telemetry {
		private:
			std::string type;
		public:
			Telemetry();
			Telemetry(const std::string&);
			virtual ~Telemetry();
			virtual void setData(ovrSession&, ovrTrackingState&) = 0;
			virtual void writeToFile(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const Telemetry*);
}

#endif
