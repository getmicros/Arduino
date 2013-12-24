
int pin = 8;
int note = 988;

void setup()
{
}

void loop()
{
  //3 dots for the S
  for (int i=0; i<3; i++)
  {
    tone(pin, note, 100);
    delay(200);
    noTone(pin);
  }
  delay(200);
  //3 dashes for the O
  for (int i=0; i<3; i++)
  {
    tone(pin, note, 300);
    delay(400);
    noTone(pin);
  }
  delay(200);
  //3 dots for the S again
  for (int i=0; i<3; i++)
  {
    tone(pin, note, 100);
    delay(200);
    noTone(pin);
  }
  delay(200);
  //wait 3 seconds
  delay(3000);
}


