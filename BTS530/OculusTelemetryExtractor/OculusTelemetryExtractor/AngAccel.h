#ifndef _ANG_ACCEL_H_
#define _ANG_ACCEL_H_

#include "Telemetry.h"

namespace extractor {

	class AngAccel : public Telemetry {
		private:
			Vector3f aaData;
		public:
			AngAccel();
			AngAccel(const std::string&);
			~AngAccel();
			void setData(ovrSession&, ovrTrackingState&);
			void writeToFile(std::ostream&) const;
	};
}

#endif
