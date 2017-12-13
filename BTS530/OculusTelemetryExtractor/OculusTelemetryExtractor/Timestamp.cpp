#define _CRT_SECURE_NO_WARNINGS
#include "Timestamp.h"

namespace extractor {
	std::string getCurrDate()
	{
		std::string currDate;

		time_t t = time(NULL);
		tm* timePtr = localtime(&t);

		currDate = std::to_string(timePtr->tm_year + 1900) + "/" + std::to_string(timePtr->tm_mon + 1) + "/" + std::to_string(timePtr->tm_mday);

		return currDate;
	}
	std::string getCurrTime()
	{
		std::string currTime;
		
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		std::chrono::milliseconds now  = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(now % std::chrono::seconds(1));

		currTime = std::to_string(timePtr->tm_hour) + ':' 
				 + std::to_string(timePtr->tm_min)  + ':' 
				 + std::to_string(timePtr->tm_sec)  + ':' 
				 + std::to_string(msec.count());

		return currTime;
	}
}