#define _CRT_SECURE_NO_WARNINGS

#include "OculusDataExtractor.h"

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

OCULUSDATAEXTARCTION_API DataExtractor * CreateDataExtractor()
{
	return new DataExtractor();
}

OCULUSDATAEXTARCTION_API void DestroyDataExtractor(DataExtractor * dataEx)
{
	delete dataEx;
}

OCULUSDATAEXTARCTION_API void getData(DataExtractor * dataEx)
{
	dataEx->getData();
}

DataExtractor::DataExtractor()
{
	ovrResult result = ovr_Initialize(nullptr);

	result = ovr_Create(&hmd, &luid);
	if (OVR_FAILURE(result))
		ovr_Shutdown();

	TCHAR filePath[MAX_PATH];             // To store the path of the file.
	TCHAR fileName[] = L"\\Demo.txt"; // The file name must begin with "\\"

	GetDesktopfilePath(filePath, fileName);  // Get the full path of the file situated in the desktop.

	char c_szText[MAX_PATH];
	wcstombs(c_szText, filePath, wcslen(filePath) + 1);

	output.open(c_szText, std::ofstream::out);
}

DataExtractor::~DataExtractor()
{
	output.close();
	ovr_Destroy(hmd);
	ovr_Shutdown();
}

void DataExtractor::getData()
{
	ovrTrackingState ts = ovr_GetTrackingState(hmd, ovr_GetTimeInSeconds() + 0.005, ovrTrue);
	if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
		OVR::Vector3f angAccelData = ts.HeadPose.AngularAcceleration;
		OVR::Vector3f linAccelData = ts.HeadPose.LinearAcceleration;
		OVR::Vector3f gyroData = ts.HeadPose.AngularVelocity;
		OVR::Vector3f linVelData = ts.HeadPose.LinearVelocity;

		// get the "Head Pose" of the individual wearing HMD
		// create quaternion variable for Orientation information
		ovrPosef pose = ts.HeadPose.ThePose;
		OVR::Quatf quaternion = pose.Orientation;
		float yaw, pitch, roll;
		quaternion.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&yaw, &pitch, &roll);

		output << "Angular Acceleration (x,y,z): " << angAccelData.x << ", " << angAccelData.y << ", " << angAccelData.z << std::endl;
		output << "Linear Acceleration (x,y,z): " << linAccelData.x << ", " << linAccelData.y << ", " << linAccelData.z << std::endl;
		output << "Angular Velocity (x,y,z): " << gyroData.x << ", " << gyroData.y << ", " << gyroData.z << std::endl;
		output << "Linear Velocity (x,y,z): " << linVelData.x << ", " << linVelData.y << ", " << linVelData.z << std::endl;
		output << "Yaw: " << OVR::RadToDegree(yaw) << std::endl;
		output << "Pitch: " << OVR::RadToDegree(pitch) << std::endl;
		output << "Roll: " << OVR::RadToDegree(roll) << std::endl;
	}
}
