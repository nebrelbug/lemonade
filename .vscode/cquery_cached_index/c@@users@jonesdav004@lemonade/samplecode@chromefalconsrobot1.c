#pragma config(Motor,  port1,           left1,         tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           left2,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           right1,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           right2,        tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true) {
		motor[port1]=vexRT[Ch3];
		motor[port2]=vexRT[Ch3];
		motor[port3]=vexRT[Ch2];
		motor[port4]=vexRT[Ch2];
	}

}