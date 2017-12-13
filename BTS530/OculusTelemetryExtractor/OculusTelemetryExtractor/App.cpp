#include "App.h"

namespace extractor {

	App::App() {}

	void App::run(const char* in) {
		int choice = menu();
		do {
			switch (choice) {
			case 1:
				dataEx.initHeadset();
				break;
			case 2:
				dataEx.initializeForSim(in);
				fileWriter = std::thread{ &write };
				fileWriter.detach();
				break;
			case 3:
				canWrite = false;
				dataEx.closeFile();
				break;
			case 4:
				char exit;
				std::cout << "Thank you for using the Oculus Telemetry Extractor.  Goodbye!" << std::endl;
				std::cout << "Please press any key to exit." << std::endl;
				std::cin >> exit;
				break;
			default:
				std::cout << "--- INVALID SELECTION ---" << std::endl;
				std::cout << "Please input a valid number" << std::endl;
				break;
			}
		} while (choice != 4);
	}

	int App::menu() {
		unsigned short input = 0;
		printOptionsToConsole();
		
		do {
			std::cin >> input;
			std::cout << std::endl;
			std::cin.clear();
			if (input >= 1 && input <= 4)
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
		std::cout << "3 - End Simulation" << std::endl;
		std::cout << "4 - Exit Program" << std::endl;
		std::cout << "> " << std::endl;
	}

	void App::write() {
		dataEx.writeDataToFile();
	}
}