#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Auton Middle Level
//drive functions
//drive forward
void driveForward(int time){
	driveForwardPID(1000);
	waitFunc(time);
	driveStop();
}


//Auton High Level
void auton(){
	wait1Msec(100);
}
