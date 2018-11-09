#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Drive Function Base Level
void intakeFunc(int power){
	motor[intake]=power;
}

//Drive Function Middleintake
//drive stop
void intakeStop(){
	intakeFunc(0);
}

void intakeForward(){
	intakeFunc(127);
}

void intakeBackward(){
	intakeFunc(-127);
}

void intaking(){
	if(vexRT[Btn6U]==1){
		intakeForward();
	} else if(vexRT[Btn6D]){
			intakeBackward();
	} else
			intakeStop();
}
