#include "App.h"

namespace extractor {

	App::App() {}

	int App::run(const char*) {

	}

	int App::menu() {
		unsigned short input = 0;
		printOptionsToConsole();
		
		do {
			std::cin >> input;
			std::cout << std::endl;
			std::cin.clear();
			if (input >= 1 && input <= 3)
				return input;
			else
				printOptionsToConsole();
		} while (!std::cin.fail());
	}

	void App::printOptionsToConsole() {
		std::cout << "Oculus Rift Data Extraction & Simulation Software" << std::endl;
		std::cout << "=================================================" << std::endl;
		std::cout << "1 - Initialize Headset" << std::endl;
		std::cout << "2 - Begin Simulation" << std::endl;
		std::cout << "3 - Exit Program" << std::endl;
		std::cout << "> " << std::endl;
	}
}