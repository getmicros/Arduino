#include <Charliplexing.h> //Imports the library, which needs to be
#include <Wire.h>
#include "nunchuck_funcs.h"

byte line = 0;       //Row counter
char buffer[10];
int value;
int randNumber;
byte zbut;
int loop_cnt=0;

void setup() 
{
  LedSign::Init();  //Initializes the screen
  randomSeed(analogRead(0));
  nunchuck_setpowerpins();
  nunchuck_init(); // send the initilization handshake
  //Serial.begin(19200);
}

void loop()
{
  if( loop_cnt > 100 ) 
  { // every 100 msecs get new data
        loop_cnt = 0;
        nunchuck_get_data();
        zbut = nunchuck_zbutton();
        //Serial.print("\tzbut: "); Serial.print((byte)zbut,DEC);
        if (zbut == HIGH)
        {
            randNumber = random(1,7);
            throwDice(randNumber);
            delay(100);
        }
  }
  loop_cnt++;
  delay(1);
}

void DisplayBitMap(int lineint)
{
  //int data[9] = {95, 247, 123, 511, 255, 1, 5, 31, 15};
  
  //for(line = 0; line < 9; line++) {
  for (byte led=0; led<14; ++led) {
    if (lineint & (1<<led)) {
      LedSign::Set(led, line, 1);
    } else {
      LedSign::Set(led, line, 0);
    }
  }
    
  line++;
  if(line >= 9) line = 0;
}

void throwDice(int Number)
{
    switch(Number)
    {
      case 1: 	delay(1000);
      	        DisplayBitMap(4088);
      	        DisplayBitMap(2056);
      	        DisplayBitMap(2056);
      	        DisplayBitMap(2056);
      	        DisplayBitMap(2184);
      	        DisplayBitMap(2056);
      	        DisplayBitMap(2056);
      	        DisplayBitMap(2056);
      	        DisplayBitMap(4088);
                break;
       case 2:  delay(1000);
	        DisplayBitMap(4088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2056);
	        DisplayBitMap(2056);
	        DisplayBitMap(2568);
	        DisplayBitMap(2056);
	        DisplayBitMap(4088);
                break;
       case 3:  delay(1000);
	        DisplayBitMap(4088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2184);
	        DisplayBitMap(2056);
	        DisplayBitMap(2568);
	        DisplayBitMap(2056);
	        DisplayBitMap(4088);
                break;
       case 4:  delay(1000);
	        DisplayBitMap(4088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(2056);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(4088);
                break;
       case 5:  delay(1000);
	        DisplayBitMap(4088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(2184);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(4088);
                break;
      case 6:   delay(1000);
	        DisplayBitMap(4088);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(2600);
	        DisplayBitMap(2056);
	        DisplayBitMap(4088);
                break;
      default:  delay(1000);
    }
}
