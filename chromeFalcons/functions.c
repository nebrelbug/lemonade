#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)


//Drive Function
void driveFunc(int left1, int right1){
	motor[left] = left1;
	motor[right] = right1;
}

//Lift Function
void liftFunc(int power){
	motor[lift1a] = power;
	motor[lift2a] = power;
	motor[lift1b] = -(power);
	motor[lift2b] = -(power);
}

//Flipper Function
void flipFunc(int power){
	motor[flipper]=power;
}

//Intake Function
void intakeFunc(int power){
	motor[intakeMotor]=power;
}

//user contol lift functions
void liftUp(){
	liftFunc(127);
}

void liftDown(){
	liftFunc(-127);
}

void liftStay(){
	liftFunc(0);
}

//user contol lift program
void lift(){
	if (vexRT[Btn6D]==1){
		liftUp();
		} else if (vexRT[Btn6U]==1) {
		liftDown();
		} else {
		liftStay();
	}
}

//user control flipper functions
void flip1(){
	flipFunc(127);
}

void flip2(){
	flipFunc(-127);
}

void flipStay(){
	flipFunc(0);
}

//user contol flipper program
void flip(){
	if (vexRT[Btn5D]==1) {
		flip1();
		} else if(vexRT[Btn5D]==1){
		flip2();
		} else{
		flipStay();
	}
}

//user control intake functions
void intake1(){
	intakeFunc(127);
}

void intake2(){
	intakeFunc(-127);
}

void intakeStay(){
	intakeFunc(0);
}

//user control intake program
void intake(){
	if(vexRT[Btn5DXmtr2]==1){
		intake1();
	} else if(vexRT[Btn5UXmtr2]==1){
			intake2();
	} else{
			intakeStay();
	}
}

//user control drive function
void drive(){
	driveFunc(vexRT[Ch3],vexRT[Ch2]);
}

//here is the entire auton program/functions
void auton(){
	wait1Msec(1000);
}
