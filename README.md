# Bank-Simulator

This repository contains C++ files for a bank simulation program, developed by Will Porter.
The program simulates customer arrivals and service at a bank, tracking various statistics such as the number of customers served, average wait times, and teller performance.

Files Included:
Bank_Simulator.h: Header file containing the declaration of the Simulator class, which manages the bank simulation.
Bank_Simulator.cpp: Implementation file for the Simulator class, defining methods for running the simulation and outputting statistics.
Customer.h: Header file for the Customer class, representing bank customers and their attributes.
Customer.cpp: Implementation file for the Customer class, including methods for calculating delay times and service times.
Teller.h: Header file for the Teller class, representing bank tellers and their status during the simulation.
Teller.cpp: Implementation file for the Teller class, containing methods for starting and ending service.
Random.h: Header file for the Random class, used for generating random numbers in the simulation.
newCxxTest.h: Header file for unit tests using the CxxTest framework, validating various functionalities of the simulation classes.

Usage:
To use the bank simulation program, include the necessary header files and source files in your C++ project.
Instantiate the Simulator class, set the number of tellers, and run the simulation by calling the run_simulation method with appropriate parameters.

Compilation:
Compile the source files using a C++ compiler. For example:
g++ Bank_Simulator.cpp Customer.cpp Teller.cpp Random.cpp newCxxTest.cpp -o Bank_Simulator

Running Tests:
The unit tests for the simulation can be executed using the CxxTest framework. Compile the test file along with the source files and run the executable. For example:
g++ Bank_Simulator.cpp Customer.cpp Teller.cpp Random.cpp newCxxTest.cpp -o Test_Bank_Simulator
./Test_Bank_Simulator

Note:
The program contains unit tests to validate the correctness of the simulation classes. These tests ensure that the simulation behaves as expected under different scenarios.
The simulation logic is based on random arrivals and service times, providing a stochastic model of a bank system.
Feel free to explore the source code, run the simulation, and modify it as needed for your specific use case.
If you encounter any issues or have questions, please refer to the comments in the source code or contact the original developer, Will Porter.
