//include library packages

#include <GyverOLED.h>
#include <SimpleDHT.h>
#include <Wire.h> 


//creating variables

int gruen = 16;
int blau = 23;
int rot = 15;
int gruen2 = 18;
int blau2 = 17;
int rot2 = 19;
int pinDHT11 = 14;

SimpleDHT11 dht11(pinDHT11);
GyverOLED<SSH1106_128x64> oled;

void setup() {
  Serial.begin(9600);
  oled.init();
  oled.clear();

  pinMode(gruen, OUTPUT);
  pinMode(gruen2, OUTPUT);
  pinMode(blau, OUTPUT);
  pinMode(blau2, OUTPUT);
  pinMode(rot, OUTPUT);
  pinMode(rot2, OUTPUT);
}

void loop() {
  delay(2000);
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }


  //OLED display style

  oled.setScale(3);
  oled.setCursor(0,0);
  oled.print("==");
  oled.setCursor(38,0);
  //oled.print("Humidity:"); (optional: print Humidity:xx instead of just the number.)
  oled.print(humidity);
  oled.setCursor(75,0);
  oled.print("%===");
  oled.setCursor(0,5);
  oled.print("==");
  oled.setCursor(38,5);
  //oled.print("Temperature:"); (optional: print Temperature:xx instead of just the number.)
  oled.print(temperature);
  oled.setCursor(75,5);
  oled.print("C===");
  oled.update();


  //set all LEDs to LOW

digitalWrite(rot, LOW);
digitalWrite(blau, LOW);
digitalWrite(gruen, LOW);
digitalWrite(rot2, LOW);
digitalWrite(blau2, LOW);
digitalWrite(gruen2, LOW);


  //define different conditions for the LEDs

  if (humidity < 35){
    digitalWrite(rot, HIGH);
  }
  else 
    if (humidity > 70){
      digitalWrite(blau, HIGH);
  }
  else{
    digitalWrite(gruen, HIGH);
  }

  if (temperature > 27){
    digitalWrite(rot2, HIGH);
  }
  else 
    if (temperature < 17){
      digitalWrite(blau2, HIGH);
  }
  else{
    digitalWrite(gruen2, HIGH); 
  } 
}
