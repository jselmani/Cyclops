# Oculus Data Extractor
A small (for now), ongoing project to extract MEMS data from the Oculus Rift CV1 and its relevancy to simulation training in a variety of industries/fields.

### Getting Started

Before going any further, please ensure that you have the following hardware plugged in to your for your machine:  
1. Oculus Rift Headset
2. Oculus Sensor

It isn't entirely necessary, but it gets you up and running quickly.

Once setup is complete, getting started is easy, simply clone the repo onto your local machine and import the file into your text editor or IDE. Also, if you would like to make changes to the code to improve it, please fork it. In order for this program to run correctly, you will need to do some configuration to your build environment.  If you don't have it already, you should download the [Oculus SDK](https://developer.oculus.com/downloads/package/oculus-sdk-for-windows/) for Windows.  The version in this project is currently 1.18.0.

Performing this work in Visual Studio 2015 myself, a link to the LibOVR library must be established for the project to compile and build.  Below is a picture for reference.

##### Linker Input (LibOVR)
![LinkerInput](https://github.com/jselmani/OculusDataExtractor/blob/master/Images/LinkerLibOVR.PNG)

You will also need to import the Oculus SDK libraries into the project as well in order to access the Rift itself.  With everything established, simply compile and run the program and have your headset at the ready, preferably on your head and in range of the sensor.  You will immediately begin to see the data being printed in the console.  Below is an image of sample output.

#### Sample Output
![SampleOutput](https://github.com/jselmani/OculusDataExtractor/blob/master/Images/SampleOutput.PNG)

### Issues

Should you discover that the project has discrepancies, please do not hesitate to reach out to me or file an issue.  

Thank you in advance,
Jiel
