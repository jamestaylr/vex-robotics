## Robot-C Autonomous OS

This code outlines the framework and functions for robot control and operations in an autonomous environment.

----------
### Theory

The autonomous code breaks down functions that control the movement of motors in the robot into tasks. During the `main()` method, two tasks are created `drive()` and `manipulator()`. These tasks operate in parallel and `sync()` at after operation segments have been completed. Parallel processing is essential to operation efficiency: we need the robot to run motors in different contexts at the same time.

This code is written in RobotC and will not compile without the program's proprietary compiler.

### Core Usage

The basic functions are:
-   `moveForward(int distance)`
-   `moveBackward(int distance)`
-   `turnRight(int angle)`
-   `turnLeft(int angle)`
-   `arm(int height)`
-   `clawOpen()`
-   `clawClose()`

> Note: to test this code, the `#pragma` configurations would have to be redefined in the code's header.