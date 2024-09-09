# Electronics Cheatsheet

## Description

A simple yet useful console app with a collection of commonly needed electronics calculators.
Designed with audio electronics design and analysis in mind.

## Technical

Written in C. 

This project contains one main .c file and one .h header file with all relevant math functions included. 

No GUI -- this is a classic console app.

## Included Calculators

**-Ohm's Law**

**-Voltage gain to dB**

**-Parallel resistance**

**-Series capacitance**

**-Cutoff frequency for high pass or low pass filters**

**-Charge/discharge time for capacitors**

**-Voltage divider**

**-AC/DC conversion**

**-Inductive and capacitive reactance**

## Use

The executables for MacOS and Windows are in their respectively named folders. Simply download the correct one for your operating system. For MacOS, the executable is compressed in a zip file to preserve it's identity as an Unix executable otherwise GitHub breaks it. Just unzip it after downloading to run. For Windows, the .exe file is ready to go. 

You can also download this project and build it yourself.

The application functions as a typical console app: options and prompts are printed out and the user types and enters their input to control the program. 

The calculators are designed to parse RKM shorthand from user input such as **".2uF"** as **.0000002** or **"4k7"** as **4700** and inversely will abbreviate on output for ease of use and readability. It will convert decimals down to milli, micro, nano, or abbreviate large numbers up to kilo, mega, giga, depending on the unit.

The **emaths.h** function header file may also be used/tweaked independently to expand on this concept for other electronics applications. 
