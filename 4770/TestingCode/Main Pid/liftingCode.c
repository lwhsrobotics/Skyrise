#include "pid.c"
#include "DriveControler.c"
#include "AutonomusSelc.c"
#include "AutonomusCode.c"

void lift() {
		//SPARE LIFT CODE
bMotorReflected[port8] = true;
bMotorReflected[port5] = true;
if(vexRT[Btn5U]) {
			motor[port9] = 127;
			motor[port8] = 127;
			motor[port5] = 127;
			motor[port4] = 127;
			} else if (vexRT[Btn5D]) {
			motor[port9] = -127;
			motor[port8] = -127;
			motor[port5] = -127;
			motor[port4] = -127;
			}
			//TEMP
			else if(vexRT[Btn7R]) {
			motor[port9] = 127;
			motor[port8] = 127;
			} else if (vexRT[Btn7L]) {
			motor[port5] = 127;
			motor[port4] = 127;
			}
			//TEMP
			else {
			motor[port9] = 0;
			motor[port8] = 0;
			motor[port5] = 0;
			motor[port4] = 0;
		}

}

/*
//PID SECTION
void intPid(float Kp,float Ki, float Kd) {

	//lift PID \/
	pidInitState(liftStateRight, Kp, Ki, Kd, 150);
	pidInitState(liftStateLeft, Kp, Ki , Kd, 150);
}
void bootUpPid() {
		//lift control
		pidSetTarget(liftStateLeft, SensorValue[in1]);
		pidSetTarget(liftStateRight, SensorValue[in2]);
}
void lift() {
			// LIFT Up and Down
		if(vexRT[Btn5U]) {
			pidIncrementTarget(liftStateRight, 8);
			pidIncrementTarget(liftStateLeft, 8);
			} else if (vexRT[Btn5D]) {
			pidIncrementTarget(liftStateRight, -8);
			pidIncrementTarget(liftStateLeft, -8);
			} else {
			pidIncrementTarget(liftStateRight, 0);
			pidIncrementTarget(liftStateLeft, 0);
		}
		bMotorReflected[port8] = true;
		bMotorReflected[port5] = true;
		motor[port9] = pid(&liftStateRight,SensorValue[in2],20);
		motor[port8] = pid(&liftStateRight,SensorValue[in2],20);
		motor[port5] = pid(&liftStateLeft,SensorValue[in1],20);
		motor[port4] = pid(&liftStateLeft,SensorValue[in1],20);

}
*/
