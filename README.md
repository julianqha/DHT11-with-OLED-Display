# DHT11-with-OLED-Display
The program reads temperature and humidity data from a DHT11 sensor every 2 seconds.
If the reading fails, an error message is printed to the Serial Monitor.

The measured values are then shown on an OLED display using the GyverOLED library.

Additionally, the system uses LEDs to indicate different conditions:

Humidity:
below 35% → red LED turns on
above 70% → blue LED turns on
otherwise → green LED turns on
Temperature:
above 27°C → red LED turns on
below 17°C → blue LED turns on
otherwise → green LED turns on
