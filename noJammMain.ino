#include <Wire.h>
#include <LiquidCrystal.h>
#include <Tone.h>
#include <stdint.h>




#define NOTE_A4  440
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 



Tone PIEZOPIN1;
Tone PIEZOPIN2;
int buttonPin = 0;
int buttonState = digitalRead(buttonPin);

int Pin6 = 6;       // Led 1
int Pin9 = 9;       // Led 2 

int Value6 = 0;    //Value Led1
int Value9 = 0;    //Value Led2

int analog0Pin = 0;      // button to start wave
int val0 = 0;             // variable to store the value read

int threshold = 512;     // threshold for button
int timer = 100;


void setup() {
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT);
  PIEZOPIN1.play(NOTE_A4);
  PIEZOPIN2.play(NOTE_A4);
  while(PIEZOPIN1.isPlaying() || PIEZOPIN2.isPlaying());
 pinMode(analog0Pin, INPUT);
 pinMode(Pin6, OUTPUT);   // sets the digital pin as output
 pinMode(Pin9, OUTPUT);   // sets the digital pin as output
 
 Serial.begin(9600);          //  setup serial
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("NOJAMM !!!!");
}


  
void loop() {
  tone(NOTE_A4, 440, 5000);
   if (buttonState == HIGH) {
    //led turn on
     lcd.print("Now playing: 440 Hz");
  PIEZOPIN1.play(NOTE_A4);
  PIEZOPIN2.play(NOTE_A4);
  while(PIEZOPIN1.isPlaying() || PIEZOPIN2.isPlaying());
   }
   else{
    //led turn off
    //lcd turn on
  PIEZOPIN1.play(NOTE_A4);
  PIEZOPIN2.play(NOTE_A4);
  while(PIEZOPIN1.isPlaying() || PIEZOPIN2.isPlaying());
   }
   { 
 val0 = analogRead(analog0Pin);    // read the input pin for button
 Serial.println(val0);             // debug value

if (val0 >= threshold)                // 

{ 
 for(Value6 = 0 ; Value6 <= 255; Value6+=5) // fade in (from min to max) Led 1
 { 
   analogWrite(Pin6, Value6);           // sets the value (range from 0 to 255) 
   delay(30);                            // waits for 30 milli seconds to see the dimming effect 
 } 
 for(Value6= 255; Value6 >=0; Value9-=5)   // fade out (from max to min) 
 { 
   analogWrite(Pin6, Value6); 
   delay(30); 
     } 
 
 
  if (Value6 = 255)             

{ 
 for(Value9 = 0 ; Value9 <= 255; Value9+=5) // fade in (from min to max) Led 2
 { 
   analogWrite(Pin9, Value9);           // sets the value (range from 0 to 255) 
   delay(30);                            // waits for 30 milli seconds to see the dimming effect 
 } 
 for(Value9 = 255; Value9 >=0; Value9-=5)   // fade out (from max to min) 
 { 
   analogWrite(Pin9, Value9); 
   delay(30); 
     } 
 
     
     if (Value9 = 255);


 }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  // Increment our time counter every loop.
  //timeAroundLoop = timeAroundLoop + timeAdditionValue;

}
}
}
