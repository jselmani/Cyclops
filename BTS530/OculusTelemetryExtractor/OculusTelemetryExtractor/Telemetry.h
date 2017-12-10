#ifndef _TELEMETRY_H_
#define _TELEMETRY_H_	

#include <iostream>
#include <vector>
#include "../../OculusSDK/LibOVR/Include/OVR_CAPI.h"
#include "../../OculusSDK/LibOVR/Include/Extras/OVR_Math.h"
#include "AngAccel.h"
#include "AngVelocity.h"
#include "LinAccel.h"
#include "LinVelocity.h"
#include "Orientation.h"

using namespace OVR;

namespace extractor {

	enum telType { AA = 1, AV, LA, LV, OR };

	class Telemetry {
	private:
		std::string type; //declare type of class name that derives it
		telType dataType;
	protected:
		Telemetry();
		Telemetry(const std::string&);
	public:
		virtual void printToFile(std::ofstream&) const = 0;
		std::string getType() const;
	};
}

#endif
