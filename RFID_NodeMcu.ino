#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h> 



//Put your SSID & Password//
const char* ssid = "INFINITUM15C4_2.4"; // Rellena con el nombre de tu red WiFi
const char* password = "LvyPTDBn2L"; // Rellena con la contraseña de tu red WiFi
// IP 192.168.1.67   192.168.1.66
// const char* host = "192.168.1.66";
IPAddress ip(192, 168, 0, 107); //set static ip
IPAddress gateway(192, 168, 0, 1); //set getteway
IPAddress subnet(255, 255, 255, 0);//set subnet

WiFiServer server(3000);

//Variables para lector//
String content = "A01240483";

WiFiClient client;

void setup() {

  
  Serial.begin(9600);
  delay(1000);

 
  // Conectamos a la red WiFi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
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



void loop() {
  
  Core();
  Serial.println("I'm awake, but I'm going into deep sleep mode until RESET pin is connected to a LOW signal");

  if tiempo de inacvtivida = 100 s {
  ESP.deepSleep(0);
  }

}





//FUNCION SEPARADA DE LA CONEXION A CLIENTE
void Core () {

  
   if (client.connect(host,WiFiServer))     // "184.106.153.149" or api.thingspeak.com
   { 
  HTTPClient http;
  http.begin("http://192.168.1.66:" + WiFiServer);
  http.addHeader("Content-Type", "text/plain");
  int  httpCode=http.POST(content);
    unsigned long timeout = millis();
  
    while (client.available() == 0) {
    
    if (millis() - timeout > 5000) {
      Serial.println(">>> YA FUE MUCHO TIEMPO !");
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
  

