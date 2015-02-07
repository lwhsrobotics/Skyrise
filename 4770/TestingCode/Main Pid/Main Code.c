#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  SkyClaw,        sensorDigitalOut)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port3,            ,             tmotorVex393, openLoop, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port4,           liftRightOne,  tmotorVex393, openLoop)
#pragma config(Motor,  port5,           liftRightTwo,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           liftLeftOne,   tmotorVex393, openLoop)
#pragma config(Motor,  port9,           liftLeftTwo,   tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "pid.c"
#include "DriveControler.c"
#include "AutonomusSelc.c"
#include "AutonomusCode.c"
#include "liftingCode.c"
int AutoMode;
	int LeftLift = SensorValue[in1];//for LCD
	int RightLift = SensorValue[in2];//for LCD
//Drive Sensors
int rightBackEncoder = SensorValue[I2C_1];
int leftBackEncoder = SensorValue[I2C_2];
int rightFrontEncoder = SensorValue[I2C_3];
int leftFrontEncoder = SensorValue[I2C_4];
PidState liftStateRight;
PidState liftStateLeft;
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
void pre_auton() {
	bStopTasksBetweenModes = true;
	//drive sensors
	rightBackEncoder = SensorValue[in3];
	leftBackEncoder = SensorValue[in4];
	rightFrontEncoder = SensorValue[in5];
	leftFrontEncoder = SensorValue[in5];

	//lift PID \/
	pidInitState(liftStateRight, 0.5, 0.3, 3.0, 150);
	pidInitState(liftStateLeft, 0.5, 0.3, 3.0, 150);
	//Clear Encoders (Check Drive Controler for more information)
	ClearEncoders();
	//Clear's LCD Screen
	clearLCDLine(0);
	clearLCDLine(1);

	//AutoMode = AutoSelc(); FIX ME

}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
task autonomous() {
	AutoSky();
	/*
	//SETING AUTONOMUS
	if(AutoMode == 0) {
	AutoSky(); 	//Runs Skyrise Autonomus
	}
	else if(AutoMode == 1) {
	AutoCube();	//Runs Cube Autonomus
	}
	else if(AutoMode == 2) {
	//Do Nothing AKA ERROR
	}
	else {
	//Do Nothing
	}
	*/
}
int potLeft;
int potRight;
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//


/////////////////////////////////////////////////////////////////////////////////////////
task usercontrol() {
	//bLCDBacklight = true;
	string mainBattery = "";
	string backupBattery = "";
	bool Claw = false;
	potLeft = SensorValue[in1];
	potRight = SensorValue[in2];
//lift control
		pidSetTarget(liftStateLeft, SensorValue[in1]);
		pidSetTarget(liftStateRight, SensorValue[in2]);
	while (true) {
		RightLift = SensorValue[in2];//for LCD
		LeftLift = SensorValue[in1];//for LCD
		//RightLift = RightL;
		//LeftLift = LeftL;
		//Clear Screen
		clearLCDLine(0);
		clearLCDLine(1);
		/*
		//Battery Levels  c
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'F'); //Build the value to be displayed
		displayNextLCDString(mainBattery);
		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'F');    //Build the value to be displayed
		displayNextLCDString(backupBattery);
		*/
		displayLCDString(0, 0, "Left:");
		displayNextLCDNumber(LeftLift);
		displayLCDString(1, 0, "Right:");
		displayNextLCDNumber(RightLift);
		drive(false);

		/*	//Drive
		pidSetTarget(driveStateLeftFront, SensorValue[in3]);
		pidSetTarget(driveStateRightFront, SensorValue[in4]);
		pidSetTarget(driveStateLeftBack, SensorValue[in5]);
		pidSetTarget(driveStateRightBack, SensorValue[in6]);
		*/
		//Skyrise Intake
		if(vexRT[Btn8U]) {
			Claw = true;
		}
		if(vexRT[Btn8R]) {
			Claw = false;
		}
		if(Claw == true) {
			SensorValue[SkyClaw] = 1;
		}
		else {
			SensorValue[SkyClaw] = 0;
		}
		//Cube Intake
		if(vexRT[Btn6U]) {
			motor[port7] = 127;
			} else if (vexRT[Btn6D]) {
			motor[port7] = -127;
			} else {
			motor[port7] = 0;
		}

		// LIFT Up and Down
		if(vexRT[Btn5U]) {
			pidIncrementTarget(liftStateRight, 4);
			pidIncrementTarget(liftStateLeft, 4);
			} else if (vexRT[Btn5D]) {
			pidIncrementTarget(liftStateRight,-4);
			pidIncrementTarget(liftStateLeft, -4);
			} else {
			pidIncrementTarget(liftStateRight, 0);
			pidIncrementTarget(liftStateLeft, 0);
	}

		bMotorReflected[port8] = true;
		bMotorReflected[port5] = true;
		motor[port9] = pid(liftStateRight,SensorValue[in2],15);
		motor[port8] = pid(liftStateRight,SensorValue[in2],15);
		motor[port5] = pid(liftStateLeft,SensorValue[in1],15);
		motor[port4] = pid(liftStateLeft,SensorValue[in1],15);

		wait1Msec(15);
	}
}
