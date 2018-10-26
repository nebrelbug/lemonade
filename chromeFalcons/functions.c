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
		} else if(liftPotent()>150){
			liftStayUp();
		} else if(liftPotent()<-150){
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

//LCD Functions
void batteryLCD(){

	bLCDBacklight = true;                                    // Turn on LCD Backlight
	string mainBattery, backupBattery;

	//Clear LCD of text
	clearLCDLine(0);                                            // Clear line 1 (0) of the LCD
	clearLCDLine(1);                                            // Clear line 2 (1) of the LCD

	//Boot Sequence
	displayLCDString(0,0, "Booting Robot");
	displayLCDString(1,0, "1");
	clearLCDLine(1);
	wait1Msec(250);
	displayLCDString(1,0, "1 2");
	clearLCDLine(1);
	wait1Msec(250);
	displayLCDString(1,0, "1 2 3");
	clearLCDLine(1);
	wait1Msec(250);
	displayLCDString(1,0, "1 2 3 A");
	clearLCDLine(1);
	wait1Msec(250);
	displayLCDString(1,0, "1 2 3 A B");
	clearLCDLine(1);
	wait1Msec(250);
	displayLCDString(1,0, "1 2 3 A B C");
	wait1Msec(1000);

	//Display the Primary Robot battery voltage
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	displayNextLCDString(mainBattery);

	//Display the Backup battery voltage
	displayLCDString(1, 0, "Backup: ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
	displayNextLCDString(backupBattery);
	wait1Msec(2000);

	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
}
