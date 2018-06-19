// include the library code:
#include <LiquidCrystal.h>


static bool menuProgram=    false;
String programScreen=        "program";
String setScreen=            "set";
static bool menuRadio=       false;
String radioScreen=          "radio";
static bool menuSettings=    false;
String settingsScreen=       "settings";
static bool menuAlarm=       false;
String alarmScreen=          "alarm";
static bool menuAudio=       false;
String audioScreen=          "audio";
String lcd0=                 "OOOOOOOOOOOOOOOO";
String initializing=         "INITIALIZING";
String intStartup=           "press button";
String endStartup=           "start";
static bool up=              false;
static bool down=            false;
static bool right=           false;
static bool left=            false;
static bool menu=            false;
String lcd1=                 ".";
String lcd2=                 "..";
String lcd3=                 "...";

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(lcd0);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(lcd0);
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(initializing);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(initializing+ lcd1);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(initializing + lcd2);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(initializing + lcd3);
  delay(1000);
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print(intStartup);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(endStartup);
}

void loop() {
  if (left = 1) {
    menu = menu - 1;
  }  
  if (right = 1) {
    menu = menu + 1; 
  }
  if (menu=-2){
    menuSettings =1;
  }
  if (menu=-1){
    menuAudio =1;
  }
  if (menu=0){
    menuProgram =1;
  }
  if (menu=1){
    menuRadio =1;
  }
  if (menu=2){
    menuAlarm =1;
  }
  if (menu=3) {
    menu=-2;
  }
  if (menu=-3) {
    menu=2;
  }
  if (menu>-10 and menu<10) {
    lcd.setCursor(0,1);
    delay(500);
  }
  if (menuProgram = 1) {
    lcd.setCursor(0, 0);
    lcd.print(programScreen);
  }
  if (menuSettings = 1) {
    lcd.setCursor(0, 0);
    lcd.print(settingsScreen);
  }
  if (menuAudio = 1) {
    lcd.setCursor(0, 0);
    lcd.print(audioScreen);
  }
  if (menuRadio = 1) {
    lcd.setCursor(0, 0);
    lcd.print(radioScreen);
  }
  if (menuAlarm = 1) {
    lcd.setCursor(0, 0);
    lcd.print(alarmScreen);
  }
}
 