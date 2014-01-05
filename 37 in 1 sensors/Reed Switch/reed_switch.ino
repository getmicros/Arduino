// Arduino pin numbers
//D2 and A0 used
const int digital = 2;
const int analog = 0;

void setup()
{
pinMode(digital, INPUT);
Serial.begin(115200);
}

void loop()
{
Serial.print(digitalRead(digital));
Serial.print("-");
Serial.println(analogRead(analog));
delay(250);
}
