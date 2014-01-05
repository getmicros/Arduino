#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>


RTC_DS1307 rtc;
// Connections: Sainsmart LCD/Keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
  //Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  //setup the LCD
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("Time");
  //debug the rtc
   if (! rtc.isrunning()) 
   {
      //Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      rtc.adjust(DateTime(__DATE__, __TIME__));
    }
}

void loop()
{
DateTime now = rtc.now();
//read temperature and output via LCD
lcd.setCursor(0,1);
lcd.print(now.hour(), DEC);
lcd.setCursor(2,1);
lcd.print(":");
lcd.setCursor(3,1);
lcd.print(now.minute(), DEC);
lcd.setCursor(5,1);
lcd.print(":");
lcd.setCursor(6,1);
lcd.print(now.second(), DEC);
delay(1000);
}


