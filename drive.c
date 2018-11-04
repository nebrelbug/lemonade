#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Drive Function Base Level
void driveFunc(int power1, int power2){
	SetMotor(left1,driveLeftChange(power1));
	SetMotor(right1,driveRightChange(power2));
	SetMotor(left2,driveLeftChange(power1));
	SetMotor(right2,driveRightChange(power2));
	SetMotor(left3,driveLeftChange(power1));
	SetMotor(right3,driveRightChange(power2));
}

//Drive Function Middle Level
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
	driveStraight();
	driveFunc(vexRT[Ch3],vexRT[Ch2]);
}
