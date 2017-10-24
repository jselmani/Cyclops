#include "C:\OculusSDK\LibOVR\Include\OVR_CAPI.h" 
#include "C:\OculusSDK\LibOVR\Include\Extras\OVR_Math.h"

#include <fstream>
#include <windows.h>
#include <shlobj.h>
#include <stdlib.h>

#define OCULUSDATAEXTARCTION_API __declspec(dllexport)

bool GetDesktopfilePath(PTCHAR filePath, PTCHAR fileName);

class DataExtractor {
	ovrSession hmd;
	ovrGraphicsLuid luid;
	std::ofstream output;
public:
	DataExtractor();
	~DataExtractor();
	void getData();
};

extern "C" {
	OCULUSDATAEXTARCTION_API DataExtractor* CreateDataExtractor();
	OCULUSDATAEXTARCTION_API void DestroyDataExtractor(DataExtractor* dataEx);
	OCULUSDATAEXTARCTION_API void getData(DataExtractor* dataEx);
}