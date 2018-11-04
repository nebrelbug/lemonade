#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//ints
//lift potentiomoters
int liftPotent(){
	return(((SensorValue[leftLiftPotent])*(SensorValue[rightLiftPotent]))/2);
}

int leftDriveEncode(){
	return(SensorValue[leftEncoder]);
}

int rightDriveEncode(){
	return(SensorValue[rightEncoder]);
}

int puncherEncode(){
	return(SensorValue[puncherEncoder]);
}

//Drive Function Base Level
void driveFunc(int power1, int power2){
	motor[left1] = power1;
	motor[right1] = power2;
	motor[left2] = power1;
	motor[right2] = power2;
	motor[left3] = power1;
	motor[right3] = power2;
}

//Drive Function Middle Level
//drive forward
void driveForward(){
	driveFunc(127,127);
}

//drive back
void driveBack(){
	driveFunc(-127,-127);
}

//turn left
void driveTurnLeft(){
	driveFunc(-127,127);
}

//turn right
void driveTurnRight(){
	driveFunc(127,-127);
}

//drive stop
void driveStop(){
	driveFunc(0,0);
}

//Drive Top Level
void drive(){
	driveFunc(vexRT[Ch3],vexRT[Ch2]);
}

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
