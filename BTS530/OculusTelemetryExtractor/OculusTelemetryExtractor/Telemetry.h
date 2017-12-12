#ifndef _TELEMETRY_H_
#define _TELEMETRY_H_	

#include <iostream>
#include <vector>
#include "../../OculusSDK/LibOVR/Include/OVR_CAPI.h"
#include "../../OculusSDK/LibOVR/Include/Extras/OVR_Math.h"

using namespace OVR;

namespace extractor {

	enum telType { AA = 1, AV, LA, LV, OR };

	class Telemetry {
		private:
			std::string type;
		protected:
			Telemetry();
			Telemetry(const std::string&);
		public:
			virtual void setData(ovrSession&, ovrTrackingState&) = 0;
			virtual void writeToFile(std::ostream&) const = 0;
			std::string getType() const;
	};
}

#endif
