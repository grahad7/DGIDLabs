#include "L01.h"


void setup() {
  // Start the serial monitor at 115200 baud
  Serial.begin(115200);
  
  
  sensor_t sensor;
  dht.temperature(),getSensor(&sensor
  dht.humidity().getSensor(&sensor);

  dht.begin();
  bmo.begin();
  BH1750.begin(BH1750_TO_GROUND);
  

}

void loop() {
 
    // Polling the DHT and BMP Sensors using events
  sensors_event_t dhtTempEvent, dhtHumEvent, bmpEvent;
  dht.temperature().getEvent(&dhtTempEvent);
  dht.humidity().getEvent(&dhtHumEvent);
  bmp.getEvent(&bmpEvent);

  //Polling the BH sensor

  BH1750.start();
  float lux=BH1750.getLux();

  Serial.println("\n-");
  (!isnan(dhtTempEvent.temperature)) ? Serial.println("Temperature: " + String(dhtTempEvent.temperature) + "degC") : Serial.println("Temperature Sensor Disconnected");

  (!isnan(dhtHumEvent.relative_humidity)) ? Serial.println("Humidity: " + String(dhtHumEvent.relative_humidity) + " %") : Serial.println("Humidity Sensor Disconnected");

  (!isnan(bmpEvent.pressure)) ? Serial.println("Pressure: " + String(bmpEvent.pressure) + " hPa") : Serial.println("Pressure Sensor Disconnected");
 
  (!isnan(lux)) ? Serial.println("Light Intensity: " + String(lux) + "lux") : Serial.println("Lux Sensor Disconnected");

}
