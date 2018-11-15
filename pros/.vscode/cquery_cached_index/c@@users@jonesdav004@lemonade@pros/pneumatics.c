#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

//Drive Function Base Level
void pneumaticsFunc(int power){
	SensorValue[dgtl9]=power;
}

//Dive Function Middle Level
//drive stop
void pneumaticsDown(){
	pneumaticsFunc(0);
}

void pneumaticsUp(){
	pneumaticsFunc(1);
}

void pneumatics(){
	if(vexRT[Btn7U]==1){
		pneumaticsUp();
	} else{
			pneumaticsDown();
	}
}
