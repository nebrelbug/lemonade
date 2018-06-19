
  const int analogSensor = A0;  // Analog input pin that the potentiometer is attached to
  const int pwmServo = 3; // Analog output pin that the LED is attached to

  int sensorValue = 0;        // value read from the pot
  int servoValue = 0;        // value output to the PWM (analog out)
  
  void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(pwmServo, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(analogSensor);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // map it to the range of the analog out:
  servoValue = map(sensorValue, 0, 1023, 0, 127);

  // print the results to the Serial Monitor:
  Serial.print("sensor input = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(servoValue);
  
  digitalWrite(pwmServo, servoValue);

  // print out the value you read:
  Serial.print("Voltage");
  Serial.println(voltage);
  delay(1000);
  
  

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}

 