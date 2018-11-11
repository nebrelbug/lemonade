#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//sensor encoders int
int leftEncode(){
	return(SensorValue[leftEncoder]);
}

int rightEncode(){
	return(SensorValue[rightEncoder]);
}

//Drive Function Base Level
void leftDriveFunc(int power){
	SetMotor(left1,  power);
	SetMotor(left2,  power);
	SetMotor(left3,  power);
}

void rightDriveFunc(int power){
	SetMotor(right1, power);
	SetMotor(right2, power);
	SetMotor(right3, power);
}

void driveFunc(int power1, int power2){
	leftDriveFunc(power1);
	rightDriveFunc(power2);
}

int driveJoystick(int input){
	if((input<15)&&(input>-15)){
		return(0);
	} else
			return(input);
}

//Drive Function High Level
void drive(){
	driveFunc(driveJoystick(vexRT[Ch3]),driveJoystick(vexRT[Ch2]));
}
