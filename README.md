## Robot-C Autonomous OS

This code outlines the framework and functions for robot control and operations in an autonomous environment.

----------
### Theory

The operating system works by breaking down tasks into functions. These include `turnRight()`, `moveForward()`, `clawOpen()`, etc. and they simplify the code. These methods will alter the states of the motors on the robot indefinitely, until the motors are reset to their original states.

Overloaded methods of these core functions will change the states of the motors, but only for a definite amount of time. Calculations are performed in the methods and the `reset()` call is not needed.

### Core Usage

The basic functions are:
-   `moveForward()`
-   `moveBackward()`
-   `turnRight()`
-   `turnLeft()`
-   `armUp()`
-   `armDown()`
-   `clawOpen()`
-   `clawClose()`