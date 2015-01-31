#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  LeftDriveEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  RightDriveEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  RightArmEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           rightDriveMotor,    tmotorVex393HighSpeed_MC29, openLoop, reversed,encoderPort, I2C_2)
#pragma config(Motor,  port6,           rightArmMotor,     tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port7,           leftArmMotor,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           clawMotor,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           leftDriveMotor,     tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* ---------------------------------------------------------------------------
 ** small-autonomous.c
 ** Skeleton class for the autonomous code.
 **
 ** Author: James Taylor & Keith Tiemann
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

int SERVO_SPEED = 63;


void setup() {
	nMotorEncoder[leftDriveMotor] = 0;
	nMotorEncoder[rightDriveMotor] = 0;

	nMotorEncoder[rightArmMotor] = 0;

	motor[rightDriveMotor] = 0;
	motor[leftDriveMotor] = 0;
}

void wait(int seconds) {
	wait1Msec(seconds * 1000);
}

// ~ Driving Definitions ......................................................

void turn(int angle) // Rotational Movement. Postive angles turn left while negative angles turn right.
{
	// Write a conversion equation for the angle to distance. This is so the code for move() can still be used. Current one is temporary
	int distance = angle;

	if (angle < 0) {

		move(SERVO_SPEED, -SERVO_SPEED, -distance);
	} else {
		move(-SERVO_SPEED, SERVO_SPEED, distance);
	}
}

void moveForward(int distance) {

	move(SERVO_SPEED, SERVO_SPEED, distance);
}

void moveBackward(int distance) {

	move(-SERVO_SPEED, -SERVO_SPEED, distance);
}

void move(int rightDrive, int leftDrive int distance) {

	nMotorEncoder[leftDriveMotor] = 0;
	nMotorEncoder[rightDriveMotor] = 0;

	encodistance = distance; // Write a conversion equation for the distance to encoder values, current one is temporary
	while (abs(nMotorEncoder[leftDriveMotor]) < encodistance)
	{
		motor[rightDriveMotor] = rightDrive;
		motor[leftDriveMotor] = leftDrive;
	}

	motor[rightDriveMotor] = 0;
	motor[leftDriveMotor] = 0;
}

// ~ Lift Definitions .........................................................

int previous_height;

void arm(int height) {

	if (height > previous_height) {
		arm(SERVO_SPEED, SERVO_SPEED, height - previous_height);
	} else {
		arm(-SERVO_SPEED, -SERVO_SPEED, previous_height - height);
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

	motor[clawMotor] = -SERVO_SPEED;
	wait(2);
	motor[clawMotor] = 0;
}
void clawClose() {

	motor[clawMotor] = SERVO_SPEED;
	wait(2);
	motor[clawMotor] = 0;
}
