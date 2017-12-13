#include "DataExtractor.h"

namespace extractor {

	//initialize hmd and other member variables
	DataExtractor::DataExtractor() {
		serialNum.clear();
		counter = 0;
		HmdPresent = false;
	}

	// read in from configuration file (see SampleConfig.csv)
	// and build object
	void DataExtractor::initializeForSim(const char* in) {
		if (!HmdPresent)
			std::cout << "--- INITIALIZE HEADSET FIRST ---" << std::endl << std::endl;
		else {
			data.clear();
			std::ifstream configFile(in, std::ios::in);
			configFile.seekg(0, configFile.beg);
			if (configFile.fail())
				throw std::string("Could not open the configuration file.");
			else {
				while (!configFile.eof()) {
					int tmp = 0;
					configFile >> tmp;
					if (tmp == 0)
						break;
					configFile.ignore();
					determineTelType(tmp);
				}
				configFile.close();
				openFileForWriting();
				std::cout << "--- INITIALIZED FOR SIMULATION ---" << std::endl << std::endl;
			}
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
		file = new std::ofstream();
		file->open(createFileName(serialNum, ".csv").c_str(), std::ofstream::out);
		canWrite = true;
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
		HmdPresent = true;
		std::cout << "--- HEADSET INITIALIZED ---" << std::endl << std::endl;
	}

	void DataExtractor::writeDataToFile() {
		if (!file->is_open()) {
			throw std::string("The file is corrupted.");
		}
		else {
			while (extractor::canWrite) {
				for (auto it = data.begin(); it != data.end(); it++) {
					(*it)->setData(hmd, trackState);
					(*it)->writeToFile(*file);
				}
				*file << std::endl;
				Sleep(50);
			}
		}
	}

	void DataExtractor::closeFile() {
		if (file->is_open()) {
			file->clear();
			file->close();
		}
		else
			std::cout << "A file has not been opened yet.  Begin a simulation to write to a file." << std::endl;
	}

	std::ofstream& DataExtractor::getFileObject() {
		return *file;
	}

	ovrBool DataExtractor::headsetPresent() {
		return HmdPresent;
	}
}
