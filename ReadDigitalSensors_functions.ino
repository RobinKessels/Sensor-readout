#include <DHT.h>
#include "Wire.h"
#include <DHT_U.h>
#include <Sparkfun_APDS9301_Library.h>
#include "AS726X.h"

// pin mapping of NodeMCU ESP8266
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

#define DHTPIN D3
#define DHTTYPE DHT22
#define timeDelay 1000
DHT dht(DHTPIN, DHTTYPE);
APDS9301 apds;
AS726X as726X;

float getTemperature_DHT();
float getHumidity_DHT();
float getLux();
float getTemperature_as726X();
float* getSpectrum();
float spectrum[6];

void setup() {
  delay(5);
  apds.begin(0x39);
  dht.begin();
  Wire.begin(D2, D1);
  as726X.begin();
}

float getTemperature_DHT() {
  return dht.readTemperature(false, false);
}

float getHumidity_DHT(){
  return dht.readHumidity();
}

float getLux() {
  return apds.readLuxLevel();
}

float getTemperature_as726X() {
  return as726X.getTemperature();
}

float* getSpectrum() {
  spectrum[0] = as726X.getCalibratedViolet();
  spectrum[1] = as726X.getCalibratedBlue();
  spectrum[2] = as726X.getCalibratedGreen();
  spectrum[3] = as726X.getCalibratedYellow();
  spectrum[4] = as726X.getCalibratedOrange();
  spectrum[5] = as726X.getCalibratedRed();

  return spectrum;
}

void loop(){
  /*
  Serial.println(getTemperature_DHT());
  float* myF;
  myF = getSpectrum();
  Serial.println(myF[0]);
  Serial.println(myF[1]);
  Serial.println(myF[2]);

  delay(2000);
  */
}

