

//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "shikha"  // Replace with your network credentials
#define STAPSK  "1234512345"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

#define PIN_LED 14
int a,b,c,d,e,f,g,h,i;
hw_timer_t * timer = NULL;
volatile uint8_t led_state = 0;

void IRAM_ATTR timer_isr(){
  led_state = ! led_state;
  digitalWrite(PIN_LED, led_state);
}

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(2, OUTPUT);
  timer = timerBegin(0, 40, true);
  timerAttachInterrupt(timer, &timer_isr, true);
  timerAlarmWrite(timer, 65536, true);
  timerAlarmEnable(timer);

}

void loop() {
  OTAloop();

a = timerRead(timer);
b = timerRead(timer);
c = 32768;
d = 16384;
e = a&c;
h = e>>15;
f = b&d;
i = f>>14;
g = h|i;
digitalWrite(2 ,g);
}


