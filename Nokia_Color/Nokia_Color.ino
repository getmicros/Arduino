
#include <ColorLCDShield.h>

LCDShield lcd;

int buttons[3] = {3, 4, 5};  // S1 = 3, S2 = 4, S3 = 5
byte cont = 40;  // Good center value for contrast

void setup()
{
  for (int i=0; i<3; i++)
  {
    pinMode(buttons[i], INPUT);  // Set buttons as inputs
    digitalWrite(buttons[i], HIGH);  // Activate internal pull-up
  }
  
  lcd.init(PHILLIPS);  // Initialize the LCD, try using PHILLIPS if it's not working
  lcd.contrast(cont);  // Initialize contrast
  lcd.clear(WHITE);  // Set background to white
  testPattern();  // Print color bars on bottom of screen
}

void loop()
{
}

void testPattern()
{
  lcd.setRect(1, 2, 131, 19, 1, WHITE);
  lcd.setRect(1, 19, 131, 35, 1, YELLOW);
  lcd.setRect(1, 35, 131, 51, 1, CYAN);
  lcd.setRect(1, 51, 131, 67, 1, GREEN);
  lcd.setRect(1, 67, 131, 83, 1, MAGENTA);
  lcd.setRect(1, 83, 131, 99, 1, RED);
  lcd.setRect(1, 99, 131, 115, 1, BLUE);
  lcd.setRect(1, 115, 131, 131, 1, BLACK);
}
