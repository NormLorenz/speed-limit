#include <Arduino.h>

// declare function prototypes
void textToMorse(const char *);
void lampOn(int);
void lampOff(int);

void setup()
{
  // put your setup code here, to run once:

  // initialize LED digital pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  lampOff(100);
  lampOn(1000);
  lampOff(100);
  lampOn(5000);
}

void lampOff(int milliseconds)
{
  // turn the LED off (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  // wait
  delay(milliseconds);
}

void lampOn(int milliseconds)
{
  // turn the LED on (LOW is the voltage level)
  digitalWrite(LED_BUILTIN, LOW);

  // wait
  delay(milliseconds);
}
