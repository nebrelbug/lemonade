#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//after ints
#include "drive.c"
#include "puncher.c"
#include "intake.c"

//file that is really called PID
#include "leftPID.c"
#include "rightPID.c"

//after drivercontrol
#include "auton.c"
