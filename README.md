# Group 14

Group Members
* Jiel Selmanovski
* Eric Schvartzman
* Rosario Cali
* Joseph Pildush

## Project Overview

### Client Information

Our client, Dr. Elliott Coleshill, is a Professor and Industry Relations Coordinator at Seneca College of Applied Arts and Technology, York University Campus.  Dr. Coleshill has tasked us with learning the capabilities of the Oculus Rift VR Headset and its peripheral technology, the Oculus Touch gamepad.  He is currently working on a cross-disciplinary project with Seneca College's School of Aviation where he will be combining our technology with a vast set of other tools; a VR Simulation Vest (ARAIG), Level 5 Flight Simulators, as well as his own proprietary software that he has developed for his research.

He is interested in administering a safe environment for both Professors and Students, with an end goal of providing the same experience to the pilot "on the ground" that they would receive in the cockpit. 

### Business Statements

Virtual reality technology is relatively new and our group has never worked with the technology before.  Therefore, we will be maintaining a relatively lower level of complexity in order to ensure project completion.  Our task is to generate a series of components to meet the requirements of the research project.  These components consist of a Unity Game Engine User Interface, a Database to store data (User, Sensor Data, Timestamp), a Unity Game Engine Scene (preferably a Static Cockpit), and software that will extract accelerometer and gyroscope data from the VR Headset and its peripheral device.

In order to aid Dr. Coleshill in his research, he requires technology that can process sensor information in real-time.  By doing so, he will be able to understand what and where the User is looking at, and how often.  With vast amounts of data being stored, it can be extracted for review where Dr. Coleshill can establish patterns in the flight and analyze the data accordingly on a per user basis.

To make our lives easier, each group member will be tasked on working on a particular portion of the project to lighten the workload.  Should any group members become overwhelmed, it is agreed upon that aid will be provided from group members and our client as well.  Our project has several requirements, and are as follows.

### Overall System Requirements
The project must solve the problem that our team has been tasked with and must meet certain requirements in order to be deemed successful.

#### General Requirements
* The project will only be accessible using an Oculus Rift headset and a capable-GPU personal computer (VR Ready).
* The database will only be accessible by an Admin.
* There will only be one Admin.

#### The Interface Requirement
* A UI must be present, user-friendly, and intuitive. It can be met in any of the following ways:
	* Via a Monitor or Screen,
	* Via the VR Headset
* The UI must only accept (authenticate) users that have been created by an Admin, including the Admin.
* When a User attempts to log in, and fails, the System must let the User know why they cannot begin their session.

#### The Database Requirement
* A database will be designed and built using MySQL or NoSQL where all information will be stored.
	* The user passwords will be hashed,
	* The data will only be accessible by an Admin.
	* The Admin login credentials will be basic and unchangeable for simplicity.
* Data must be able to be written to the database in near real-time without fault.
	* The language that will be used is yet to be determined.

#### The Scene Requirement
* The scene will be generated by the Unity Game Engine.
	* The scripts will be written in C#.
* In order to benefit Dr. Coleshill's research, it will be mocked to a cockpit of some kind, either a plane or a spaceship for added fun.
	* This detail is yet to be determined.
* The scene will remain static.
	* If progress is being made and time remains, we may attempt to build a dynamic scene that incorporates movement within the scene.

#### The VR Sensor Extraction Requirement
* The Oculus Rift Headset and its peripheral technology uses C++ in it's SDK.
	* The software to extract the accelerometer and gyroscope data must be written in C++.
* The client has requested that the extracted data is in real-time.
	* We must be able to achieve as close to near real-time as possible.
	* When the data extraction is successful, we may attempt to give a visual representation of the data within the Oculus Rift display if project is near completion and time remains.

## Technical Overview

To be completed in Draft 2

## Use Cases

To be completed for final submissions
