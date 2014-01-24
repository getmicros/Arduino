//libraries needed
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>


//I2C Controller
#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

//DHT11
#define DHT11PIN 8

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
dht11 DHT11;

void setup()
{ 
    //setup the LCD
    lcd.begin (16,2);
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
}

void loop() 
{
 
  //lcd.clear();
  lcd.home();
 
  DHT11.read(DHT11PIN);
 
  lcd.setCursor(0,0);
  lcd.print("Humid : ");
  lcd.print((float)DHT11.humidity, 2);
 
  lcd.setCursor(0,1);
  lcd.print("Temp : ");
  lcd.print((float)(DHT11.temperature), 2);

  delay(1000);
    
}

