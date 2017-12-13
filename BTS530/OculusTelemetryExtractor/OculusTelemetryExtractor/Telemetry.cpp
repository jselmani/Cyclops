#include "Telemetry.h"

namespace extractor {

	Telemetry::Telemetry() {
		type.clear();
	}

	Telemetry::Telemetry(const std::string& str) {
		if (!str.empty())
			type = str;
		else
			throw std::string("The Telemetry type name has been corrupted in the file");
	}

	std::string Telemetry::getType() const {
		return type; // to be used by derived classes
	}
}
