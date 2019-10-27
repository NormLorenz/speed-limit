#include <Arduino.h>
#include <LedControl.h>

enum Orientation
{
  horizonal,
  vertical,
};

// declare function prototypes
void lampOn(int);
void lampOff(int);
void showBoundries(bool);
void writeSegments();
void writeSegment(int, int, int, Orientation, bool);
void displayRandomSpeed();
void displaySpeed(int);
void displayDigit(int, bool);
void showAllLeds();

/**
 * we need a LedControl to work with
 * pin D7 is connected to the DataIn
 * pin D5 is connected to the CLK
 * pin D8 is connected to LOAD
 * number of devices 
 */

LedControl lc = LedControl(D7, D5, D8, 4);

// local variables
int unit = -1;
int ten = -1;

void setup()
{
  // initialize LED digital pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // we have already set the number of devices when we created the LedControl
  int devices = lc.getDeviceCount();

  // // we have to init all devices in a loop
  for (int address = 0; address < devices; address++)
  {
    // the MAX72XX is in power-saving mode on startup
    lc.shutdown(address, false);
    // set the brightness to a medium values
    lc.setIntensity(address, 0);
    // clear the display
    lc.clearDisplay(address);
  }
}

void loop()
{
  // blink a led
  lampOn(100);
  lampOff(100);

  // writeSegments();
  displayRandomSpeed();
  delay(1000);
}

void showAllLeds()
{
  /* we always wait a bit between updates of the display */
  unsigned long delaytime = 10;

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
  delay(milliseconds);
}

void lampOn(int milliseconds)
{
  // turn the LED on (LOW is the voltage level)
  digitalWrite(LED_BUILTIN, LOW);
  delay(milliseconds);
}

void showBoundries(bool action)
{
  int delayTimer = 500;

  for (int addr = 0; addr < 4; addr++)
  {
    lc.setLed(addr, 0, 0, action);
    delay(delayTimer);
    lc.setLed(addr, 0, 7, action);
    delay(delayTimer);
    lc.setLed(addr, 7, 0, action);
    delay(delayTimer);
    lc.setLed(addr, 7, 7, action);
    delay(delayTimer);
  }
}

void displayRandomSpeed()
{
  // generate a speed between 1 and 40 miles per hour
  int randomSpeed = (rand() % 40) + 1;
  displaySpeed(randomSpeed);
}

void displaySpeed(int speed)
{
  // see if we need to display a different ten digit
  if (ten != speed / 10)
  {
    ten = speed / 10;
    lc.clearDisplay(3);
    lc.clearDisplay(2);
    if (ten != 0)
      displayDigit(ten, false);
  }

  // see if we need to display a different unit digit
  if (unit != speed % 10)
  {
    unit = speed % 10;
    lc.clearDisplay(1);
    lc.clearDisplay(0);
    displayDigit(unit, true);
  }
}

void displayDigit(int value, bool unit)
{
  switch (value)
  {
  case 0:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(0, 0, 2, Orientation::horizonal, unit); // e
    writeSegment(1, 0, 1, Orientation::horizonal, unit); // f
    break;
  case 1:
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    break;
  case 2:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(0, 0, 2, Orientation::horizonal, unit); // e
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  case 3:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  case 4:
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(1, 0, 1, Orientation::horizonal, unit); // f
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  case 5:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(1, 0, 1, Orientation::horizonal, unit); // f
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  case 6:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(0, 0, 2, Orientation::horizonal, unit); // e
    writeSegment(1, 0, 1, Orientation::horizonal, unit); // f
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  case 7:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    break;
  case 8:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(0, 0, 2, Orientation::horizonal, unit); // e
    writeSegment(1, 0, 1, Orientation::horizonal, unit); // f
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  case 9:
    writeSegment(1, 1, 7, Orientation::vertical, unit);  // a
    writeSegment(1, 7, 1, Orientation::horizonal, unit); // b
    writeSegment(0, 7, 2, Orientation::horizonal, unit); // c
    writeSegment(0, 1, 1, Orientation::vertical, unit);  // d
    writeSegment(1, 0, 1, Orientation::horizonal, unit); // f
    writeSegment(1, 1, 0, Orientation::vertical, unit);  // g
    break;
  }
}

void writeSegment(int addr, int row, int col, Orientation orientation, bool unit)
{
  for (int i = 0; i < 6; i++)
  {
    if (orientation == Orientation::horizonal)
    {
      lc.setLed(unit ? addr : addr + 2, row, col + i, true);
      delay(25);
    }
    else
    {
      lc.setLed(unit ? addr : addr + 2, row + i, col, true);
      delay(25);
    }
  }
}