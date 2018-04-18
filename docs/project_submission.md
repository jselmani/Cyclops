### Team #: 14

### Brief Overview of System
A desktop application which utilizes the Oculus Rift hardware and Oculus Rift SDK with a custom-designed GUI that extracts telemetry data
and writes to  `.csv` files to be used for analysis and research purposes.  
The specific telemetry data that is extracted in this application include:
* Angular Acceleration
* Angular Velocity
* Linear Acceleration
* Linear Velocity
* Orientation
    * Yaw
    * Pitch
    * Roll

Overall, the purpose of this application is to provide VR developers the opportunity to understand user movement when engaged in the simulation.
Due to the ability to timestamp the data being written to telemetry files, game developers can record their VR sessions to better understand the intensity,
stimulus, and correlation between the telemetry data and the VR game/simulation.

### Differences between Planned and Actual
Originally, the application was intended to have the features listed below.
 * User/Administrator login portal
 * Database to store the telemetry data
 * The ability to start the Unity VR simulation upon initializing the headset
 * Encapsulating all functionality into a DLL to ensure portability of the application

The above functionality was ignored as there was not enough time to learn the Oculus SDK, Hardware Integration, Unity Game Engine, and the MFC framework (GUI) within the duration of the project.
Also our client, Dr. Elliott Coleshill, emphasized that the above functionality was not required for his research.  Therefore, the final product resulted in the following implementation:
 * C++ Extractor Code that utilizes the Oculus SDK
 * MFC Graphical User Interface that allows users to interact with the Extractor Code
 * Local storage of Telemetry data and Configuration files
     * The Configuration file save path (if not previously created) is assigned by the user.
     * The Telemetry file(s) save path is assigned by the user with the following structure:
         1. If no files have been written to this path, a directory will be created with this format:
             * `(ISO-Date)-(Oculus Rift HMD Serial Number)\`
         2. If files have been written to this path on the date, the file will be written into the directory that was created previously with the following structure:
             * `HH-MM-SS-MS`

### Deployment
As the application is production ready, our intention is to host the source code on GitHub to make it open to other developers that would like to work on the project and improve it.  There are other points of telemetry data that can be extracted and it would be great to see the project become a trending open source project on GitHub.  Cyclops will be deployed on the Oculus Home Play Store, where developers can download the `Cyclops.exe` directly onto their machines and be able to utilize the application when playing a VR game or developing their own.  Since Cyclops does not require external storage, the only hosting required will be what will be posted on GitHub and on the Oculus Home Play Store.

### Limitations
One of our biggest fears are the Oculus Home Play Store's heavy guidelines for deployment on their platform.  Since the application is not a VR game or simulation but rather a developer tool, it might be rejected and ineligible for deployment.  No other foreseeable limitations exist as the executable itself is capable of running on all Windows platforms simply by downloading it from GitHub.

### Learning
#### Business and Functions of Use
Being a research based project, our project would support VR researchers into understanding how to make better simulations that are comfortable for their users as well as learn new ways to utilize the capabilities of the hardware.  Working with our client (Dr. Coleshill) gave us insight into how the understanding of a technology is just as important in writing code and documentation that supports it.  Without understanding his needs, our group would not have known where to start this project.

#### Technologies We Used
The most critical part of our project lied in the technology we used.  Working with third party software, like the Oculus SDK, was difficult to understand at first.  With thousands of lines of code and different components to be used, the initial task of learning how to integrate the SDK into our project was daunting.  Reading code and documentation was an excellent experience as that is what afforded our team the opportunity to accomplish our challenge.  Essentially, trial and error was the only way we could make this project work.  We also had to utilize the MFC framework to design our graphical user interface that migrated the backend code of our application with user-friendly visuals and functionality.  Integrating the backend with the frontend in C++ is not easy and this was a very proud achievement for our team.  Lastly, building and generating a VR experience to test our software with was enlightening.  It was an opportunity that was a lot of fun where we worked with 3D objects, Level Design, Audio Integration, Scale, and both free and paid assets.  Using the Unity Game Engine was a steep learning curve but the final product for this project was a beautiful simulation for others to enjoy.

#### The Overall Experience
As is group work, our team had its fair share of disagreements and miscommunication; a precursor to what life is like in industry.  However, we overcame our challenges as a team by successfully talking things through (sometimes arguing) and compromising with one another's ideas.  Running and managing a product from start to finish is a difficult task as so much more than just writing code is necessary.  We must establish requirements, discover the main priorities of our client, determine the appropriate features to be deployed, and most importantly (and most difficult), is having to delete features that do not fit the scope of our project.  Software Development is not an overnight process and this project and experience allowed us to realize the process that is undertaken to go from concept to deployable product.
