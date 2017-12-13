#ifndef _DATAEXTRACTOR_H_
#define _DATAEXTRACTOR_H_

#include <fstream>
#include <vector>
#include <windows.h>
#include <ShlObj.h>
#include <stdlib.h>
#include <sstream>
#include "AngAccel.h"
#include "AngVelocity.h"
#include "LinAccel.h"
#include "LinVelocity.h"
#include "Orientation.h"

/*
	TODO:
	- delete memory in DataExtractor::vector data by writing function
	- delete file memory
	- finish writing destructor
	- add date to file name
	- DEBUG/TEST WITH OCULUS
*/
namespace extractor {

	static bool canWrite = false;

	class DataExtractor {
		private:
			ovrSession hmd;
			ovrGraphicsLuid luid;
			ovrTrackingState trackState;
			ovrBool HmdPresent;
			std::ofstream* file;
			std::vector<Telemetry*> data;
			std::string serialNum;
			int counter; // used to change file name
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
			void writeDataToFile();
			void initializeForSim(const char*); // read in from file and build object
			void initHeadset();
	};
}

#endif
