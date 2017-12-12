#ifndef _DATAEXTRACTOR_H_
#define _DATAEXTRACTOR_H_
#define FILE_LENGTH 2000

#include "File.h"
#include "AngAccel.h"
#include "AngVelocity.h"
#include "LinAccel.h"
#include "LinVelocity.h"
#include "Orientation.h"

/*
	TODO:
	- Add timestamp to every telemetry data point
	- write to file by using threads
	- write main to run program
	- DEBUG/TEST WITH OCULUS
*/
namespace extractor {

	class DataExtractor {
	private:
		ovrSession hmd;
		ovrGraphicsLuid luid;
		ovrTrackingState trackState;
		File* file;
		std::vector<Telemetry*> data;
		std::string serialNum;
		int counter; // used to change file name
	public:
		DataExtractor();
		~DataExtractor();
		std::string getSerialNum();
		std::string createFileName(const std::string&, const std::string&);
		void determineTelType(int);
		void openFileForWriting();
		void initializeForSim(const char*); // read in from file and build object
		void initHeadset();
	};
}

#endif
