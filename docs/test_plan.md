# Test Plan
## Extracting Data

Thee following tests will be conducted in order to test the extraction of data from the Oculus Rift headset. Please see the wiki page [here](https://github.com/jselmani/cyclops/wiki/Test-Cases) to consult with different test cases.

| Number | Action | Output |
|--------|--------|--------|
|   1    | The user starts program and initializes HMD. | The system lets user know that HMD is initialized and that test user can put it on. |
|   2    | The user wants to check if file has been opened. | The system lets user know that a file has been opened successfully. |
|   3    | The file nears file size limit | The system lets user know that a new file is opened and will be written to once current file reaches designated file limit. |
|   4    | The user wants to check if file has been closed. | The system lets user know that the file has reached it's limit and has been closed successfully. |
|   5    | The user would like to end the simulation. | The system lets user know that the HMD's session has been ended and that the test user can remove it. |
