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
Virtual reality technology is relatively new and our group has never worked with the technology before.  Therefore, we will be maintaining a relatively lower level of complexity in order to ensure project completion.  Our task is to generate a series of components to meet the requirements of the research project.  These components consist of customized scenes (the VR and desktop environments) such as the user interface and the cockpit (preferably a Static Cockpit) which would be designed and implemented using Unity's Game Engine, a Database to store data (User, Sensor Data, Timestamp), and software that will extract accelerometer and gyroscope data from the VR Headset and its peripheral device.

In order to aid Dr. Coleshill in his research, he requires technology that can process sensor information in real-time.  By doing so, he will be able to understand what and where the User is looking at, and how often.  With vast amounts of data being stored, it can be extracted for review where Dr. Coleshill can establish patterns in the flight and analyze the data accordingly on a per user basis.

To cut down on development time, each group member will be tasked on working on a particular portion of the project to lighten the workload.  Should any group members become overwhelmed, it is agreed upon that aid will be provided from group members and our client as well.  Our project has several requirements, and are as follows.

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
* A Database will be designed and built in order to store and retrieve data, following the rules below:
	* The user passwords will be hashed,
	* The data will only be accessible by an Admin.
	* The Admin login credentials will be basic and unchangeable for simplicity.
	* The database will consist of multiple tables – each table will hold the data of a scene that has been run by a user.
	* Data from the headset technology and its peripherals will be written to a .CSV file and stored into a file system
		* The file will be referenced by the database for extraction, limiting database resources.

#### The Scene Requirements
* The scene will be generated by the Unity Game Engine.
* In order to benefit Dr. Coleshill's research, it will be mocked to a cockpit of some kind, either a plane or a spaceship for added fun.
* Initially, we plan on designing and working with a static scene.
	* Depending on how fast the development progresses, we will implement a dynamic scene that incorporates movement within the scene.

#### The VR Sensor Extraction Requirements
* The client has requested that the extracted data is in real-time. We have two methods to bring this to fruition.
	* The data extracted will be time stamped in order for the admin to be able to analyze the data efficiently
	* The data will be written to a .CSV file where the data will be extracted at intervals between 50-200 milliseconds
	* When the data extraction is successful, if the project is near completion and time permits we may attempt to give a visual representation of the data within:
		* The Oculus Rift display and/or
		* The desktop environment - this would only be accessible to an admin so they may analyze the data as it is being written.
* The Oculus Rift Headset and its peripheral technology uses C++ in it's SDK.
	* The software to extract the accelerometer and gyroscope data must be written in C++.

#### Logical Requirements
* Only users that are authenticated by an Admin will be allowed access to the Desktop UI or the VR Headset’s UI.
	* A login section will be available on the Desktop UI
* Depending on the type of login (regular user or admin), the UI will be slightly different.
	* Once an admin is logged in they will be able to:
		* Register a new user.
	* A regular user would be able to:
		* Chose the type of scene they would like to use, in the VR Headset UI and/or in the Desktop UI.
		* Once a scene is chosen, data will be written to the database based on the movement of the VR Headset and its peripheral device.
		* For a user to end the scene, there should be a button dedicated on the peripheral device that the user may press (so the transmission of data will be cutoff) or a button will be implemented within the UI that has the same effect.
	* In order to completely end the session, the admin/user must logoff.


## Technical Overview

This project consists of several components including the **front-end interfaces** for the students and administrator to access and perform the use cases, a **back-end (database)** component to store the extracted data from the Oculus Rift and its peripheral technology.  The **hosting** of the database will be local to the administrators machine.

In this technical overview, we will list these components and their requirements, and discuss the technologies and their uses in order to run the program smoothly.

### Components and Requirements

#### The Oculus Rift
* Components of the Rift:
	* OLED panel for each eye – resolution of 1080×1200 with refresh rate of 90 Hz each panel.
	* Integrated 3D Headphones.
	* Accelerometer
	* Gyroscope
	* Constellation – the positional tracking system
		* Tracks the position of the user's head as well as the position of the peripheral device (Touch Controller)
	* Oculus Touch (Touch Controllers) – pair of handheld motion controllers
* Software Packaged with the Rift:
	* Oculus Home – base software of the rift which starts VR applications
	* Oculus PC SDK - written in C++
	* Oculus Runtime/Drivers - the runtime and drivers must be installed in order for the rift to function.


#### Desktop/Laptop PC
* Minimum Requirements:
	* Graphics Card – NVIDIA GTX 960 / AMD Radeon R9 290 or greater
	* CPU – Intel i3-6100 / AMD Ryzen 3 1200, FX4350 or greater
	* RAM – 8GB or greater
	* HDMI – version 1.3
	* USB 3.0 – 1 Port
	* USB 2.0 – 2 Ports
	* Operating System – Windows 8.1 or newer


#### Database
* MongoDB (NoSQL)
	* MongoDB must be installed on the local machine and will be configured using the Unity MongoDB driver for C#.

#### Unity Game Engine
* General Documentation:
	* Unity is a cross-platform game engine developed by UnityTechnologies.
	* Unity is primarily used to develop video games and simulations.
	* Unity scripting is written in C#.
* System Requirements:
	* Graphics Card – DX9 or DX11 enabled graphics
	* Operating System –
		* Windows 7 or newer
		* Mac OS X 10.8 or newer

#### Additional Software
* The Oculus Rift data will be retrieved by a program written in C++.
	* This program well then write the data to a .CSV file that will be stored in a file system and referenced by the database.

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

#### Back-End/Database System

The back-end of the project will consist of a C++ console application that will extract the sensor data from the Oculus Rift and its peripherals, as well as the MongoDB database that will be hosted locally in the administrators machine.  We have chosen to use C++ and MongoDB for the following reasons:
* Oculus SDK
  * The SDK is written in C++ and it is imperative that we use C++ in order to extract the sensory data.
  * The C++ application is lightweight and can be started in the background once the user has logged in and has been validated in the Unity user interface.
    * This will occur using the Process object in the Unity game engine.
* Lightweight Database Engine
  * The MongoDB database engine is lightweight and easy to integrate with C#, utilizing drivers to allow Unity integration.
  * Data structuring uses JSON/BSON notation, making it a simpler alternative to MySQL or SQLite
  * Querying in MongoDB uses simpler syntax with less restrictions, making it more error-free than the alternatives.

  The beauty of the back-end is that the front-end will utilize it when required using Unity's Process object.  By doing so, the C++ application executable will run when called upon by Unity, and the MongoDB database can be opened and operating when the Unity application is opened.

## Use Cases

### Administrator Creates A New User Account
**Pre-requisites**: The administrator already has all the new user information and is currently logged in.</br>
**Actor**: Administrator.</br>
**Use Case Successful Post-Conditions**: The administrator creates a new user account.

1. The administrator clicks on **Create New User**.
2. The system changes its view to display a form to the administrator for him/her to fill up with the new user information.
3. The administrator enters the new user infomation and clicks on the **Create** button inside the form.
	* The administrator can cancel this operation by clicking on the **Cancel** button inside the form, or by clicking the
	**Back** button. By clicking on the **Cancel** button the form will be cleared, instead, by clicking on the **Back**
	button the Administrator will be taken back to the main dashboard.
4. The system checks the validity of the provided user information and creates a new user account if the form is valid.
	* The system will display an error on the screen next to field where the error occured. The administrator can enter the field again.
5. After successfully creating a new user, the system will display a pop-up message informing the administrator about the successful operation and the form will be cleared.

### User Login
**Pre-requisites**: The User has an account in the system and the program is running.</br>
**Actor**: Student/Admininstrator/Instructor.</br>
**Use Case Successful Post-Conditions**: The user is authenticated by the system.</br>

1. The student clicks on **Login**.
2. The System brings up a model for the user to enter his/her credentials.
3. The user enters his/her credentials (username and password) and clicks on the **Login** button inside the model.
	* The user can cancel this operation by clicking on the **cancel** button inside the model.
4. The system will query the database and compare the credentials provided by the user. If a match is found, then the system will authenticate the user.
	* The system sends an error message in case authentication fails. The user can enter his/her credentials again.
5. After the system successfully authenticates the user, they are redirected to a menu page displaying a list of options for flight training simulations.

### Administrator Retrieves Data From File System Database
**Pre-requisites**: The Administrator is logged into the Mongo shell using Administrator credentials<br/>
**Actor**: Administrator<br/>
**Use Case Successful Post-Conditions**: The Administator has found the files path and opens the file.<br/>

1. The Administrator **queries** the database to locate the session they are looking for.  This will be done by using the Users Student Number as the unique identifier and the date the session took place. An example of the query: db.sessions.find({ userId: '101101152', created_at: '20170115'})
2. The Administrator examines the database BSON output and finds the URL path that is referenced in the BSON document.
3. The Administrator copies the URL path from the console and pastes in the file system address bar.
4. The Administrator successfully locates the file and examines the data as preferred using their preferred data visualization method.
