#include <Arduino.h>
#include <LedControl.h>

// declare function prototypes
void lampOn(int);
void lampOff(int);
void setup();
void loop();

/**
 * we need a LedControl to work with
 * pin 12 is connected to the DataIn
 * pin 11 is connected to the CLK
 * pin 10 is connected to LOAD
 * number of devices 
 */
LedControl lc = LedControl(12, 11, 10, 4);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 500;

void setup()
{
  // put your setup code here, to run once:

  // initialize LED digital pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // we have already set the number of devices when we created the LedControl
  int devices = lc.getDeviceCount();

  // we have to init all devices in a loop
  for (int address = 0; address < devices; address++)
  {
    // the MAX72XX is in power-saving mode on startup
    lc.shutdown(address, false);
    // set the brightness to a medium values
    lc.setIntensity(address, 8);
    // clear the display
    lc.clearDisplay(address);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  lampOff(100);
  lampOn(1000);
  lampOff(100);
  lampOn(5000);

  // read the number cascaded devices
  int devices = lc.getDeviceCount();

  // we have to init all devices in a loop
  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 8; col++)
    {
      for (int address = 0; address < devices; address++)
      {
        delay(delaytime);
        lc.setLed(address, row, col, true);
        delay(delaytime);
        lc.setLed(address, row, col, false);
      }
    }
  }
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