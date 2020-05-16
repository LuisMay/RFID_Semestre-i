#include <ESP8266WiFi.h>

//Put your SSID & Password//
const char* ssid = "INFINITUM15C4_2.4"; // Rellena con el nombre de tu red WiFi
const char* password = "LvyPTDBn2L"; // Rellena con la contraseña de tu red WiFi


 //IP 192.168.1.67   192.168.1.66
const char* host = "192.168.1.66";

//Variables para lector//
String pelota = "12343";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  // Conectamos a la red WiFi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Esperamos a que estemos conectados a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); // Mostramos la IP

  //Impresión MAC addres
  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() 
  
{
  
  if (client.connect(host,3000))     // "184.106.153.149" or api.thingspeak.com
  
  { 
  String content = pelota;

   client.print(String("POST /") + " HTTP/1.1\r\n"+
                "Host: " + host + "\r\n" + 
                content + "\r\n" +
                "Connection: close\r\n\r\n");
                
 // client.print(String("POST /") + " HTTP/1.1\r\n"+
   //             "Host: " + host + "\r\n" + 
     //           "Accept: */*\r\n"+
       //         "Content-Length: " + content.length()+"\r\n" +
         //       "Content-Type: application/x-www-form-urlencoded"+"\r\n"+
           //     " " + "\r\n"
             //   + content);
                
    
  //  client.println("POST / HTTP/1.1");
   // client.println("Host:" + host);
   // client.println("Accept: */*");
  //  client.println("Content-Length: " + content.length());
   // client.println("Content-Type: application/x-www-form-urlencoded");
    //client.println();
    //client.println(content); 

              

              
    unsigned long timeout = millis();

    
    while (client.available() == 0) {
     
    if (millis() - timeout > 5000) {
      Serial.println(">>> Superado el tiempo de espera !");
      client.stop();
      return;
      }
    }

    while(client.available()){
      
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
    Serial.println("");
  }
}

