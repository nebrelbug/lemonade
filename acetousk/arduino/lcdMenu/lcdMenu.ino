// include the library code:
#include <LiquidCrystal.h>

int menuProgram=     false;
int menuRadio=       false;
int menuSettings=    false;
int menuAlarm=       false;
int menuAudio=       false;
int up=              false;
int down=            false;
int right=           false;
int left=            false;
int menu=            false;

int leftState=       0;
int rightState=      0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); //initialize serial
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("OOOOOOOOOOOOOOOO");
  Serial.print("OOOOOOOOOOOOOOOO");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("OOOOOOOOOOOOO");
  Serial.print("OOOOOOOOOOOOOOOO");
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("initializing");
  Serial.print("initializing");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("initializing.");
  Serial.print("initializing.");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("initializing..");
  Serial.print("initializing..");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("initializing...");
  Serial.print("initializing...");
  delay(1000);
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print("press button to");
  Serial.print("press button to");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("start");
  Serial.print("start");
}

void loop() {
  if (leftState = 1) {
    menu = menu - 1;
    Serial.print("menu - 1");
  }
  if (rightState = 1) {
    menu = menu + 1; 
    Serial.print("menu + 1");
  }
  if (menu=-2){
    menuSettings = 1;
    Serial.print("menu = -2");
  }
  if (menu=-1){
    menuAudio =1;
    Serial.print("menu = -1");
  }
  if (menu=0){
    menuProgram =1;
    Serial.print("menu = 0");
  }
  if (menu=1){
    menuRadio =1;
    Serial.print("menu = 1");
  }
  if (menu=2){
    menuAlarm =1;
    Serial.print("menu = 2");
  }
  if (menu=3) {
    menu=-2;
    Serial.print("menu =3");
  }
  if (menu=-3) {
    menu=2;
    Serial.print("menu = -3");
  }
  if (menuProgram = 1) {
    lcd.setCursor(0, 0);
    lcd.print("program");
    Serial.print("program");
  }
  if (menuSettings = 1) {
    lcd.setCursor(0, 0);
    lcd.print("screen");
    Serial.print("screen");
  }
  if (menuAudio =  1) {
    lcd.setCursor(0, 0);
    lcd.print("audio");
    Serial.print("audio");
  }
  if (menuRadio = 1) {
    lcd.setCursor(0, 0);
    lcd.print("radio");
    Serial.print("radio");
  }
  if (menuAlarm = 1) {
    lcd.setCursor(0, 0);
    lcd.print("alarm");
    Serial.print("alarm");
  }
}