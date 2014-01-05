const int SWITCH = 2;
const int X_PIN = 0;
const int Y_PIN = 1;

void setup()
{
pinMode(SWITCH, INPUT);
digitalWrite(SWITCH, HIGH);
Serial.begin(115200); //watch the baud rate in the serial monitor
}

void loop()
{
Serial.print(digitalRead(SWITCH));
Serial.print(" - ");
Serial.print(analogRead(X_PIN));
Serial.print(" by ");
Serial.println(analogRead(Y_PIN));
delay(100);
}
