/*
This is a simple example to test the BH1750 Light sensor

Connect the sensor to a NodeMCU ESP8266:
VCC <-> 3V3 [grey]
GND <-> Gnd [purple]
SDA <-> D2 [green]
SCL <-> D1 [blue]
ADDR <-> RX [yellow]
*/

#include <Wire.h>
#include <BH1750FVI.h>

// Settings

BH1750FVI::eDeviceAddress_t DEVICEADDRESS = BH1750FVI::k_DevAddress_L;
BH1750FVI::eDeviceMode_t DEVICEMODE = BH1750FVI::k_DevModeContHighRes;

// Create the Lightsensor instance
BH1750FVI LightSensor(ADDRESSPIN, DEVICEADDRESS, DEVICEMODE);

void setup()
{
Serial.begin(9600);
LightSensor.begin();
Serial.println("Running...");
}

void loop()
{
uint16_t lux = LightSensor.GetLightIntensity();
Serial.print("Light level: ");
Serial.println(lux);
delay(2000);
}
