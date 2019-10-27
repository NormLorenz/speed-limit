## Board and Pinout

https://www.banggood.com/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12F-WIFI-Development-Board-p-985891.html?rmmds=search&cur_warehouse=USA
https://fccid.io/2AL3B-ESP-F/User-Manual/User-Manual-3387875
https://www.sigmdel.ca/michel/ha/esp8266/doit_nodemcu_v3_en.html

## PlatformIO

https://docs.platformio.org/en/latest/ide/vscode.html
https://platformio.org/platformio-ide?install=vscode
https://www.youtube.com/watch?v=0poh_2rBq7E

## Terminology

* Differences between esp32 and esp8266 https://makeradvisor.com/esp32-vs-esp8266/

* Espressif (chip maker) - https://www.espressif.com/en
  * ESP Modules
    * ESP32
    * ESP8266
  * Development Boards
    * ESP32 DevKitC
    * ESP8266 DevKitC
    * Others
* BangGood - Parts supplier - https://www.banggood.com/
* Geekcreit® - Brand sold at BangGood.com
* NodeMCU - An open-source firmware and development kit - https://www.nodemcu.com/index_en.html
* LUA - Programming lanuage - https://www.lua.org/
* PlatformIO - IOT Development platform - https://platformio.org/
  * Examples - https://github.com/platformio/platformio-examples
  * Source - https://github.com/platformio

```json
[env:esp12e]
platform = espressif8266
framework = arduino
board = esp12e
// monitor_speed = 115200
// build_flags = -D LED_BUILTIN=2
```

## options
* display when under the speed limit
* adjust trigger sound db level
* adjust briteness level
* adjust distance
* turn on access point option
* turn on wifi option

## other

```cpp
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
```


MAX7219/ESP8266
---------------
VCC/3.3V - GREEN
GND/Gnd - YELLOW
DIN/D7 - ORANGE
CS/D8 - RED
CLK/D5 - BROWN