#ifndef _LIN_ACCEL_H_
#define _LIN_ACCEL_H_

#include "Telemetry.h"

namespace extractor {

	class LinAccel : public Telemetry {
		private:
			Vector3f laData;
		public:
			LinAccel();
			LinAccel(const std::string&);
			void setData(ovrSession&, ovrTrackingState&);
			void writeToFile(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const LinAccel&);
}

#endif
