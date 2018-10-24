#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)


//Drive Function
void driveFunc(int power1, int power2){
	motor[left1] = power1;
	motor[right1] = power2;
	motor[left2] = power1;
	motor[right2] = power2;
	motor[left3] = power1;
	motor[right3] = power2;
}

//Lift Function
void liftFunc(int power){
	motor[liftLeft] = power;
	motor[liftRight] = power;
}

//Flipper Function
void flipFunc(int power){
	motor[flipper]=power;
}

//Intake Function
void intakeFunc(int power){
	motor[intaker]=power;
}

//user contol lift functions
void liftUp(){
	liftFunc(127);
}

void liftDown(){
	liftFunc(-127);
}

void liftStayUp(){
	liftFunc(50);
}

void liftStayDown(){
	liftFunc(-50);
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
		} else if(SensorValue[liftPotent]>150){
			liftStayUp();
		} else if(SensorValue[liftPotent]<-150){
			liftStayDown();
		} else{
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

void flipStayUp(){
	flipFunc(50);
}

void flipStayDown(){
	flipFunc(-50);
}

//user contol flipper program
void flip(){
	if (vexRT[Btn5D]==1) {
		flip1();
		} else if(vexRT[Btn5D]==1){
		flip2();
		} else if(){
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
