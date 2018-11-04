#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Auton Middle Level
//drive functions
//drive forward
void driveForward(int time){
	driveFunc(127,127);
	waitFunc(time);
	driveStop();
}

//drive back
void driveBack(int time){
	driveFunc(-127,-127);
	waitFunc(time);
	driveStop();
}

//turn left
void driveTurnLeft(int time){
	driveFunc(-127,127);
	waitFunc(time);
	driveStop();
}

//turn right
void driveTurnRight(int time){
	driveFunc(127,-127);
	waitFunc(time);
	driveStop();
}


//Auton High Level
void auton(){
	driveForward(1000);
	driveTurnLeft(500);
	driveBack(1000);
}
