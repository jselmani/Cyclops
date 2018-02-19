#ifndef _DATAEXTRACTOR_H_
#define _DATAEXTRACTOR_H_

#include <fstream>
#include <vector>
#include <mutex>
#include <memory>
#include <windows.h>
#include <ShlObj.h>
#include <stdlib.h>
#include "AngAccel.h"
#include "AngVelocity.h"
#include "LinAccel.h"
#include "LinVelocity.h"
#include "Orientation.h"

namespace extractor {

	static std::mutex guard;

	class DataExtractor {
		private:
			ovrSession hmd;
			ovrGraphicsLuid luid;
			ovrTrackingState trackState;
			ovrBool HmdPresent;
			std::ofstream* file;
			std::vector<std::unique_ptr<Telemetry>> data;
			std::string serialNum;
		public:
			DataExtractor();
			~DataExtractor();
			std::string getSerialNum();
			std::string createFileName(const std::string&, const std::string&);
			std::ofstream& getFileObject();
			ovrBool headsetPresent();
			void closeFile();
			void determineTelType(int);
			void openFileForWriting();
			void initializeForSim(const char*); // read in from file and build object
			void initHeadset();
			void operator()(bool&, int&);
	};
}

#endif
