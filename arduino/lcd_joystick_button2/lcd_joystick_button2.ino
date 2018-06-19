/*********************************************
* name:Joystick PS2
* function:push the joystick and the coordinates of X and Y axes displayed on Serial Monitor will change accordingly; 
* press down the joystick, and the coordinate of Z=0 will also be displayed.
connection:
Joystick PS2 SunFounder Uno R3
GND           GND
VCC           5V
Bt            7
x             A0
y             A1
***********************************************/
//Email: support@sunfounder.com
//Website: www.sunfounder.com

const int xPin = A0; //X attach to A0
const int yPin = A1; //Y attach to A1
const int btPin = 7; //Bt attach to digital 7
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  pinMode(btPin,INPUT); //set btpin as INPUT
  digitalWrite(btPin, HIGH); //and HIGH
  Serial.begin(9600); //initialize serial
}

void loop()
{
  
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("X: ");
  lcd.print(analogRead(xPin),DEC); //read the value of A0 and print it in decimal);
  lcd.setCursor(2,1);
  lcd.print("\tZ: ");
   lcd.setCursor(0,2);
  lcd.print(digitalRead(btPin));
   lcd.setCursor(2,3);
  lcd.print("Yeee");
  delay(200);
}
