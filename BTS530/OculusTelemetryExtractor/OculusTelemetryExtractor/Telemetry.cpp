#include "Telemetry.h"

namespace extractor {

	Telemetry::Telemetry() {
		type.clear();
	}

	Telemetry::~Telemetry() {}

	Telemetry::Telemetry(const std::string& str) {
		if (!str.empty())
			type = str;
		else
			throw std::string("The Telemetry type name has been corrupted in the file");
	}

	std::ostream& operator<<(std::ostream& output, const Telemetry* data) {
		data->writeToFile(output);
		return output;
	}
}
