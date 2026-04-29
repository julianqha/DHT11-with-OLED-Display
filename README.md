# DHT11 with OLED Display

## What you need:

- 1x [ESP32 Developer Module](https://de.aliexpress.com/item/1005007977096529.html) with minimum:
  - 1x USB data transfer cable  
  - 1x 3.3V pin  
  - 1x 5V/VIN pin  
  - 3x GND pins  
  - 9x GPIO pins  

- 1x [Breadboard](https://de.aliexpress.com/item/1005006139490896.html) 

- 1x [OLED Display](https://de.aliexpress.com/item/32913603885.html)  
  - Interface: I2C  
  - Controller: SH1106  
  - Voltage: 3.3V – 5V compatible  

- 1x [DHT11 Temperature and Humidity Sensor](https://de.aliexpress.com/item/33048949797.html)  

- [LEDs](https://de.aliexpress.com/item/1005010338676055.html):
  - 2x Blue  
  - 2x Red  
  - 2x Green  

- 6x [Resistors](https://de.aliexpress.com/item/1005006189547427.html) (220Ω – 330Ω)  
- 20x [Jumper wires](https://de.aliexpress.com/item/4000204858217.html)

- Computer / Laptop  
- [CP210x USB to UART Bridge VCP Driver](https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers)
- [Arduino IDE](https://docs.arduino.cc/software/ide/) or [PlatformIO](https://platformio.org/)

---

## Description

This program reads temperature and humidity data from a DHT11 sensor every 2 seconds.  
If the reading fails, an error message is printed to the Serial Monitor.

The measured values are then shown on an OLED display using the GyverOLED library.

Additionally, the system uses LEDs to indicate different conditions:

### Humidity:
- below 35% → red LED turns on  
- above 70% → blue LED turns on  
- between 35% and 70% → green LED turns on  

### Temperature:
- above 27°C → red LED turns on  
- below 17°C → blue LED turns on  
- between 17°C and 27°C → green LED turns on  
