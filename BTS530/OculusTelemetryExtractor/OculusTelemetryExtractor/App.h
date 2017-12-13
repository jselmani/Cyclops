#ifndef _APP_H_
#define _APP_H_
#include <thread>
#include "DataExtractor.h"

namespace extractor {

	class App {
		private:
			DataExtractor dataEx;
			std::thread fileWriter;
		public:
			App();
			void run(const char*);
			void write();
			int menu();
			void printOptionsToConsole();
	};
}

#endif 
