#include "DataExtractor.h"

namespace extractor {

	//initialize hmd and other member variables
	DataExtractor::DataExtractor() {
		serialNum.clear();
		HmdPresent = false;
		file = nullptr;
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
	DataExtractor::~DataExtractor() {
		ovr_Destroy(hmd);
		ovr_Shutdown();
		data.clear();
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
		std::string date = getCurrDate();
		std::string time = getCurrTime();
		result << date << "_" << time << "-" << baseName << ext;
		return result.str();
	}

	// open file with dynamic name
	void DataExtractor::openFileForWriting() {
		serialNum = getSerialNum();
		file = new std::ofstream(createFileName(serialNum, ".csv").c_str());
	}

	// determine telemetry type to push into vector
	// vector will be iterated through to print data to file
	void DataExtractor::determineTelType(int telType) {
		switch (telType) {
		case 1:
			data.push_back(std::unique_ptr<Telemetry>(new AngAccel("Angular Acceleration")));
			break;
		case 2:
			data.push_back(std::unique_ptr<Telemetry>(new AngVelocity("Angular Velocity")));
			break;
		case 3:
			data.push_back(std::unique_ptr<Telemetry>(new LinAccel("Linear Acceleration")));
			break;
		case 4:
			data.push_back(std::unique_ptr<Telemetry>(new LinVelocity("Linear Velocity")));
			break;
		case 5:
			data.push_back(std::unique_ptr<Telemetry>(new Orientation("Orientation")));
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

	void DataExtractor::operator()(bool &bTerminate, int &lineCount) {
		guard.lock();
		while (bTerminate) {
			*file << getCurrTime() << ",";
			for (auto it = data.begin(); it != data.end(); it++) {
				(*it)->setData(hmd, trackState);
				(*it)->writeToFile(*file);
			}
			*file << std::endl;
			lineCount++;
			if (lineCount == 10000) {
				closeFile();
				openFileForWriting();
				lineCount = 0;
			}
			Sleep(75);
		}
		guard.unlock();
	}

	void DataExtractor::closeFile() {
		if (file->is_open()) {
			file->clear();
			file->close();
			delete file;
			file = nullptr;
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
