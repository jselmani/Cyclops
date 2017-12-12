#ifndef _APP_H_
#define _APP_H_
#include "DataExtractor.h"

namespace extractor {

	class App {
		private:
			DataExtractor dataEx;
		public:
			App();
			void run(const char*);
			int menu();
			void printOptionsToConsole();
	};
}

#endif 
