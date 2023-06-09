"Oscillatory radii simulator"


This code is in public domain. If it is used for scientific elaborations, academic articles or other types of publications, We kindly ask that the repository be cited.


Introduction:

This software is meant to simulate the dynamic of circular particles with oscillating radii.

The particles moves towards a target and interact with each other and the container via contact forces. 

It is focused in particles exiting a container with an opening, so the main output is the times when each particle exit, but it also provides the position of every particle with certain periodicity. Those outputs are saved on a dedicated folder for each configuration used. 



Installation:

Compile the file "Room.cpp" using g++:
"g++ Room.cpp -o Room.exe"
Room.exe is the binary file you will be using. 



How to use:
In order to run simulations, you need a configuration file where you specify the parameters. There is also a python script (ejecutar.py) that reads and call the binary file with the selected parameters.
There is an example config file in the "Example" folder. You have to use that format in your config files. 



Conceptualization:

Daniel R. Parisi
Code: Lucas E. Wiebke

