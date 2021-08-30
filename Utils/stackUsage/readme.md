# Stack Usage Test Framework


## Overview
This document explains the design of the StackUsage Test Framework. This Framework allows the user to examine the stack usage of a given function with given parameters. In this document we will show the usage of this framework, how to create your own test and run it.

## Algorithm
The test paints the stack with defined memory pattern (DEADFACE) XORed with index values which are ranged between 0 – 255 (index%256) and then calls the target function (which we are testing) and checks how many bytes were changed in the stack. In this way the user knows the maximal stack usage of the target function - for given arguments. The following is an exact step-by-step explanation of the algorithm:
1. Allocate on stack array with size of 32 bytes (size is arbitrary). This array will be used as the base address to start from while checking for modifications on the stack.
2. Initiate this array with one value = 0xBE.
3.  Call paintStack() – This function will allocate new array on the stack with size of 3Kbytes (This size is configurable and may be different in different OSs and platforms) and initiate it with mentioned memory pattern XORed with index values in range: 0 - 255.
 

| EA,A0,FA,22,DE |
| -------------- |
| BC,1F,4C,08,40 |
| FF,AC,54,05,E6 |
| Function call: paintStack |
| BE, BE, BE,…..,BE |



4. Call the target function, at the end of function the distance from the last 0xBE and the first unchanged byte according to the pattern is the actual maximal stack size used by the function (see Limitations section).
5. In a loop starting in the address of the second array (step 3) up to the end, find the first modified byte and calculate how many bytes were modified in the second array .
6. In a loop, count the bytes right after the second array to the beginning of the first array.
7. Return the count of the modified bytes according to step 5 and step 6.

## Implementation
The test framework was designed to be generated from four parts:
* [Template C file.](./TestSuite/Template/template.c)
* [Text file – TeargetFunctions.txt.](./TestSuite/TargetFunctions.txt)
* [Python script.](./TestSuite/TestsGenarator.py)
* [Makefile.](./TestSuite/Makefile)
Each part is necessary for the test generation; in the following section they will be explained.

## Template C File
This file implements the algorithm described above. Since it is a template, there are instances of the TEMPLATE word which is used to tell the python script how to process these sections.

## Text File (TargetFunctions.txt)
The text file contains the list of the function calls that the user wants to test for Stack Usage. The user MUST supply include files, variables declarations, test function name and the target function call, for example:
foo.h $ StackUsage_foo $ int a = 5; int b = 6; int c = 0 $ c = foo(a, a+b);
INCLUDES $ TEST FUNCTION NAME $ VARIABLES DECLARATION $ ACTUAL CALL
Between each inputs (includes and variables for example) the syntax requires $ separation. "stdio.h" and "stdlib.h" are already included in the generated files – no need to include them. At the end of the Text file the line "List Finished!" MUST appear to tell the python script that the text file EOF.

**Notes:**
1. If there are no variables, the user can make it an empty field denoted by one space.
2. In order to mark a line for the python to ignore, user should add '#' in the beginning.

## Python Script (TestsGenerator.py)
The python script reads the "Template C File" and the "Text File" and generates new files:
* functionsVector.h
* functionsVector.c
* TestSuiteRunner.h
* TestSuiteRunner.c


The script creates new C file **functionsVector.c**; this file contains the implementations of the test functions which will create the vector later.
Each function is generated from the template function with the relevant modifications in the template lines, the modifications is taken from the text file according to what the user inserted in it.
When the script read the "List Finished!" it will add the implementation of the "paintStack()" function – (see step 3 in the algorithm).
The next generated file is the **functionsVector.h**; this file contains:
* struct definition "functionNode":
* An array of this struct, the size of the array is defined in the header file.
* Declarations for the implemented functions in the C file.
* Definition of a constant "STACK_SIZE" which used to set the sizes of the arrays in the test function and the "paintStack()".
* Definition of the memory pattern and its size.
* Definition of magic numbers used in the template and in the paintStack().

The next generated file is the **TestSuiteRunner.c**; this file contains an implementation of **TestSuiteRunner()**, this function has a loop which goes over the array defined in the **functionsVector.h** and calls the test functions using the function pointer and prints the result.
The next generated file is the **TestSuiteRunner.h**; this file contains a declaration for the **TestSuiteRunner()**.

## Makefile
The make file contains basic code, it contains several flags that the user can define:
* CFLAGS: C flags to be defined if necessary.
* CC: The compiler, for default the compiler is the native "gcc".

## Limitations
There is one limitation in this solution, in order to fill the stack with two different patterns and let them be modified, we need to call function "paintStack()" which allocates an array on the stack and initiates it and return.
This call exploits the stack and the second array will be allocated in distance of 8 bytes may be different in different platforms and OSs from the first array. So the accuracy of this algorithm is for functions which uses 8 bytes or greater.

## Run Tests and Output
In order to use this test framework, user should do the following steps:
1. Check-out the PAL branch This should be changed for the new GIT branch: https://github.com/ARMmbed/mbed-client-pal. Under "Utils/stackUsage/TestSuite/" there are:
* Template Folder – contains the template.c file.
* Makefile
* TargetFunctoins.txt
* TestsGenerator.py
2. Edit the TargetFunctions.txt file and add new tests lines.
3. Call the python script to generate the tests. The generated files will be in new folder called "Tests".
4. Call Makefile to compile the sources. – the output is "./Tests/TestRunner".
5. Run the tests by calling : "TestRunner".
