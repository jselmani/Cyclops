#ifndef _LIN_VELOCITY_H_
#define _LIN_VELOCITY_H_

#include "Telemetry.h"

namespace extractor {

	class LinVelocity : public Telemetry {
	private:
		Vector3f lvData;
	public:
		LinVelocity();
		void printToFile(std::ofstream&);
	};
}

#endif
