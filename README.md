# Group 14

Group Members
* Jiel Selmanovski
* Eric Schvartzman
* Rosario Cali
* Joseph Pildush

## Project Overview

### Client Information

Dr. Elliott Coleshill is a Professor and Industry Relations Coordinator at Seneca College of Applied Arts and Technology at the York University Campus.  Dr. Coleshill is interested to learn the capabilities of the Oculus Rift VR Headset and its peripheral technology, the Oculus Touch gamepad.  Currently, he is working on a cross-disciplinary project with Seneca College's School of Aviation where he will be creating a virtual experience with a vast set of tools; VR Headset, a VR Simulation Vest (ARAIG), Level 5 Flight Simulators, as well as his own proprietary software that he has developed for his research.


### Business Statement

Currently, pilots require a certain number of inflight hours before they are able to receive their piloting license. This is a very costly and endagering procedure since an untrained pilot would be taking control of a very expensive aircraft. Fuel is also very expensive. Dr. Coleshill has requested our team to learn the capabilities of a Virtual Reality Headset, the Oculus Rift, and create a project that allows him to learn and understand the exact capabilities of the Oculus Rift with ease. He is interested in administering a safe environment for both Professors and Students, with an end goal of providing the same experience to the pilot "on the ground" that they would receive in the cockpit "in the air". This safe environment would decrease the dangers and costs that are involed with training a new pilot.
Virtual reality technology is relatively new and our group has never worked with the technology before.  Therefore, we will be maintaining a relatively lower level of complexity in order to ensure project completion.  Our task is to generate a series of components to meet the requirements of the research project.  These components consist of customized scenes (the VR and desktop environments) such as the user interface and the cockpit (preferably a Static Cockpit) which would be designed and implemented using Unity's Game Engine, a Database to store data (User, Sensor Data, Timestamp), and software that will extract accelerometer and gyroscope data from the VR Headset and its peripheral device.

In order to aid Dr. Coleshill in his research, he requires technology that can process sensor information in real-time.  By doing so, he will be able to understand what and where the User is looking at, and how often.  With vast amounts of data being stored, it can be extracted for review where Dr. Coleshill can establish patterns in the flight and analyze the data accordingly on a per user basis.

In order to have a seamless and proper collaboration, each group member will be tasked on working on a particular portion of the project to lighten the workload.  Should any group members become overwhelmed, it is agreed upon that aid will be provided from group members and our client as well.  Our project has several requirements, and are as follows.

### Overall System Requirements
The project must solve the problem that our team has been tasked with and must meet certain requirements in order to be deemed successful.

#### General Requirements
* The project will only be accessible using an Oculus Rift headset and a capable-GPU personal computer (VR Ready).
* The database will only be accessible by an Admin.
* There will only be one Admin.

#### The Interface Requirements
* A UI must be present, user-friendly, and intuitive. It can be met in any of the following ways:
	* Via a Monitor or Screen,
	* Via the VR Headset
* The UI must only accept (authenticate) users that have been created by an Admin, including the Admin.
* When a User attempts to log in, and fails, the System must let the User know why they cannot begin their session.

#### The Database Requirements
* A Database will be built in order to store data that is being read from the VR Headset as well as to retrieve that data for analysis.
	* The user passwords will be hashed,
	* The data will only be accessible by an Admin.
	* The Admin login credentials will be basic and unchangeable for simplicity.
* Data must be able to be written to the database in near real-time without fault.
	* The language that will be used is yet to be determined.

#### The Scene Requirements
* The scene will be generated by the Unity Game Engine.
	* The scripts will be written in C#.
* In order to benefit Dr. Coleshill's research, it will be mocked to a cockpit of some kind, either a plane or a spaceship for added fun.
* The scene will start as a static scene
	* Initially, we plan on designing and working with a static scene. Depending on how fast the development progresses, we will implement a dynamic scene that incorporates movement within the scene.

#### The VR Sensor Extraction Requirements
* The client has requested that the extracted data is in real-time. We have two methods to bring this to fruition.
	* The data extracted will be timestamped in order for the admin to be able to analyze the data efficiently 
	* When the data extraction is successful, if the project is near completion and time remains we may attempt to give a visual representation of the data within:
		* The Oculus Rift display and/or
		* The desktop environment - this would only be accessible to an admin so they may analyse the data as it is being written.
* The Oculus Rift Headset and its peripheral technology uses C++ in it's SDK.
	* The software to extract the accelerometer and gyroscope data must be written in C++.

#### Logical Requirements



## Technical Overview

To be completed in Draft 2

## Use Cases

To be completed for final submissions
