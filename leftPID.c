#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//PID
//Drive Top Level
// PID using optical shaft encoder
//
// Shaft encoder has 360 pulses per revolution
#define PID_INTEGRAL_LIMIT  50
#define PD_INTEGRAL_LIMIT  50

#define LEFT_SENSOR_INDEX    leftEncoder
#define RIGHT_SENSOR_INDEX   rightEncoder
#define PID_SENSOR_SCALE     -1

#define LEFT_MOTOR_INDEX    left1
#define RIGHT_MOTOR_INDEX   right1
#define PID_MOTOR_SCALE     -1

#define PID_DRIVE_MAX       80
#define PID_DRIVE_MIN     (-80)

// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"

static int   pidRunning = 1;
static float pidRequestedValue;

static int   pdRunning = 1;
static float pdRequestedValue;

bool taskRunning=false;
// These could be constants but leaving


// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*  pid control task                                                           */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

task leftPIDController()
{
		taskRunning=true;
    float  pidSensorCurrentValue;
    float  pidError;
    float  pidLastError;
    float  pidIntegral;
    float  pidDerivative;
    float  pidDrive;

    float  pdSensorCurrentValue;
    float  pdError;
    float  pdLastError;
    float  pdIntegral;
    float  pdDerivative;
    float  pidDrive2;

    // If we are using an encoder then clear it
    if( SensorType[ LEFT_SENSOR_INDEX ] == sensorQuadEncoder )
        SensorValue[ LEFT_SENSOR_INDEX ] = 0;

    if( SensorType[ RIGHT_SENSOR_INDEX ] == sensorQuadEncoder )
        SensorValue[ RIGHT_SENSOR_INDEX ] = 0;

    // Init the variables - thanks Glenn :)
    pidLastError  = 0;
    pidIntegral   = 0;

    pdLastError  = 0;
    pdIntegral   = 0;

    while( true ){
    	if( pidRunning ){
        if(pidSensorCurrentValue==pidRequestedValue){
        	taskRunning = false;
        	stopTask(leftPIDController);
      	}

        // Is PID control active ?
        if( pdRunning )
            {
            // Read the sensor value and scale
            pdSensorCurrentValue = SensorValue[ RIGHT_SENSOR_INDEX ] * PID_SENSOR_SCALE;

                        // Read the sensor value and scale
            pidSensorCurrentValue = SensorValue[ LEFT_SENSOR_INDEX ] * PID_SENSOR_SCALE;


            // calculate error
            pidError = pidSensorCurrentValue - pidRequestedValue;

            // calculate error
            pdError = pdSensorCurrentValue - pdRequestedValue;

            // integral - if Ki is not 0
            if( pd_Ki != 0 )
                {
                // If we are inside controlable window then integrate the error
                if( abs(pdError) < PD_INTEGRAL_LIMIT )
                    pdIntegral = pdIntegral + pdError;
                else
                    pdIntegral = 0;
                }
            else
                pdIntegral = 0;

                        // integral - if Ki is not 0
            if( pid_Ki != 0 )
                {
                // If we are inside controlable window then integrate the error
                if( abs(pidError) < PID_INTEGRAL_LIMIT )
                    pidIntegral = pidIntegral + pidError;
                else
                    pidIntegral = 0;
                }
            else
                pidIntegral = 0;

						// calculate the derivative
            pidDerivative = pidError - pidLastError;
            pidLastError  = pidError;

            // calculate the derivative
            pdDerivative = pdError - pdLastError;
            pdLastError  = pdError;

            // calculate drive
            pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

            pidDrive2 = (pd_Kp * pidError) + (pd_Ki * pidIntegral) + (pd_Kd * pidDerivative);

            // limit drive
            if( pidDrive > PID_DRIVE_MAX )
                pidDrive = PID_DRIVE_MAX;
            if( pidDrive < PID_DRIVE_MIN )
                pidDrive = PID_DRIVE_MIN;

            if( pidDrive2 > PID_DRIVE_MAX )
                pidDrive2 = PID_DRIVE_MAX;
            if( pidDrive2 < PID_DRIVE_MIN )
                pidDrive2 = PID_DRIVE_MIN;

            leftFunc(pidDrive);
						rightFunc(pidDrive2);
					}
      	}else{
            // clear all
            pidError      = 0;
            pidLastError  = 0;
            pidIntegral   = 0;
            pidDerivative = 0;

            // clear all
            pdError      = 0;
            pdLastError  = 0;
            pdIntegral   = 0;
            pdDerivative = 0;

            leftFunc(0);
            rightFunc(0);
            }

        // Run at 50Hz
        wait1Msec( 25 );
        }
}

/*-----------------------------------------------------------------------------*/
/*
*/
/*  main task
/*
*/
/*-----------------------------------------------------------------------------*/

void drivePID(int clicks, int clicks2){

	// send the motor off somewhere
  pidRequestedValue= clicks*-1;
  pdRequestedValue=  clicks2*-1;

	// start the PID task
  startTask( leftPIDController );
  taskRunning=true;
	//	startTask( rightPIDController );

  // use joystick to modify the requested position
  while(taskRunning){
  	// maximum change for pidRequestedValue will be 127/4*20, around 640 counts per second
  	// free spinning motor is 100rmp so 1.67 rotations per second
		// 1.67 * 360 counts is 600
  	wait1Msec(20);
  }
	stopTask(leftPIDController);
}

////////////////////////////////////////////////////////////////////////////////

task puncherOn(){
	while(true){
		puncherFunc(127);
	}
}

task puncherOff(){
	while(true){
		puncherFunc(0);
	}
}

task driveOn(){
	while(true){
		leftFunc(-127);
		rightFunc(-127);
	}
}

task driveOff(){
	while(true){
		leftFunc(0);
		rightFunc(0);
	}
}


task intakeOn(){
	while(true){
		intakeFunc(127);
	}
}

task intakeOff(){
	while(true){
		intakeFunc(0);
	}
}

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Point Turns with Encoders -                                    *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to turn left, and then right, using feedback from the encoders   *|
|*  to determine how much.  There is a 2 second pause at the beginning of the program.                *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" model, but may not be needed for all robot configurations.                      *|
|*    2)  Whichever encoder is being used for feedback should be cleared just before it starts        *|
|*        counting by using the "SensorValue(encoder) = 0;".  This helps ensure consistancy.          *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor   - Port 2    rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor   - Port 3    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital - Port 1,2  rightEncoder        VEX Shaft Encoder     Right side                        *|
|*    Digital - Port 3,4  leftEncoder         VEX Shaft Encoder     Left side                         *|
\*----------------------------------------------------------------------------------------------------*/


void turnLeft(int leftVal){
	resetEncoders();
  while(SensorValue(rightEncoder) < leftVal)//rightEncoder has counted less than 1800 counts
	{
		//Turn Left
		rightFunc(127);  //Motor on port2 is run at full (127) power forward
		leftFunc(-127);       //Motor on port3 is run at full (-127) power reverse
	}
}

void turnRight(int rightVal){
	SensorValue[leftEncoder] = 0;	            //Set the encoder so that it starts counting at 0

  while(SensorValue(leftEncoder) < rightVal)//While leftEncoder has counted less than 1800 counts
	{
		//Turn Right
    rightFunc(-127);// port2 is run at full (127) power forward
		leftFunc(127);      //Motor on port3 is run at full (-127) power reverse	}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//auton functions
//forward slightly

//auton
void auton(){
	//1200 from place to flag or to alliance park
	//2000 from place to center
	startTask(puncherOn);
	delayFunc(800);
	stopTask(puncherOn);
	startTask(puncherOff);
	stopTask(puncherOff);

//	drivePID(1150,1150);
//	drivePID(-2000,-2000);
  // If we are using an encoder then clear it
	resetEncoders();

	turnRight(300);

	startTask(driveOn);
	delayFunc(500);
	stopTask(driveOn);
	startTask(driveOff);
	stopTask(driveOff);

	drivePID(1200,1200);
}
////////////////////////////////////////////////////////////////////////////////
/*
#define LIFT_PID_INTEGRAL_LIMIT  50

#define LIFT_SENSOR_INDEX    liftRight
#define LIFT_PID_SENSOR_SCALE     1

#define LIFT_LEFT_MOTOR_INDEX    left1
#define LIFT_RIGHT_MOTOR_INDEX   right1
#define LIFT_PID_MOTOR_SCALE     -1

#define PID_LIFT_MAX       80
#define PID_LIFT_MIN     (-80)

// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"

static int   pidLiftRunning = 1;
static float pidLiftRequestedValue;

task liftPIDController(){

 float  pidSensorCurrentValue;
 float  pidError;
 float  pidLastError;
 float  pidDerivative;
 float  pidDrive;
 float  pidIntegral;

  	// Init the variables - thanks Glenn :)
	  pidLastError  = 0;
    pidIntegral   = 0;

  while( true ){
    // Is PID control active ?
    if( pidLiftRunning ){
      // Read the sensor value and scale
      pidSensorCurrentValue = SensorValue[ LIFT_SENSOR_INDEX ] * PID_SENSOR_SCALE;

      // calculate error
      pidError = pidSensorCurrentValue - pdRequestedValue;

        // calculate the derivative
        pidDerivative = pidError - pidLastError;
        pidLastError  = pidError;

        if( pid_Lift_Ki != 0 ){
          // If we are inside controlable window then integrate the error
          if( abs(pidError) < LIFT_PID_INTEGRAL_LIMIT )
            pidIntegral = pidIntegral + pidError;
          else
            pidIntegral = 0;
        }
        // calculate drive
        pidDrive = (pid_Lift_Kp * pidError)+(pid_Lift_Kd * pidDerivative)+(pid_Lift_Ki * pidIntegral);

        // limit drive
        if( pidDrive > PID_LIFT_MAX )
          pidDrive = PID_LIFT_MAX;
        if( pidDrive < PID_LIFT_MIN )
          pidDrive = PID_LIFT_MIN;

            // send to motor
           	liftFunc(pidDrive * PID_MOTOR_SCALE);
    }else{
       // clear all
       pidError      = 0;
       pidLastError  = 0;
       pidDerivative = 0;
       rightFunc(0);
     }

    // Run at 50Hz
    wait1Msec( 25 );
  }
}


/*-----------------------------------------------------------------------------*/
/*
*/
/*  main task
/*
*/
/*-----------------------------------------------------------------------------*/
/*
void liftPID(int potentValue){
	pidLiftRequestedValue+=potentValue;

	// start the PID task
  startTask( liftPIDController );
	//	startTask( rightPIDController );

  // use joystick to modify the requested position
  while(true){
  	// maximum change for pidRequestedValue will be 127/4*20, around 640 counts per second
  	// free spinning motor is 100rmp so 1.67 rotations per second
		// 1.67 * 360 counts is 600
  	// send the motor off somewhere
  	wait1Msec(20);
  }
	stopTask(liftPIDController);
}
*/
