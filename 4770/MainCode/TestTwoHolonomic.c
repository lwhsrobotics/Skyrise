
task main()
{
	while(true) {
		bMotorReflected[port2] = true;
		bMotorReflected[port3] = true;
motor[port1] = vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];
motor[port10] =  vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
motor[port3] = vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
motor[port2] =  vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
}

}
