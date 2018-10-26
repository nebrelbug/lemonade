//here is the entire auton program/functions
void auton(){
	autonForward();
	autonTurn();
	autonBack();
	autonForward2();
}

void autonForward(){
	while((leftDriveEncode()<1500)&&(rightDriveEncode()<1500)){
		driveForward();
	}
	driveStop();
}

void autonTurn(){
	while()
}

void autonBack(){

}

void autonForward(){

}
