#include<math.h>
#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include"libr.h"

AsyncWebServer server(80);

const char* ssid = "OnePlus7";
const char* password = "Starz123";

const char* input_parameter1 = "input1";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>UNIT VECTOR COMPUTATION</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 2.0rem; color: blue;}
  </style> 
  </head><body>
  <h2>TO FIND IF THE SUM OF TWO UNIT VECTORS IS A UNIT VECTOR</h2> 
  <form action="/get">
    Enter the angle (in degrees) between the unit vectors a and b: <input type="number" name="input1">
    <input type="submit" value="Submit">
    

  </form><br>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connecting...");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    double A,B,C,D,E;
    A=load_num(request,input_parameter1);
    if(A >180){
    E = 360-A;
    }
    else{
    E=A;
    }
    B=rad(E);
    C= cos(B);
    D= cos((2*M_PI)/3);


	//request->send(200, "text/html", "Resultant : "+String(C)+" <br><a href=\"/\">Return to Home Page</a>");
     if( D == C){
 request->send(200, "text/html", "Resultant vector is a unit vector <br><a href=\"/\">Return to Home Page</a>");
	}
	else{
     request->send(200, "text/html", "Resultant vector is not a unit vector <br><a href=\"/\">Return to Home Page</a>");
	}

  });		
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
  
}
