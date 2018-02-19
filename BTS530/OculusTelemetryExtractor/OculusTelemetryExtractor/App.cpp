#include "App.h"

namespace extractor {

	App::App() { 
		bThreadRunning = false; 
		lineCount = 0;
	}

	void App::run(const char* in) {
		int choice = 0;
		do {
			choice = menu();
			switch (choice) {
			case 1:
				dataEx.initHeadset();
				break;
			case 2:
				dataEx.initializeForSim(in);
				if (dataEx.headsetPresent()) {
					bThreadRunning = true;
					std::thread writeFile(std::ref(dataEx), std::ref(bThreadRunning), std::ref(lineCount));
					writeFile.detach();
				}
				break;
			case 3:
				if (dataEx.getFileObject().is_open()){
					bThreadRunning = false;
					dataEx.closeFile();
				}
				else
					std::cout << "--- START SIMULATION FIRST ---" << std::endl << std::endl;
				break;
			case 4:
				char exit;
				std::cout << "Thank you for using the Oculus Telemetry Extractor.  Goodbye!" << std::endl;
				std::cout << "Please press any key to exit." << std::endl;
				std::cin >> exit;
				break;
			default:
				std::cout << "--- INVALID SELECTION ---" << std::endl;
				std::cout << "Please input a valid number" << std::endl << std::endl;
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
		Sleep(3000);
		system("cls");
		std::cout << "Oculus Rift Data Extraction & Simulation Software" << std::endl;
		std::cout << "=================================================" << std::endl;
		std::cout << "1 - Initialize Headset" << std::endl;
		std::cout << "2 - Begin Simulation" << std::endl;
		std::cout << "3 - End Simulation" << std::endl;
		std::cout << "4 - Exit Program" << std::endl;
		std::cout << "> ";
	}
}