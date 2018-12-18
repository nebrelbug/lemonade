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

#define LEFT_SENSOR_INDEX    leftEncoder
#define RIGHT_SENSOR_INDEX   rightEncoder
#define PID_SENSOR_SCALE     1

#define LEFT_MOTOR_INDEX    left1
#define RIGHT_MOTOR_INDEX   right1
#define PID_MOTOR_SCALE     -1

#define PID_DRIVE_MAX       80
#define PID_DRIVE_MIN     (-80)

// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"

static int   pidRunning = 1;
static float pidRequestedValue;

static float pdRequestedValue;


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
    float  pidSensorCurrentValue;

    float  pidError;
    float  pidLastError;
    float  pidIntegral;
    float  pidDerivative;
    float  pdError;
    float  pdLastError;
    float  pdIntegral;
    float  pdDerivative;
    float  pidDrive;
    float  pidDrive2;

    // If we are using an encoder then clear it
    if( SensorType[ LEFT_SENSOR_INDEX ] == sensorQuadEncoder )
        SensorValue[ LEFT_SENSOR_INDEX ] = 0;

    if( SensorType[ RIGHT_SENSOR_INDEX ] == sensorQuadEncoder )
        SensorValue[ RIGHT_SENSOR_INDEX ] = 0;

    // Init the variables - thanks Glenn :)
    pidLastError  = 0;
    pidIntegral   = 0;

    while( true )
        {
        // Is PID control active ?
        if( pdRunning )
            {
            // Read the sensor value and scale
            pidSensorCurrentValue = SensorValue[ LEFT_SENSOR_INDEX ] * PID_SENSOR_SCALE;


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

            // calculate the derivative
            pdDerivative = pdError - pdLastError;
            pdLastError  = pdError;

            // calculate drive

            pidDrive2 = (pd_Kp * pidError) + (pd_Ki * pidIntegral) + (pd_Kd * pidDerivative);

            // limit drive
            if( pidDrive > PID_DRIVE_MAX )
                pidDrive = PID_DRIVE_MAX;
            if( pidDrive < PID_DRIVE_MIN )
                pidDrive = PID_DRIVE_MIN;

        // Is PID control active ?
        if( pidRunning )
            {
            // Read the sensor value and scale
            pidSensorCurrentValue = SensorValue[ LEFT_SENSOR_INDEX ] * PID_SENSOR_SCALE;


            // calculate error
            pidError = pidSensorCurrentValue - pidRequestedValue;

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

            // calculate drive
            pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

            // limit drive
            if( pidDrive > PID_DRIVE_MAX )
                pidDrive = PID_DRIVE_MAX;
            if( pidDrive < PID_DRIVE_MIN )
                pidDrive = PID_DRIVE_MIN;

            // send to motor
            leftFunc(pidDrive * PID_MOTOR_SCALE);
            }
        else
            {
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
  pidRequestedValue= clicks;
  pdRequestedValue=  clicks2;

	// start the PID task
  startTask( leftPIDController );
//	startTask( rightPIDController );

  // use joystick to modify the requested position
  while(pidRequestedValue!=leftEncode()){
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

	drivePID(1300,1300);
	drivePID(-2000,-2000);
	drivePID(300,-300);
	drivePID(-150,-150);
	drivePID(600,600);
}
////////////////////////////////////////////////////////////////////////////////

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
