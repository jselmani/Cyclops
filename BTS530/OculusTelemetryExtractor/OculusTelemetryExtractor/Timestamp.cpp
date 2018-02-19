#define _CRT_SECURE_NO_WARNINGS
#include "Timestamp.h"

namespace extractor {
	std::string getCurrDate()
	{
		std::string currDate;

		time_t t = time(NULL);
		tm* timePtr = localtime(&t);

		currDate = std::to_string(timePtr->tm_year + 1900) + "-" + std::to_string(timePtr->tm_mon + 1) + "-" + std::to_string(timePtr->tm_mday);

		return currDate;
	}

	std::string getCurrTime()
	{
		std::ostringstream currTime;
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		std::chrono::milliseconds now  = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(now % std::chrono::seconds(1));

		currTime << std::setfill('0') << std::setw(2) << timePtr->tm_hour << '-'
			<< timePtr->tm_min << '-'
			<< timePtr->tm_sec << '-'
			<< std::setw(3) << msec.count()
			<< std::setfill(' ') << std::setw(0);

		return currTime.str();
	}
}