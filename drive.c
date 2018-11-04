#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Drive Function Base Level
void driveFunc(int power1, int power2){
	motor[left1] = driveLeftChange(power1);
	motor[right1] = driveRightChange(power2);
	motor[left2] = driveLeftChange(power1);
	motor[right2] = driveRightChange(power2);
	motor[left3] = driveLeftChange(power1);
	motor[right3] = driveRightChange(power2);
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
void driveStraight(){
	if(rightMleft()>100){
		leftPowerM();
	} else if(rightMleft()<-100){
			rightPowerM();
	} else{
			rightPower=100;
			leftPower=100;
	}
}

void drive(){
	driveFunc(vexRT[Ch3],vexRT[Ch2]);
}
