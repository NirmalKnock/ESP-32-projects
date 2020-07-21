#include<ThingSpeak.h>
#include<WiFi.h>
//Your wifi and password
const char ssid[]="your ssid here";
const char password[]="Your password";

//Thing speak configuration
const unsigned long channel_id=  ; //your channel id here
const char write_api_key[]="Your API key";
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
  //generate random numbers
   int random_no= random(0,100);
   Serial.println("Posting :"+String(random_no) +" to ThingSpeak");
   ThingSpeak.setField(1,random_no);
   ThingSpeak.writeFields(channel_id,write_api_key);
   (10000);

}
