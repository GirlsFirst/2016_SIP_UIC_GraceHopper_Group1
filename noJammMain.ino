#include <Wire.h>
#include <LiquidCrystal.h>
#include <Tone.h>


// A4=SDA, A5=SCL
LiquidCrystal lcd(0);
int PI=3.14;
unsigned int tovf1 = 0;
unsigned long frequency = 0;
unsigned long temp = 0;
// timer 1 is the counter
//16-bit counter overflows after 65536 counts
//tovf1 keeps track of how many times you overflow

// PWM pins are 3, 5, 6, 9, 10, 11, 12
// Master value of how many LEDs I want to have connected
int const howManyLeds = 5;
// The analogWrite command goes from 0 to 255
int const maxBrightness = 255;
// Which pins on the Arduino UNO support Pulse Witdh Modulation (PWM).
int pwmPins[] = {3,5,6,9,10,11,12};
// Create our array of actually used pins with LEDs attached.
int usedPins[howManyLeds];
// Each LED/pin has a different fade speed, we keep that speed multiplier in here.
float currentFadeAmount[howManyLeds];
// For each pin we are using, we also need a current brightness.
int currentBrightness[howManyLeds];
// The counter that we add to, and feed into the sin() function.
float timeAroundLoop;
// Number we add to our timeAroundLoop counter.  Make this bigger for faster pulses.
float timeAdditionValue = 0.005;
//float tempSinVal;



ISR(TIMER1_OVF_vect)
{
  tovf1++
}

void setup() {
  // usedPins is our master destination list of pins.
  for (int i=0; i < howManyLeds; i++)
  {
    // Fill my new array with the available PWM pins.
    usedPins[i] = pwmPins[i];
  }
 // currentFadeAmount is our increment/decrement to our currentBrightness val.
  for (int i = 0; i < howManyLeds; i++)
  {
    // Set the fading speed to be somewhat randomized.
    currentFadeAmount[i] = random(0.0,15.0);
  }
 // Prepare the pins as outputs.  (This may not be needed, but it doesn't hurt.)
  for (int i = 0; i < howManyLeds; i ++)
  {
    pinMode(usedPins[i], OUTPUT);
  }

  // put your setup code here, to run once:
  pinMode(5, INPUT);
  
  void loop() {
    
    
    
    
tone1.play(NOTE_C4);
tone2.play(NOTE_A4);
delay(noteDuration);
tone1.stop();
tone2.stop();

  // Increment our time counter every loop.
  timeAroundLoop = timeAroundLoop + timeAdditionValue;
  for (int i = 0; i < howManyLeds; i++)
  {
    // Each LED fades fater or slower than each other - multiply time by speed.
    tempSinVal = timeAroundLoop*currentFadeAmount[i];

    // This gives us a sinewave value of the adjusted time.  Values from -1 to 1.
    tempSinVal = sin(tempSinVal);

    // Absolute the sine wave (no negatives) to give a bouncing ball style wave.
    tempSinVal = abs(tempSinVal);

    // Do 1-value, to turn the bouncing ball upside down.
    // It now looks like a hanging garland, just touching the ground.
    tempSinVal = 1-tempSinVal;

    // Set the brightness to this value, multiplied by our max brightness.
    // The scale now goes from 0-255 instead of 0-1.
    currentBrightness[i] = tempSinVal * maxBrightness;
    // Write this value to the pin.
    analogWrite(usedPins[i], currentBrightness[i]);
  }

