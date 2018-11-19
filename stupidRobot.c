#pragma config(Motor,  port3,           left1,         tmotorVex393HighSpeed_MC29, PIDControl, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port4,           left2,         tmotorVex393HighSpeed_MC29, PIDControl, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port5,           left3,         tmotorVex393HighSpeed_MC29, PIDControl, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port6,           right1,        tmotorVex393HighSpeed_MC29, PIDControl, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port7,           right2,        tmotorVex393HighSpeed_MC29, PIDControl, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port8,           right3,        tmotorVex393HighSpeed_MC29, openLoop)

task main(){
	motor[right2]= 127;
	motor[right3]= 127;
	motor[left1] = 127;
	motor[left2] = 127;
	motor[left3] = 127;
	motor[right1]= 127;
	while(true){
		wait1Msec(100);
	}
}
