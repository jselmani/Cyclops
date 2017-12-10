#include "DataExtractor.h"

namespace extractor {

	//initialize hmd and other member variables
	DataExtractor::DataExtractor() {
		serialNum.clear();
		counter = 0;
		ovrResult result = ovr_Initialize(nullptr);
		if (OVR_FAILURE(result))
			return;

		result = ovr_Create(&hmd, &luid);
		if (OVR_FAILURE(result)) {
			ovr_Shutdown();
			return;
		}
	}

	// read in from configuration file (see SampleConfig.csv)
	DataExtractor::DataExtractor(const char* in) {
		DataExtractor();
		std::ifstream inputFile(in, std::ios::in);

		if (inputFile.fail())
			throw std::string("Could not open the configuration file.");
		else {
			while (!inputFile.eof()) {
				int tmp;
				inputFile >> tmp;
				inputFile.ignore();
				determineTelType(tmp);
			}
		}
	}

	// Destructor
	DataExtractor::~DataExtractor() {
		ovr_Destroy(hmd);
		ovr_Shutdown();
	}

	// returns serial number of headset to be used as filename
	// can only be called after initialization of hmd
	std::string DataExtractor::getSerialNum() {
		ovrHmdDesc desc = ovr_GetHmdDesc(hmd);
		return desc.SerialNumber;
	}

	// create dynamic file names so data is not overwritten each time a new file is created
	std::string DataExtractor::createFileName(const std::string& baseName, const std::string& ext) {
		std::ostringstream result;
		result << baseName << "-" << counter++ << ext;
		return result.str();
	}

	// open file with dynamic name
	void DataExtractor::openFile() {
		serialNum = getSerialNum();
		file->getStream().open(createFileName(serialNum, ".csv").c_str());
	}

	// determine telemetry type to push into vector
	void DataExtractor::determineTelType(int telType) {
		switch (telType) {
		case 1:

		}
	}
}
