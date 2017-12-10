#ifndef _ANG_ACCEL_H_
#define _ANG_ACCEL_H_

#include "Telemetry.h"

namespace extractor {

	class AngAccel : public Telemetry {
	private:
		Vector3f aaData;
	public:
		AngAccel();
		std::ofstream& operator<<(std::ofstream&) const;
	};
}

#endif
