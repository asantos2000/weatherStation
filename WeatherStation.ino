
#include <Bridge.h>
#include <BridgeSSLClient.h>
#include <ArduinoCloud.h>


// Arduino Cloud settings and credentials
const char userName[]   = "adsantos";
const char thingName[] = "WeatherStation";
const char thingId[]   = "92c46ff8-bab2-46ce-bbc4-3bc1a0938641";
const char thingPsw[]  = "caa03c3a-cfdb-4ef7-bd4b-e6fd43f66464";


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
