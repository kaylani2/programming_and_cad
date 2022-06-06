/*
 * Update: 12/11/2017
 * 
 * Holy shit! This code is really badly written. Since it works just fine for my purposes I'll leave exactly like it is.
 * Suggested modifications:
 *  -> Indentation IS NOT standardized, CHANGE THAT!!!
 *  -> It's probably better to write the messages on the LCD display as generic instructions for turning on an outlet instead of a coffe maker.
 *  
 */

/*
  Author: Kaylani Bochie
  Last Modification: 18/3/2017

  Purpose: To set any home appliance to turn on at a chosen time and how long it should be on

*/

#include <Wire.h>
#include <RTClib.h>
#include  <LiquidCrystal_I2C.h>

RTC_DS1307 rtc;

LiquidCrystal_I2C lcd (0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //initializes the display at the 0x3f adress

char daysOfTheWeek [7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int relayOutput = 9;
const int confirmButton = 8;
const int plusHourButton = 7;
const int minusHourButton = 6;
const int plusMinuteButton = 5;
const int minusMinuteButton = 4;
const int resetButton = 3;

int onTurningHour = 0;
//int offTurningHour = 0;
int onTurningMinute = 0;
//int offTurningMinute = 0;


void setup () {
  lcd.begin (16, 2);
  pinMode (relayOutput, OUTPUT);
  pinMode (confirmButton, INPUT_PULLUP);
  pinMode (plusHourButton, INPUT_PULLUP);
  pinMode (minusHourButton, INPUT_PULLUP);
  pinMode (plusMinuteButton, INPUT_PULLUP);
  pinMode (minusMinuteButton, INPUT_PULLUP);
  pinMode (resetButton, INPUT_PULLUP);
  digitalWrite (relayOutput , HIGH);
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println ("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning ()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }



  lcd.clear ();
  lcd.setCursor (0, 0);
  lcd.print ("Standing by");
  delay (1000);

  lcd.clear ();
  lcd.setCursor (0, 0);
  lcd.print ("Choose the time you want your coffe");
  delay (250);
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    lcd.scrollDisplayLeft ();
    delay (250);
  }
  delay (250);
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    lcd.scrollDisplayRight ();
    delay (250);
  }
  delay (1000);


  while (digitalRead (confirmButton) == HIGH) {
    lcd.clear ();
    lcd.setCursor (0, 0);
    lcd.print ("Use the buttons");
    lcd.setCursor (0, 1);
    lcd.print (onTurningHour);
    lcd.print ("h :");
    lcd.print (onTurningMinute);
    lcd.print ("m ");
    if (digitalRead (plusHourButton) == LOW)
      plusHour ();
    if (digitalRead (plusMinuteButton) == LOW)
      plusMinute ();
    if (digitalRead (minusHourButton) == LOW)
      minusHour ();
    if (digitalRead (minusMinuteButton) == LOW)
      minusMinute ();
    delay (50);
  }


}

void loop () {

  if (digitalRead(resetButton == LOW)) {
    digitalWrite (relayOutput, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Choose the time you want your coffe");
    delay(250);
    for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(250);
    }
    delay(250);
    for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
      lcd.scrollDisplayRight();
      delay(250);
    }
    delay(1000);


    while (digitalRead(confirmButton) == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Use the buttons");
      lcd.setCursor(0, 1);
      lcd.print(onTurningHour);
      lcd.print("h :");
      lcd.print(onTurningMinute);
      lcd.print("m ");
      if (digitalRead(plusHourButton) == LOW)
        plusHour();
      if (digitalRead(plusMinuteButton) == LOW)
        plusMinute();
      if (digitalRead(minusHourButton) == LOW)
        minusHour();
      if (digitalRead(minusMinuteButton) == LOW)
        minusMinute();
      delay(50);
    }


  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time set to:");
  lcd.setCursor(0, 1);
  lcd.print(onTurningHour);
  lcd.print("h :");
  lcd.print(onTurningMinute);
  lcd.print("m ");

  DateTime now = rtc.now();
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  //  Serial.print(" since midnight 1/1/1970 = ");
  //  Serial.print(now.unixtime());
  //  Serial.print("s = ");
  //  Serial.print(now.unixtime() / 86400L);
  //  Serial.println("d");


  Serial.println();
  delay(1000);

  if (now.hour() == onTurningHour)
    if (now.minute() == onTurningMinute) {
      digitalWrite (relayOutput, LOW);
      lcd.clear();
      lcd.setBacklight(HIGH);
      lcd.setCursor(0 , 0);
      lcd.print("Bom dia");
    }
}


void plusHour () {
  if (onTurningHour < 23)
    onTurningHour++;
  else
    onTurningHour = 0;
}


void plusMinute () {
  if (onTurningMinute < 59)
    onTurningMinute++;
  else
    onTurningMinute = 0;
}


void minusHour () {
  if (onTurningHour > 0)
    onTurningHour--;
  else
    onTurningHour = 23;
}

void minusMinute () {
  if (onTurningMinute > 0)
    onTurningMinute--;
  else
    onTurningMinute = 59;
}
