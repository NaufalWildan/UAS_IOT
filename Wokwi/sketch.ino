// This example uses an ESP32 Development Board
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://www.shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <WiFi.h>
#include <MQTT.h>
#include "DHT.h"1

#define DHTPIN 15
#define LEDPINBED 12
#define DHTTYPE DHT22
#define LEDPINBATH 14
#define LEDPINLIVING 13
#define LEDPINKITCHEN 27
DHT dht(DHTPIN,DHTTYPE);

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

WiFiClient net;
MQTTClient client;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("msg","kelompokgacor","EgUEPi589mvvgNhO")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("uas/iot/led/bed");
  client.subscribe("uas/iot/led/bath");
  client.subscribe("uas/iot/led/living");
  client.subscribe("uas/iot/led/kitchen");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if(payload[0] == '1' && topic == "uas/iot/led/bed"){
    digitalWrite(LEDPINBED, HIGH);
  }else{
    digitalWrite(LEDPINBED, LOW);
  }
  if(payload[0] == '1' && topic == "uas/iot/led/bath"){
    digitalWrite(LEDPINBATH, HIGH);
  }else{
    digitalWrite(LEDPINBATH, LOW);
  }
  if(payload[0] == '1' && topic == "uas/iot/led/living"){
    digitalWrite(LEDPINLIVING, HIGH);
  }else{
    digitalWrite(LEDPINLIVING, LOW);
  }
  if(payload[0] == '1' && topic == "uas/iot/led/kitchen"){
    digitalWrite(LEDPINKITCHEN, HIGH);
  }else{
    digitalWrite(LEDPINKITCHEN, LOW);
  }
  
  

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  pinMode(LEDPINBED, OUTPUT);
  pinMode(LEDPINBATH, OUTPUT);
  pinMode(LEDPINLIVING, OUTPUT);
  pinMode(LEDPINKITCHEN, OUTPUT);
  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin("kelompokgacor.cloud.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  //suhu
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp,msg,10));
  client.publish("uas/iot/suhu/bed",msg);
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp+1,msg,10));
  client.publish("uas/iot/suhu/bath",msg);
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp+2,msg,10));
  client.publish("uas/iot/suhu/living",msg);
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp+3,msg,10));
  client.publish("uas/iot/suhu/kitchen",msg);
  


  //lem
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum,msg,10));
  client.publish("uas/iot/kelembapan/bed",msg);
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum+1,msg,10));
  client.publish("uas/iot/kelembapan/bath",msg);
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum+2,msg,10));
  client.publish("uas/iot/kelembapan/living",msg);
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum+3,msg,10));
  client.publish("uas/iot/kelembapan/kitchen",msg);
  delay(2000);
}