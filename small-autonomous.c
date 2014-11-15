#pragma config(Sensor, in1,    LiftPot,        sensorPotentiometer)

#pragma config(Motor,  port2,           rightDriveMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port9,           leftDriveMotor,     tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port6,           liftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port8,           clawMotor,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* ---------------------------------------------------------------------------
 ** small-autonomous.h
 ** Skeleton class for the autonomous code.
 **
 ** Author: James Taylor
 ** -------------------------------------------------------------------------*/

task drive() {
	writeDebugStreamLine("> Started Drive task");
	while (true) {
		wait(5);
	}
}

task manipulator() {
	writeDebugStreamLine("> Started Manipulator task");
	while (true) {
		wait(5);
	}
}

task main() {

	setup();

	writeDebugStreamLine("\n\n>> Beginning Autonomous Subroutine\n");
	StartTask(drive);
	StartTask(manipulator);

	// needed to prevent the main task from terminating
	while (true) {
		wait(5);
	}

}

// ~ Global Definitions .......................................................

void setup() {
	nMotorEncoder[leftDriveMotor] = 0;
	nMotorEncoder[rightArmMotor] = 0;
}

void wait(int seconds) {
	wait1Msec(seconds * 1000);
}

// ~ Driving Definitions ......................................................

void turnRight(int angle) {

	// TODO angle to distance conversion
	move(127, -127, distance);
}

void turnLeft(int angle) {

	// TODO angle to distance conversion
	move(-127, 127, distance);
}

void moveForward(int distance) {

	move(127, 127, distance);
}

void moveBackward(int distance) {

	move(-127, -127, distance);
}

void move(int rightDrive, int leftDrive int distance) {

	nMotorEncoder[leftDriveMotor] = 0;

	while (nMotorEncoder[leftDriveMotor] < distance * 10)
	// TODO the distance conversion goes here
	{
		motor[rightDriveMotor] = rightDrive;
		motor[leftDriveMotor] = leftDrive;
	}

	motor[rightDriveMotor] = 0;
	motor[leftDriveMotor] = 0;
}

// ~ Arm Definitions ..........................................................

int previous_height;

void arm(int height) {

	if (height > previous_height) {
		arm(127, 127, height - previous_height);
	} else {
		arm(-127, -127, previous_height - height);
	}
}

void arm(int rightArm, int leftArm, int delta_height) {

	nMotorEncoder[rightArmMotor] = 0;

	while (nMotorEncoder[rightArmMotor] < delta_height * 10)
	// TODO the distance conversion goes here
	{
		motor[rightArmMotor] = rightArm;
		motor[leftArmMotor] = leftArm;
	}

	motor[rightArmMotor] = 0;
	motor[leftArmMotor] = 0;
}

// ~ Claw Definitions .........................................................

void clawOpen() {

	motor[clawMotor] = -127;
	wait(2);
	motor[clawMotor] = 0;
}
void clawClose() {

	motor[clawMotor] = 127;
	wait(2);
	motor[clawMotor] = 0;
}
