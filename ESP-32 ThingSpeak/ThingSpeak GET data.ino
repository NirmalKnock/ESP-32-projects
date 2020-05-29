#include<ThingSpeak.h>
#include<WiFi.h>
//Your wifi and password
const char ssid[]="YOUR SSID";
const char password[]="YOUR PASSWORD";

//Thing speak configuration
const unsigned long channel_id=  here ; //your channel id here
const char read_api_key[]="YOUR READ API KEY";
// wifi object
WiFiClient client;

void setup() {
Serial.begin(9600);
delay(100);
  // connect wifi
Serial.print("connecting to wifi");
Serial.print("ssid");
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println();
//Show connected
Serial.println("connected");
ThingSpeak.begin(client);
randomSeed(micros());
}

void loop() {
  //get latest numbers from thingspeak
    int datavalue=ThingSpeak.readIntField(channel_id,1,read_api_key);
    Serial.print("data:");
    Serial.print(datavalue);
    Serial.println();
    delay(5000);
  
}
