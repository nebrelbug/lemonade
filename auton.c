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

void drivePID(int clicks){

	// send the motor off somewhere
  pidRequestedValue= clicks*-1;

	// start the PID task
  startTask( leftPIDController );
  taskRunning=true;
	//	startTask( rightPIDController );

  // use joystick to modify the requested position
  while(taskRunning){
  	if(pidRequestedValue==clicks*-1)
  			taskRunning=false;
  	}
  	// maximum change for pidRequestedValue will be 127/4*20, around 640 counts per second
  	// free spinning motor is 100rmp so 1.67 rotations per second
		// 1.67 * 360 counts is 600
  	wait1Msec(20);

  resetEncoders();
	stopTask(leftPIDController);
}
