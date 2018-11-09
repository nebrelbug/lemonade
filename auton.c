#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)



//ints
int leftDriveEncode(){
	return(SensorValue[leftEncoder]*-1);
}

int rightDriveEncode(){
	return(SensorValue[rightEncoder]);
}

//Auton Mddle Level
//drive functions
//Drive Function Middle Level
//drive stop
void driveStop(){
	driveFunc(0,0);
}

void driveForward(){
	driveFunc(127,127);
}

//drive forward
void driveForwardNormal(){
	while(leftDriveEncode()<1300){
		if(rightDriveEncode()<1300){
			driveForward();
		} else
			driveStop();
	}
}


//Auton High Level
void auton(){
	driveForwardNormal();
}
