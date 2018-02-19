#ifndef _ANG_VELOCITY_H_
#define _ANG_VELOCITY_H_

#include "Telemetry.h"

namespace extractor {

	class AngVelocity : public Telemetry {
		private:
			Vector3f avData;
		public:
			AngVelocity();
			AngVelocity(const std::string& str);
			~AngVelocity();
			void setData(ovrSession&, ovrTrackingState&);
			void writeToFile(std::ostream&) const;
	};
}

#endif
