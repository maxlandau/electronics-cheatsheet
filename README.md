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

**-Gain to dB**

**-Parallel resistance**

**-Series capacitance**

**-Cutoff frequency for high pass or low pass filters**

**-Charge/discharge time for capacitors**

**-Voltage divider**

**-AC/DC conversion**

**-Inductive and capacitive reactance**

## Use

The application functions as a typical console app: options and prompts are printed out and the user types and enters their input to control the program. 

The calculators are designed to parse RKM shorthand from user input such as **".2uF"** as **.0000002** or **"4k7"** as **4700** and inversely will abbreviate on output for ease of use and readability. It will convert decimals down to milli, micro, nano, pico depending on the unit, or abbreviate large numbers up to kilo, mega, giga. 

To use this calculator for macOS, simply download the Mac executable in the macOS folder and run it. For Windows, download this project and build from the two source files **"main.c"** and **"emaths.h"**. An icon for the executable is included in the resources file. 

The **emaths.h** function header file may also be used/tweaked to expand on this concept for other electronics applications. 
