#include "DataExtractor.h"

namespace extractor {

	//initialize hmd and other member variables
	DataExtractor::DataExtractor() {
		serialNum.clear();
		counter = 0;
	}

	// read in from configuration file (see SampleConfig.csv)
	// and build object
	void DataExtractor::initializeForSim(const char* s) {
		initHeadset();
		std::ifstream file(s, std::ios::in);
		if (file.fail())
			throw std::string("Could not open the configuration file.");
		else {
			while (!file.eof()) {
				int tmp;
				file >> tmp;
				file.ignore();
				determineTelType(tmp);
			}
			openFileForWriting();
		}
	}

	// Destructor
	// TODO: clean up all values, not just HMD
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
	void DataExtractor::openFileForWriting() {
		serialNum = getSerialNum();
		file->getStream().open(createFileName(serialNum, ".csv").c_str());
	}

	// determine telemetry type to push into vector
	// vector will be iterated through to print data to file
	void DataExtractor::determineTelType(int telType) {
		switch (telType) {
		case 1:
			data.push_back(new AngAccel("Angular Acceleration"));
			break;
		case 2:
			data.push_back(new AngVelocity("Angular Velocity"));
			break;
		case 3:
			data.push_back(new LinAccel("Linear Acceleration"));
			break;
		case 4:
			data.push_back(new LinVelocity("Linear Velocity"));
			break;
		case 5:
			data.push_back(new Orientation("Orientation"));
			break;
		default:
			throw new std::string("The configuration file has been corrupted.");
			break;
		}
	}

	void DataExtractor::initHeadset() {
		ovrResult result = ovr_Initialize(nullptr);
		if (OVR_FAILURE(result))
			return;

		result = ovr_Create(&hmd, &luid);
		if (OVR_FAILURE(result)) {
			ovr_Shutdown();
			return;
		}
	}
}
