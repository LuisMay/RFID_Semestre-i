#include <ESP8266WiFi.h> //Librería de NodeMCU
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

//Configuración internet//
const char* ssid = "SSID"; // Rellena con el nombre de tu red WiFi
const char* password = "Contraseña"; // Rellena con la contraseña de tu red WiFi
 
const char* host = "api.tanque.com";
const char* apiKey = " clave API "; 

// Huella digital del certificado del servidor 
const char * fingerprint = "a9 1f b9 fe 35 b8 38 b9 54 67 e7 34 52 8a 24 d4 17 29 fa 32";
//----------------------//

//Variables para lector//
int tanqueID=0;
//---------------------//

//Serial

void setup() {

  s.begin(115200);
  delay(10);
 
  // Conectamos a la red WiFi
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  /* Configuramos el ESP8266 como cliente WiFi. Si no lo hacemos 
  se configurará como cliente y punto de acceso al mismo tiempo */
  WiFi.mode(WIFI_STA); // Modo cliente WiFi
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
}
 
void loop() {
  
  tanqueID = obtainingID();
  
  Serial.print("connecting to ");
  Serial.println(host);

  /* 
  // Creamos el cliente
  WiFiClientSecure client;
  const int httpPort = 443; // Puerto HTTPS
  if (!client.connect(host, httpPort)) {
    // ¿hay algún error al conectar?
    Serial.println("Ha fallado la conexión");
    return;
  }
 
  // Verificamos que el certificado coincide con el esperado
  if(client.verify(fingerprint,host)){
    Serial.println("El certificado es correcto"); 
  } else {
    Serial.println("Error de certificado"); 
  }
  */

  // Creamos la URL para la petición
  
  String url = "/api/";
  url += apiKey;
  url += tanqueID;
  url += ".json";

 //Enviamos por bluetooth
  s.write(123);
  Serial.print("URL de la petición: https://");
  Serial.print(host);
  Serial.print(":");
  //Serial.print(httpPort);
  Serial.println(url);

  /*
  // Enviamos la petición
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Superado el tiempo de espera !");
      client.stop();
      return;
    }
  }

  // Consutar la memoria libre
  // Utilizando HTTPS se necesitan unos 20 kB de memoria libres adicionales
  Serial.printf("\nMemoria libre en el ESP8266: %d Bytes\n\n",ESP.getFreeHeap());
 
  // Leemos la respuesta y la enviamos al monitor serie
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println(); 
  */
}

int obtainingID(){
  Serial.print("El tanqueID es: ");
  Serial.print(tanqueID);
  Serial.println();
  while (tanqueID == 0){

  
  }
  Serial.print("El tanqueID es: ");
  Serial.print(tanqueID);
  Serial.println();
  return tanqueID;
}