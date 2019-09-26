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
[env:esp32doit-devkit-v1]
platform = espressif32
framework = arduino
board = esp32doit-devkit-v1
monitor_speed = 115200
build_flags = -D LED_BUILTIN=2
```

