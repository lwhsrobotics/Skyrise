#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
//#include "AutoSky.c"
//#include "AutoTower.c"


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

	//Clear's LCD Screen
clearLCDLine(0);
clearLCDLine(1);

/*
//SET AUTONOMUS
//Display the Primary Robot battery voltage
displayLCDString(0, 0, "Primary: ");
sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'F'); //Build the value to be displayed
displayNextLCDString(mainBattery);
//Display the Backup battery voltage
displayLCDString(1, 0, "Backup: ");
sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'F');    //Build the value to be displayed
displayNextLCDString(backupBattery);
wait1Msec(100);
*/
// Example: clearing encoders, setting servo positions, ...
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
//SETING AUTONOMUS


/*
//lift
int LeftPot;
int RightPot;
//drive
int FrontLeftPot;
int FrontRightPot;
int BackLeftPot;
int BackRightPot;
*/
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//


/////////////////////////////////////////////////////////////////////////////////////////
task usercontrol() {
	bMotorReflected[port3] = true;
	bMotorReflected[port4] = true;
bLCDBacklight = true;

	while (true) {
clearLCDLine(0);
clearLCDLine(1);

// This is the main execution loop for the user control program. Each time through the loop
		// your program should update motor + servo values based on feedback from the joysticks.

//bMotorReflected[port2] = true;

bMotorReflected[port9] = true;
 		//Holonomic Drive Code \/     \/     \/     \/
motor[port2] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4]; //back left
motor[port9] = vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4]; //front left
motor[port10] = vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];  //back right
motor[port1] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4]; //front right
		// Arm Up and Down
		if(vexRT[Btn5U]) {
		motor[port3] = 127;
		motor[port4] = 127;
		motor[port8] = 127;
		motor[port7] = 127;
		} else if (vexRT[Btn5D]) {
		motor[port3] = 127;
		motor[port4] = -127;
		motor[port8] = -127;
		motor[port7] = -127;
		} else {
		motor[port3] = 0;
		motor[port4] = 0;
		motor[port8] = 0;
		motor[port7] = 0;
		}
		//INTAKE
			if(vexRT[Btn6U]) {
			motor[port5] = 127;
		} else if (vexRT[Btn6D]) {
		motor[port5] = -127;
		} else {
		motor[port5] = 0;
		}

		/*
		//Claw
		if (vexRT[Btn8U]) {
			motor[port5] = 127;
			motor[port6] = 127;
		} else if (vexRT[Btn8D]) {
			motor[port5] = -127;
			motor[port6] = -127;
		} else {
			motor[port5] = 0;
			motor[port6] = 0;
		}
*/
		wait1Msec(20);
	}
}
