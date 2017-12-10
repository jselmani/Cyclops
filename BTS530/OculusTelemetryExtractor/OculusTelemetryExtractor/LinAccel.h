#ifndef _LIN_ACCEL_H_
#define _LIN_ACCEL_H_

#include "Telemetry.h"

namespace extractor {

	class LinAccel : public Telemetry {
	private:
		Vector3f laData;
	public:
		LinAccel();
		void printToFile(std::ofstream&);
	};
}

#endif
