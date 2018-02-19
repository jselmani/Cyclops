#ifndef _APP_H_
#define _APP_H_
#include <thread>
#include "DataExtractor.h"

namespace extractor {

	class App {
		private:
			DataExtractor dataEx;
			bool bThreadRunning;
			int lineCount; // used to determine how many lines written in a file
		public:
			App();
			void run(const char*);
			int menu();
			void printOptionsToConsole();
	};
}

#endif 
