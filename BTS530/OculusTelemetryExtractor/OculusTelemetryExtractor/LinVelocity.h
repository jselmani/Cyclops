#ifndef _LIN_VELOCITY_H_
#define _LIN_VELOCITY_H_

#include "Telemetry.h"

namespace extractor {

	class LinVelocity : public Telemetry {
	private:
		Vector3f lvData;
	public:
		LinVelocity();
		LinVelocity(const std::string&);
		void setData(ovrSession&, ovrTrackingState&);
		void writeToFile(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const LinVelocity&);
}

#endif
