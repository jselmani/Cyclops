#include "App.h"

using namespace extractor;

int main(int argc, char** argv) {
	try {
		App app;
		app.run(argv[1]);
	} 
	catch (std::string msg) {
		std::cout << msg << std::endl;
	}

	return 0;
}
