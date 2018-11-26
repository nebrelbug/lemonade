#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//after ints
//sensor encoders int
int leftEncode(){
	string value;
	value = SensorValue[leftEncoder];
	return(value);
}

int rightEncode(){
	string value;
	value = SensorValue[rightEncoder];
	return(value);
}

void driveFunc(int power1, int power2){
	SetMotor(right1, power2);
	SetMotor(right2, power2);
	SetMotor(right3, power2);
	SetMotor(left1,  power1);
	SetMotor(left2,  power1);
	SetMotor(left3,  power1);
}

//Drive Function High Level
void drive(){
	driveFunc(vexRT[Ch3],vexRT[Ch2]);
}

//puncher Function Base Level
void puncherFunc(int power){
	motor[puncher1]=power;
	motor[puncher2]=power;
}

//puncher Function Middle Level
//puncher stop
void puncherStop(){
	puncherFunc(0);
}

void puncherForward(){
	puncherFunc(127);
}

void puncher(){
	if(vexRT[Btn5U]==1){
		puncherForward();
	} else{
			puncherStop();
	}
}

//intake Function Base Level
void intakeFunc(int power){
	SetMotor(intake, power);
}

//intake Function Middle intake
//intake stop
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
	} else if(vexRT[Btn6D]==1){
			intakeBackward();
	}else
			intakeStop();
}

//pneumatics

//lcd clear
void clearLCD(){
	clearLCDLine(0);
	clearLCDLine(1);
}

//lcd driver control
int lcdToggle;

void lcd(){
	clearLCD();
	wait1Msec(20);
	if(lcdToggle ==1){
		displayLCDCenteredString(0, stringConcatenate("Left Side: ",leftEncode));
		displayLCDCenteredString(1, stringConcatenate("Right Side: ",rightEncode);
		lcdToggle=0;
	}/*--else(lcdToggle =0){
		displayLCDCenteredString(0, stringConcatenate("Left Side: ",leftEncode));
		displayLCDCenteredString(1, stringConcatenate("Right Side: ",rightEncode);
		lcdToggle=1;
	}--*/
}

//void lcd display voltage


void lcdBattery(){

		clearLCD();

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);

		//Short delay for the LCD refresh rate
		wait1Msec(100);

}

//file that is really called PID
#include "rightPID.c"

//after drivercontrol
#include "auton.c"
