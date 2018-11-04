#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//delay void
void waitFunc(int time){
	wait1Msec(time);
}

//ints
int leftDriveEncode(){
	return(SensorValue[leftEncoder]);
}

int rightDriveEncode(){
	return(SensorValue[rightEncoder]);
}

int puncherEncode(){
	return(SensorValue[puncherEncoder]);
}

int leftPowerM(){
	return(leftPower-.01);
}

int rightPowerM(){
	return(rightPower-.01);
}

//higher ints
int rightMleft(){
	return(rightDriveEncode()-leftDriveEncode());
}

int driveLeftChange(int power){
	return(power*leftPower);
}

int driveRightChange(int power){
	return(power*rightPower);
}
