#include<WiFi.h>
//Your Wifi SSID and Password below
const char ssid[]="nirmal kumar";   //SSID
const char password[]="nirmal@1234"; // Password
void setup(){
  // Initialize serial
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
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(WiFi.localIP());
  delay(1000);
  

}
