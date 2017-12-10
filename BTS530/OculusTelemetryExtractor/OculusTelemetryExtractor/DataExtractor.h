#ifndef _DATAEXTRACTOR_H_
#define _DATAEXTRACTOR_H_
#define FILE_LENGTH 2000

#include "File.h"
#include "Telemetry.h"

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
		DataExtractor(const char*);
		~DataExtractor();
		std::string getSerialNum();
		std::string createFileName(const std::string&, const std::string&);
		void determineTelType(int);
		void openFile();
	};
}

#endif
