#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include "certificate.h"

/* --- CONFIGURATION --- */
const char* ssid = "####SSID####";
const char* password = "####PASS####";

const char* mqtt_server = "####MQTT_HOST####";
const int mqtt_port = 8443;
const char* mqtt_topic = "FABLAB_21_22/stm32N6/person_count";
const char* mqtt_client_id = "STM32N6_Client";
const char* mqtt_user = "####MQTT_USER####";
const char* mqtt_pass = "####MQTT_PASS####";

/* --- GLOBALS --- */
BearSSL::WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Static IP if needed (comment out if DHCP is fine) */
  IPAddress ip(192, 168, 0, 50);
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress dns(8, 8, 8, 8);
  WiFi.config(ip, gateway, subnet, dns);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setDateTime() {
  configTime(1 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.print("Waiting for NTP time sync: ");
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.print("Current time: ");
  Serial.print(asctime(&timeinfo));
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(mqtt_client_id, mqtt_user, mqtt_pass)) {
      Serial.println("connected");
      client.publish(mqtt_topic, "{\"status\":\"STM32 Gateway Connected\"}");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  /* IMPORTANT: Must match STM32 SoftSerial baud rate */
  Serial.begin(9600); 
  
  setup_wifi();
  setDateTime();

  /* Load Certificate */
  BearSSL::X509List *cert = new BearSSL::X509List(ca_cert);
  espClient.setTrustAnchors(cert);
  
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  /* Listen for data from STM32 */
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();
    
    /* Expected format: "COUNT:12" */
    if (line.startsWith("COUNT:")) {
      String countStr = line.substring(6);
      int count = countStr.toInt();
      
      char payload[128];
      snprintf(payload, sizeof(payload), 
               "{\"count\":%d,\"device\":\"STM32N6\",\"source\":\"serial_bridge\"}", 
               count);
      
      Serial.print("Publishing: ");
      Serial.println(payload);
      
      if (client.publish(mqtt_topic, payload)) {
        Serial.println(">> OK");
      } else {
        Serial.println(">> FAIL");
      }
    }
  }
}
