#define _CRT_SECURE_NO_WARNINGS
/***********************************************
Oculus Data Extractor

Author: Jiel Selmani
Date: October 21, 2017
************************************************/

// change paths to match local machine 
#include "../OculusSDK/LibOVR/Include/OVR_CAPI.h" 
#include "../OculusSDK/LibOVR/Include/Extras/OVR_Math.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <shlobj.h>
#include <stdlib.h>


using namespace OVR;
using namespace std;

// essentially the destructor for the head mounted display
void clear(ovrSession& hmd) {
	ovr_Destroy(hmd);
	ovr_Shutdown();
}

bool GetDesktopfilePath(PTCHAR filePath, PTCHAR fileName)
{
	// Get the full path of the desktop :
	if (FAILED(SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT, filePath))) // Store the path of the desktop in filePath.
		return false;

	SIZE_T dsktPathSize = lstrlen(filePath); // Get the size of the desktope path.
	SIZE_T fileNameSize = lstrlen(fileName); // Get the size of the file name.

	// Appending the fileName to the filePath :
	memcpy((filePath + dsktPathSize), fileName, (++fileNameSize * sizeof(WCHAR)));

	return true;
}

// initializes the headset and also executes the Oculus Runtime
// during intialization if not already running
void init(ovrSession& hmd, ovrGraphicsLuid& luid, std::ofstream& output) {
	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
		return;

	result = ovr_Create(&hmd, &luid);
	if (OVR_FAILURE(result)) {
		ovr_Shutdown();
		return;
	}

	TCHAR filePath[MAX_PATH];           // store the path of the file
	TCHAR fileName[] = L"\\Demo.csv";   // the file name must begin with "\\"

	GetDesktopfilePath(filePath, fileName); // get the full path of the file situated in the Desktop

	char c_szText[MAX_PATH];
	wcstombs(c_szText, filePath, wcslen(filePath) + 1);

	output.open(c_szText, std::ofstream::out);
}

// prints data about the oculus rift to the console
void printHmdDesc(ovrHmdDesc& desc, std::ofstream& output) {
	output << "                       Headset Description                        " << endl;
	output << "==================================================================" << endl;
	output << "Product Name: " << desc.ProductName << endl;
	output << "Serial Number: " << desc.SerialNumber << endl;
	output << "Headset Refresh Rate: " << desc.DisplayRefreshRate << " frames per second" << endl << endl;
}

// prints MEMS data to the console
void printMEMSData(ovrSession& hmd, std::ofstream& output) {
	// collect the tracking state of the headset
	// ovr_GetTimeInSeconds() grabs an absolute position at the time it was grabbed.
	// by adding 0.005 seconds, we "predict" the data and lessen the overhead on the CPU
	ovrTrackingState ts = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
	if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
		Vector3f angAccelData = ts.HeadPose.AngularAcceleration;
		Vector3f linAccelData = ts.HeadPose.LinearAcceleration;
		Vector3f gyroData = ts.HeadPose.AngularVelocity;
		Vector3f linVelData = ts.HeadPose.LinearVelocity;
		
		// get the "Head Pose" of the individual wearing HMD
		// create quaternion variable for Orientation information
		ovrPosef pose = ts.HeadPose.ThePose;
		Quatf quaternion = pose.Orientation;
		float yaw, pitch, roll;
		quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);

		output << angAccelData.x << "," << angAccelData.y << "," << angAccelData.z << ","
			<< linAccelData.x << "," << linAccelData.y << "," << linAccelData.z << ","
			<< gyroData.x << "," << gyroData.y << "," << gyroData.z << ","
			<< linVelData.x << "," << linVelData.y << "," << linVelData.z << ","
			<< RadToDegree(yaw) << "," << RadToDegree(pitch) << "," << RadToDegree(roll) << endl;

		/*output << "Angular Acceleration (x,y,z): " << angAccelData.x << ", " << angAccelData.y << ", " << angAccelData.z << endl;
		output << "Linear Acceleration (x,y,z): " << linAccelData.x << ", " << linAccelData.y << ", " << linAccelData.z << endl;
		output << "Angular Velocity (x,y,z): " << gyroData.x << ", " << gyroData.y << ", " << gyroData.z << endl;
		output << "Linear Velocity (x,y,z): " << linVelData.x << ", " << linVelData.y << ", " << linVelData.z << endl;
		output << "Yaw: " << RadToDegree(yaw) << endl;
		output << "Pitch: " << RadToDegree(pitch) << endl;
		output << "Roll: " << RadToDegree(roll) << endl;*/
	}
}

// parent console printer to printHmdDesc and printMEMSData
void outputData(ovrSession& hmd, std::ofstream& output) {
	ovrHmdDesc desc = ovr_GetHmdDesc(hmd);
	ovrSizei resolution = desc.Resolution;
	printHmdDesc(desc, output);
	output << "                           Sensor Data                            " << endl;
	output << "==================================================================" << endl;
	for(int i = 0; i < 250; i++) {
		printMEMSData(hmd, output);
		Sleep(200);
	}
}

int main() {
	ovrSession hmd;
	ovrGraphicsLuid luid;
	std::ofstream output;
	init(hmd, luid, output);
	outputData(hmd, output);
	clear(hmd);
}
