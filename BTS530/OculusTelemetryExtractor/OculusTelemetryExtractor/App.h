#ifndef _APP_H_
#define _APP_H_
#include <thread>
#include "DataExtractor.h"

namespace extractor {

	class App {
		private:
			DataExtractor dataEx;
			bool bThreadRunning;
		public:
			App();
			void run(const char*);
			int menu();
			void printOptionsToConsole();
	};
}

#endif 
