#include <SPI.h>
#include <Ethernet2.h>
#include <Wire.h>

// APIキー
char APIKey[] = "2aaa6df02d319ee7e041582e4bd87234";

// OpenWeatherMap APIのエンドポイント
char server[] = "api.openweathermap.org";
char path[] = "/data/2.5/weather";
char cityId[] = "Tokyo";
char units[] = "metric";

EthernetClient client;

void setup() {
  Serial.begin(9600);
  
  // Ethernet初期化
  // delay(1000);
  // Serial.println( Ethernet.begin("A8:61:0A:AE:94:77") );
  // Serial.println(Ethernet.localIP());
  // Serial.println(Ethernet.subnetMask());
  // Serial.println(Ethernet.gatewayIP());
  // Serial.println(Ethernet.dnsServerIP());
  // Ethernet初期化
  delay(1000);
  byte mac[] = { 0xA8, 0x61, 0x0A, 0xAE, 0x94, 0x77 };
  byte ip[] = { 192, 168, 0, 85 };
  Ethernet.begin(mac,ip);
  Serial.println(Ethernet.localIP());
  Serial.println(Ethernet.subnetMask());
  Serial.println(Ethernet.gatewayIP());
  Serial.println(Ethernet.dnsServerIP());
  
  // APIリクエストの送信
  if (client.connect(server, 80)) {
    client.print("GET ");
    client.print(path);
    client.print("?q=");
    client.print(cityId);
    client.print("&units=");
    client.print(units);
    client.print("&appid=");
    client.print(APIKey);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  
  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting");
    client.stop();
    for(;;);
  }
}
