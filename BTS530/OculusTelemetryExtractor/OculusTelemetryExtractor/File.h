#ifndef _FILE_H_ 
#define _FILE_H_

#include <string>
#include <fstream>
#include <windows.h>
#include <ShlObj.h>
#include <stdlib.h>
#include <sstream>

namespace extractor {

	class File {
	private:
		std::ofstream ostr;
	public:
		std::ofstream& getStream();
		//File& operator=(File&);
	};
}

#endif 
