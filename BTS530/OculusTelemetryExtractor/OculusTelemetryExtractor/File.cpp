#include "File.h"

namespace extractor {

	std::ofstream& File::getStream() {
		return ostr;
	}
}
