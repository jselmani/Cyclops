#include "C:\OculusSDK\LibOVR\Include\OVR_CAPI.h" 
#include "C:\OculusSDK\LibOVR\Include\Extras\OVR_Math.h"

#include <fstream>
#include <windows.h>
#include <shlobj.h>
#include <stdlib.h>

#define OCULUSDATAEXTRACTION_API __declspec(dllexport)

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
	OCULUSDATAEXTRACTION_API DataExtractor* CreateDataExtractor();
	OCULUSDATAEXTRACTION_API void DestroyDataExtractor(DataExtractor* dataEx);
	OCULUSDATAEXTRACTION_API void getData(DataExtractor* dataEx);
}