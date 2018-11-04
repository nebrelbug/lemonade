#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Auton Middle Level
void autonDriveForward(){
	driveFunc(127,127);
}

void autonDriveTurnLeft(){
	driveFunc(-127,127);
}

void autonDriveTurnRight(){
	driveFunc(127,-127);
}

void autonDriveBack(){
	driveFunc(-127,-127);
}


//Auton High Level
void auton(){
	autonDriveForward();
	autonDriveTurnLeft();
	autonDriveBack();
}
