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

int puncher(){
	return(SensorValue[puncherEncoder]);
}

//Drive Function Base Level
void driveFunc(int power1, int power2){
	motor[left1] = power1;
	motor[right1] = power2;
	motor[left2] = power1;
	motor[right2] = power2;
	motor[left3] = power1;
	motor[right3] = power2;
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
//drive function
void drive(){
	driveFunc(vexRT[Ch3],vexRT[Ch2]);
}

//Lift Function Base
void liftFunc(int power){
	motor[liftLeft] = power;
	motor[liftRight] = power;
}

//Lift Middle Function
void liftUp(){
	liftFunc(127);
}

void liftDown(){
	liftFunc(-127);
}

void liftStay(){
	liftFunc(0);
}

//Lift Top Level
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

//Auton High Level
void auton(){
	autonForward();
	autonTurnLeft();
	autonBack();
	autonForward2();
}

//Auton Middle Level
void autonDriveForward(){
	driveFunc(127,127);
}

void autonDriveTurnLeft(){
	driveFunc(-127,127);
}

void autonDriveTurnRight(){
	driveFunc(127,-127)
}

void autonDriveBack(){
	driveStop(-127,-127);
}

//LCD Functions
void batteryLCD(){

	bLCDBacklight = true;                                    // Turn on LCD Backlight
	string mainBattery, backupBattery;

	//Clear LCD of text
	clearLCDLine(0);                                            // Clear line 1 (0) of the LCD
	clearLCDLine(1);                                            // Clear line 2 (1) of the LCD

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

/*--
//LCD Functions
//Wait for Press--------------------------------------------------
void waitForPress(){
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease() {
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

void lcd(){
	/*
Code Chooser
ROBOTC on VEX 2.0 Cortex
This program uses the Display functions of ROBOTC on the VEX 2.0 Cortex platform.
It allows the user to choose from 4 different pieces of code using the left and right buttons
on the VEX LCD. Once the center button is pressed, the code corresponding with the choice is run.
This code can be adapted for competition based settings - just place the code for the first
switch case in the pre_auton function, and the code for the second switch in the autonomous task.
Replace the basic movement behaviors in the second switch with your own autonomous routines.
ROBOT CONFIGURATION
MOTORS &amp; SENSORS:
[I/O Port]                    [Name]                            [Type]                                [Description]
UART Port 2                    none                                VEX LCD                                VEX LCD Screen
Motor Port 2                rightMotor                    VEX 3-wire module            Right side motor
Motor Port 3                leftMotor                        VEX 3-wire module            Left side motor
*/
//lcd variables and functions
/*--
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

//Declare count variable to keep track of our choice
int count = 0;
//------------- Beginning of User Interface Code ---------------
//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton){
	//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
		//Display first choice
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "<         Enter        >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton){
			waitForRelease();
			count = 3;
		}
		else if(nLCDButtons == rightButton){
			waitForRelease();
			count++;
		}
		break;
		case 1:
		//Display second choice
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "<         Enter        >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton){
			waitForRelease();
			count--;
		}
		else if(nLCDButtons == rightButton){
			waitForRelease();
			count++;
		}
		break;
		case 2:
		//Display third choice
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "<         Enter        >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton){
			waitForRelease();
			count--;
		}
		else if(nLCDButtons == rightButton){
			waitForRelease();
			count++;
		}
		break;
		case 3:
		//Display fourth choice
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "<         Enter        >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton){
			waitForRelease();
			count--;
		}
		else if(nLCDButtons == rightButton){
			waitForRelease();
			count = 0;
		}
		break;
		default:
		count = 0;
		break;
		}
	}
//------------- End of User Interface Code ---------------------

//------------- Beginning of Robot Movement Code ---------------
//Clear LCD
clearLCDLine(0);
clearLCDLine(1);
//Switch Case that actually runs the user choice
switch(count){
case 0:
//If count = 0, run the code correspoinding with choice 1
displayLCDCenteredString(0, "Autonomous 1");
displayLCDCenteredString(1, "is running!");
wait1Msec(2000);                        // Robot waits for 2000 milliseconds

// Move forward at full power for 3 seconds
//Ends before moving on

break;
case 1:
//If count = 1, run the code correspoinding with choice 2
displayLCDCenteredString(0, "Autonomous 2");
displayLCDCenteredString(1, "is running!");
wait1Msec(2000);                        // Robot waits for 2000 milliseconds

//robot call void Red
break;
case 2:
//If count = 2, run the code correspoinding with choice 3
displayLCDCenteredString(0, "Autonomous 3");
displayLCDCenteredString(1, "is running!");
wait1Msec(2000);                        // Robot waits for 2000 milliseconds

//Robot call Void Blue

break;
case 3:
//If count = 3, run the code correspoinding with choice 4
displayLCDCenteredString(0, "Autonomous 4");
displayLCDCenteredString(1, "is running!");
wait1Msec(2000);                        // Robot waits for 2000 milliseconds

//auton function call void 4

break;
default:
displayLCDCenteredString(0, "No valid choice");
displayLCDCenteredString(1, "was made!");
break;
}
//------------- End of Robot Movement Code -----------------------
}
--*/
