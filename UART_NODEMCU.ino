#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>



#define D5 (14)
#define D6 (12)
#define TX (1)

SoftwareSerial NodeMCU(D5,D6);

void setup(){
	Serial.begin(9600);
	NodeMCU.begin(4800);
	pinMode(D5,INPUT);
	pinMode(D6,OUTPUT);
}

void loop(){
while(NodeMCU.available()>0){
  float val = NodeMCU.parseFloat();
  if(NodeMCU.read()== '\n'){
  Serial.println(val);
  }
}
delay(30);
}