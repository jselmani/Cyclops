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

Currently, pilots require a certain number of inflight hours before they are able to receive their piloting license. This is a very costly procedure since fuel is very expensive and could be dangerous since an untrained pilot would be in control of the aircraft. Dr. Coleshill has requested our team to learn the capabilities of a Virtual Reality Headset, the Oculus Rift, and create a project that allows him to learn and understand the exact capabilities of the Oculus Rift with ease. He is interested in administering a safe environment for both Professors and Students, with an end goal of providing the same experience to the pilot "on the ground" that they would receive in the cockpit "in the air". This safe environment would decrease the dangers and costs that are involved with training a new pilot.  This environment will be rendered as a Scene (what is displayed to the user via the Oculus Rift) to engage the pilot in a cockpit setting, but in a cost-effective environment.
Virtual reality technology is relatively new and our group has never worked with the technology before.  Therefore, we will be maintaining a relatively lower level of complexity in order to ensure project completion.  Our task is to generate a series of components to meet the requirements of the research project.  These components consist of customized scenes (the VR and desktop environments) such as the user interface and the cockpit which would be designed and implemented using Unity's Game Engine, a CSV file to store data (Headset Serial Number, Sensor Data, Timestamp), and software that will extract accelerometer and gyroscope data from the VR Headset and its peripheral device.

In order to aid Dr. Coleshill in his research, he requires technology that can process sensor information in real-time.  By doing so, he will be able to understand what and where the User is looking at, and how often.  With vast amounts of data being stored, it can be extracted for review where Dr. Coleshill can establish patterns in the flight and analyze the data accordingly on a per user basis.

To cut down on development time, each group member will be tasked on working on a particular portion of the project to lighten the workload.  Should any group members become overwhelmed, it is agreed upon that aid will be provided from group members and our client as well.  Our project has several requirements, and are as follows.

### Overall Goals and Milestones
The project must accomplish the following milestones:

1. The project must demonstrate the ability to extract telemetry data from the Oculus Rift headset while running a flight simulation. (COMPLETED)
	* The Oculus C++ SDK must be utilized in order to extract the data from the headset and store it into a .CSV file.
2. A Desktop UI must be functional. (COMPLETED)
	* The Desktop UI should let Users seamlessly setup the Oculus Rift Headset without complications.
	* The Desktop UI should allow users to start and stop the extraction of data with a click of a button.
	* The Desktop UI should also allow users to configure the C++ application by presenting check boxes that let's users select specific telemetry data to be extracted.
3. A C++ application should extract the telemetry data from the headset and store it into a .CSV file that is located in the directory specified by the User in the Desktop UI. (COMPLETED)
4. The unity scene should present a 3D cockpit with the following objects that Users can interact with: (IN PROGRESS)
	* A thruster object that will accelerate/de-accelerate the speed of the spaceship in the x, y, and z planes.
	* A joystick that can rotate the spaceship in the x and z planes.
5. The Oculus Rift device should function within the Unity scene and Users should be able to interact with the thruster and joystick using the Oculus peripherals (Touch Controllers). (IN PROGRESS)
6. Final documentation will be written to describe how to setup the environment (including where to place the SDK) and how to use the application for further use. (IN PROGRESS)

### Overall System Requirements
The project must solve the problem that our team has been tasked with and must meet certain requirements in order to be deemed successful.

#### General Requirements
* The project will only be accessible using an Oculus Rift headset and a capable-GPU personal computer (VR Ready).
* A Desktop UI that allows users to setup the Oculus Rift and configure the C++ application for the storage of specific headset telemetry data.
* The project will store telemetry data in .CSV files

#### The Interface Requirements
* A UI must be present, user-friendly, and intuitive. It can be met in the following way:
	* Via a Monitor

#### The data storage Requirements
* Data from the headset technology and its peripherals will be written to a .CSV and stored into a folder structure.
* A .CSV file will be created for the following two reasons:
	* Configuration file - pre-selects specific data that will get stored into the telemetry file
	* Telemetry data - Can contain angular/linear velocity, rotation, etc.
* A CSV file will be used to store and retrieve data, following the rules below:
	* Data from the headset technology and its peripherals will be written in a table format.
	* Each table will hold data of a scene that has been run by a user.
* The folder structure for the storage of the CSV files will be created in the following format:
	* Date and Headset serial number folder -> .CSV file
* The folder will be created once per day per use.
* A .CSV file will be created for each session of the flight simulation.

#### The Scene Requirements
* The scene will be generated by the Unity Game Engine.
* In order to benefit Dr. Coleshill's research, it will be mocked to a cockpit of some kind, either a plane or a spaceship for added fun.
* Initially, we plan on designing and working with a static scene.
	* Depending on how fast the development progresses, we will implement a dynamic scene that incorporates movement within the scene.

#### The VR Sensor Extraction Requirements
* The client has requested that the extracted data is in real-time. We have two methods to bring this to fruition.
	* The data extracted will be time stamped in order for the admin to be able to analyze the data efficiently
	* The data will be written to a .CSV file where the data will be extracted at intervals between 50-200 milliseconds
	* During the extraction of the headset data a visual representation of the data will displayed in the Desktop UI in a table format.
* The Oculus Rift Headset and its peripheral technology uses C++ in it's SDK.
	* The software to extract the accelerometer and gyroscope data must be written in C++.

#### Logical Requirements
* A user would be able to:
	* Chose the type of scene they would like to use in the Desktop UI.
	* Once a scene is chosen, data will be written to the .CSV file based on the movement of the VR Headset and its peripheral device.
	* For a user to end the scene, there should be a button dedicated on the peripheral device that the user may press (so the transmission of data will be cutoff) or a button will be implemented within the UI that has the same effect.


## Technical Overview

This project consists of several components including the **front-end interfaces** for the user to access and perform the use cases, a **data storage** component to store the extracted data from the Oculus Rift and its peripheral technology.

In this technical overview, we will list these components and their requirements, and discuss the technologies and their uses in order to run the program smoothly.

### Components and Requirements

* Minimum Desktop/Laptop Hardware Requirements:
	* Graphics Card – NVIDIA GTX 960 / AMD Radeon R9 290 or equivalent
	* CPU – Intel i3-6100 / AMD Ryzen 3 1200, FX4350 or equivalent
	* RAM – 8GB or greater
	* HDMI – version 1.3
	* USB 3.0 – 1 Port
	* USB 2.0 – 2 Ports
	* 15 GB of storage space
* Oculus Hardware Requirements
	* Oculus Rift Headset
	* Oculus Touch (Touch Controllers) – pair of handheld motion controllers
	* Constellation – the positional tracking system which comes with the headset and the Oculus touch
		* Tracks the position of the user's head with the HMD attached.
* Software Requirements:
	* Oculus Home – base software of the rift which starts VR applications
	* Oculus PC SDK - written in C++
	* Oculus Runtime/Drivers - the runtime and drivers must be installed in order for the rift to function.
	* Operating System – Windows 8.1 or newer
	* Unity Game Engine - Unity is primarily used to develop video games and simulations, written in C#.

### Technologies

#### Front-End Interfaces

This project uses the Unity game engine to render the scene that will consequently be built using the engine itself.  Unity is a popular content creation system that is used by many game developers worldwide but is now evolving to become a research and development tool for companies and organizations.  We are using Unity for the following reasons:

* Integrated Oculus Rift support
* Uses C# and has detailed documentation when needing help in designing software solutions
* An asset store for requiring models that would take months to build (ie. cockpit)
* Video resources explaining VR concepts and how to utilize them efficiently in the engine.
* Running external processes (Rift sensory data extraction) on scene launch after the user has been validated by the back-end.

In regards to Unity itself, it was the clear winner over other engines like Unreal or CryEngine.  Although Unreal utilizes C++ for the logic, Unreal requires much more code to perform the same tasks that would otherwise be written in C# when using Unity.  Consequently, Unity is much easier to learn and does not have a very steep learning curve in comparison, making it the wise choice for us as beginner virtual reality developers.

Discussing virtual reality, we have mentioned several times that we will be using the Oculus Rift headset in comparison to other head-mounted displays like the HTC Vive.  We are using it for the following reasons:
* Availability
	* Seneca College of Applied Arts and Technology has several Oculus Rift headsets available for use and with the correct permissions from our client, we will be able to work with technology as frequently as we need to.
* Cost
	* One of our group members has already purchased an Oculus Rift as it is cheaper by approximately $300.00 CAD and performs the same functions as other head-mounted displays on the market.
* Documentation
	* The Oculus Rift is very well documented, with plenty of tutorials spanning the web explaining how to use it efficiently to perform certain tasks.

For the reasons outlined above, our front-end will be using rather simple technologies to build a relatively complex solution for our client.

#### Data Storage

Using the Oculus SDK, the project will export the telemetry data from the Oculus Rift and its peripherals into a .CSV file for each session.
We have chosen to use C++ and .CSV file format for the following reasons:
* Oculus SDK
  * The SDK is written in C++ and it is imperative that we use C++ in order to extract the sensory data.
  * The C++ application is lightweight and will be running in the background once the user has launched the scene.
    * This will occur using the Process object in the Unity game engine.
* .CSV files
	* Able to create tables to easily organize telemetry data
	* Compatible across multiple platforms.

# System Components

### Oculus Rift SDK/API

The backbone of the entire project, this component will be utilized to extract the telemetry data from the headset and its peripherals, the Oculus Touch gamepads via a C++ program.

### Unity Game Engine

The game engine will be used to generate the Scene for the User.  It will be used by the development team to build and create the environment that the User will immerse themselves in using the Oculus Rift headset.

### Data Storage

Store telemetry data into .CSV files, which will be stored in the file system locally on the machine after completion of each session for the flight simulation.

# Use Cases

### Administrator Creates A New User Account
**Pre-requisites**: The administrator already has all the new user information and is currently logged in.</br>
**Actor**: Administrator.</br>
**Use Case Successful Post-Conditions**: The administrator creates a new user account.

1. The administrator clicks on **Create New User**.
2. The system changes its view to display a form to the administrator for him/her to fill up with the new user information.
3. The administrator enters the new user information and clicks on the **Submit** button inside the form.
	* The administrator can cancel this operation by clicking on the **Reset** button inside the form, or by clicking the
	**Back** button. By clicking on the **Reset** button the form will be cleared, instead, by clicking on the **Back**
	button the Administrator will be taken back to the main dashboard.
4. The system checks the validity of the provided user information and creates a new user account if the form is valid.
	* The system will display an error on the screen next to field where the error occurred. The administrator can enter the field again.
5. After successfully creating a new user, the system will display a pop-up message informing the administrator about the successful operation and the form will be cleared.

### User Login
**Pre-requisites**: The User has an account in the system and is on the login page.</br>
**Actor**: Student/Administrator.</br>
**Use Case Successful Post-Conditions**: The user is authenticated by the system.</br>

1. The user clicks on **Login**.
2. The System brings up a model for the user to enter his/her credentials.
3. The user enters his/her credentials (username and password) and clicks on the **Login** button inside the model.
	* The user can cancel this operation by clicking on the **cancel** button inside the model.
4. The system will query the database and compare the credentials provided by the user. If a match is found, then the system will authenticate the user.
	* The system sends an error message in case authentication fails. The user can enter his/her credentials again.
5. After the system successfully authenticates the user, they are redirected to a menu page displaying a list of options for flight training simulations.

### Administrator Retrieves File Data From Database
**Pre-requisites**: The Administrator is logged into the Mongo shell using Administrator credentials.<br/>
**Actor**: Administrator.<br/>
**Use Case Successful Post-Conditions**: The Administrator has found the file(s) path and opens the file(s).<br/>

1. The Administrator queries the database to locate the session they are looking for.  This will be done by using the Users Student Number as the unique identifier and the date the session took place. An example of the query: db.sessions.find({ userId: '101101152', created_at: '20170115'})
2. The Administrator examines the database BSON output and finds the URL path that is referenced in the BSON document.
	* The BSON output is empty, the Administrator will have to repeat step #1 or cancel the operation.
3. The Administrator copies the URL path from the console and pastes in the file system address bar.
4. The Administrator successfully locates the file and examines the data as preferred using their preferred data visualization method.

### Data Generation from User Interaction with the System
**Pre-requisites**: A user must be logged in to the system and have chosen a scene to run.<br/>
**Actor**: Student.<br/>
**Use Case Successful Post-Conditions**: Data has been successfully written into a CSV file for future analysis and the user is taken back to the scene selection UI<br/>

1. The user would start running the scene by interacting with the **start/stop** button.
	* The user decides to exit the scene by interacting with **start/stop** button.
2. The moment the user initiates the scene, the back-end would instantly trigger the capturing of data.
3. The back-end would be translating the data from the sensors while simultaneously parsing and appending the data to the CSV file associated with the user and the current date.
	* If the file for the user does not exist, the back-end will first create the file for the user based on the user name and the current date. Then the translation of the data from the sensors would occur while simultaneously parsing and appending the data to the new CSV file.
4. The user decides to stop the scene by interacting with the **start/end** button. This would instantly trigger the back-end to stop the translation of the data as well as the parsing and appending to the CSV file.
	* The user continues to interact with the scene allowing the system to continue to gather data until the user decides to complete step #4.
5. Data has been successfully written to the CSV file and the user is brought back to the scene selection UI.
