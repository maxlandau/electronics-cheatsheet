#ELECTRONICS CHEATSHEET

##Description

A simple yet useful console app with a collection of commonly needed electronics calculators.
Designed with audio electronics design and analysis in mind.

##Technical

Written in C. 

This project contains one main .c file and one .h header file with all relevant math functions included. 

##Use

The calculators are designed to parse RKM shorthand from user input such as ".2uF" as .0000002 or "4k7" as 4700 and inversely will abbreviate on output for ease of use and readability. It will convert decimals down to milli, micro, nano, pico depending on the unit, or abbreviate large numbers up to kilo, mega, giga. 

To use this calculator for macOS, simply download the Mac executable in the macOS folder and run it. For Windows, download this project and build from the two source files "main.c" and "emaths.h". An icon for the executable is included in the resources file. 

##License

Copyright (C) 2024 Maximilian Landau

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
