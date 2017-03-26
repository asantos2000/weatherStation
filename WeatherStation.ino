
#include <Bridge.h>
#include <BridgeSSLClient.h>
#include <ArduinoCloud.h>


// Arduino Cloud settings and credentials
const char userName[]   = "adsantos";
const char thingName[] = "WeatherStation";
const char thingId[]   = "your-thing-id";
const char thingPsw[]  = "your-thing-pwd";


BridgeSSLClient sslClient;


// build a new object "WeatherStation"
ArduinoCloudThing WeatherStation;


void setup() {
  Serial.begin (9600);

  Serial.println("Starting Bridge");
  Bridge.begin();
  Serial.println("Done");


  WeatherStation.begin(thingName, userName, thingId, thingPsw, sslClient);
  WeatherStation.enableDebug();
  // define the properties
  WeatherStation.addProperty("cloudLedStatus", STATUS, R);
  WeatherStation.addProperty("Humidity", FLOAT, R, TIMED, 30);
  WeatherStation.addProperty("Lux", FLOAT, R, TIMED, 30);
  WeatherStation.addProperty("Temperature", FLOAT, R, TIMED, 30);
  WeatherStation.addProperty("UvIndex", FLOAT, R);
  
}

void loop() {
  WeatherStation.poll();

  WeatherStation.writeProperty("cloudLedStatus", "oh...");
  WeatherStation.writeProperty("Humidity", "oh...");
  WeatherStation.writeProperty("Lux", "oh...");
  WeatherStation.writeProperty("Temperature", "oh...");
  WeatherStation.writeProperty("UvIndex", "oh...");
  
  delay(1000);
  WeatherStation.writeProperty("cloudLedStatus", "yeah!");
  WeatherStation.writeProperty("Humidity", "yeah!");
  WeatherStation.writeProperty("Lux", "yeah!");
  WeatherStation.writeProperty("Temperature", "yeah!");
  WeatherStation.writeProperty("UvIndex", "yeah!");
  
  delay(1000);
}
