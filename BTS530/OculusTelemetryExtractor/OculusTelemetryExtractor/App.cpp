#include "App.h"

namespace extractor {

	App::App() {}

	void App::run(const char* in) {
		int choice = menu();
		do {
			switch (choice) {
			case 1:
				dataEx.initializeForSim(in);
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				std::cout << "--- INVALID SELECTION ---" << std::endl;
				std::cout << "Please input a valid number" << std::endl;
				break;
			}
		} while (choice != 3);
	}

	int App::menu() {
		unsigned short input = 0;
		printOptionsToConsole();
		
		do {
			std::cin >> input;
			std::cout << std::endl;
			std::cin.clear();
			if (input >= 1 && input <= 3)
				break;
			else
				printOptionsToConsole();
		} while (!std::cin.fail());

		return input;
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