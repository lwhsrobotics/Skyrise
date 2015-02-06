
task main()
{
	bMotorReflected[port2] = true;
	while(true) {
	motor[port1] = vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4]; //back left
	motor[port10] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4]; //front left
	motor[port3] = vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];  //back right
	motor[port2] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4]; //front right
}

}
