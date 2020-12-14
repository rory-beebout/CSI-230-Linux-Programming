# Final Project - Image Editor
Author: Rory Beebout
For CSI 230

# Overview

The goal of this project was to prototype a simple image editing tool that utilizes the Free Image Library, as well as to create my own shared library. In order to run this program, Free Image libraries must be installed (in their default location, or this project's Makefile must be amended). The FreeImage website can be found here:
https://freeimage.sourceforge.io/index.html

### Install
(Requires FreeImage to run)
To begin, FreeImage must be installed prior to installation. 
FreeImage can be downloaded here:
https://freeimage.sourceforge.io/download.html
Open the project directory in a terminal and use the following command.
It requires root access to create a shared library in /usr/lib/x86_64-linux-gnu. 
```sh
sudo make install
```
### Usage
(Requires FreeImage to run)
When the program is fully installed, it can be used within the terminal. After calling the program, the intended file's to edit should be named in the same command. There can be any number of files to edit, so long as there is more than one. Example command:
```sh
final_driver a.png b.png c.png
```
The program will then bring up a menu of the available options, and will wait for the user to choose an option by typing in the associated number. 

 File 1 of 3
Current File: a.png
Enter number corresponding to desired action
1. Invert and Intensify
2. Convert to Greyscale
3. Horizontal Flip

The program will loop through this screen as many times as the user likes. Once the user enters '0' (zero), the program will ask for the filename to save the modified image as, and will move on to the next file or complete.
It will create a new file with the desired file name.
Note: The desired program appends '.png' to the filename automatically.



When using make run to run the program, it will take arguments from the end of this line in the Makefile
```sh
LD_LIBRARY_PATH=$(pwd)/lib ./$(BIN)/$(EXECUTABLE) a.png x.png w.png
```
a.png, x.png, and w.png are example files that the program will attempt to open for editing.
