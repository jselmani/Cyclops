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

using namespace OVR;
using namespace std;

// essentially the destructor for the head mounted display
void clear(ovrSession& hmd) {
	ovr_Destroy(hmd);
	ovr_Shutdown();
}

// initializes the headset and also executes the Oculus Runtime
// during intialization if not already running
void init(ovrSession& hmd, ovrGraphicsLuid& luid) {
	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
		return;

	result = ovr_Create(&hmd, &luid);
	if (OVR_FAILURE(result)) {
		ovr_Shutdown();
		return;
	}
}

// prints data about the oculus rift to the console
void printHmdDesc(ovrHmdDesc& desc) {
	cout << "                       Headset Description                        " << endl;
	cout << "==================================================================" << endl;
	cout << "Product Name: " << desc.ProductName << endl;
	cout << "Serial Number: " << desc.SerialNumber << endl;
	cout << "Headset Refresh Rate: " << desc.DisplayRefreshRate << " frames per second" << endl << endl;
}

// prints MEMS data to the console
void printMEMSData(ovrSession& hmd) {
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

		cout << "Angular Acceleration (x,y,z): " << angAccelData.x <<
			", " << angAccelData.y << ", " << angAccelData.z << endl;
		cout << "Linear Acceleration (x,y,z): " << linAccelData.x <<
			", " << linAccelData.y << ", " << linAccelData.z << endl;
		cout << "Angular Velocity (x,y,z): " << gyroData.x << ", " <<
			gyroData.y << ", " << gyroData.z << endl;
		cout << "Linear Velocity (x,y,z): " << linVelData.x << ", " <<
			linVelData.y << ", " << linVelData.z << endl;
		cout << "Yaw: " << RadToDegree(yaw) << endl;
		cout << "Pitch: " << RadToDegree(pitch) << endl;
		cout << "Roll: " << RadToDegree(roll) << endl;
	}
}

// parent console printer to printHmdDesc and printMEMSData
void outputData(ovrSession& hmd) {
	ovrHmdDesc desc = ovr_GetHmdDesc(hmd);
	ovrSizei resolution = desc.Resolution;
	printHmdDesc(desc);
	cout << "                           Sensor Data                            " << endl;
	cout << "==================================================================" << endl;
	for(int i = 0; i < 2000; i++) {
		printMEMSData(hmd);
		Sleep(200);
	}
}

int main() {
	ovrSession hmd;
	ovrGraphicsLuid luid;
	init(hmd, luid);
	outputData(hmd);
	clear(hmd);
}
