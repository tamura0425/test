#include <SPI.h>
#include <Ethernet2.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_ADDRESS 0x3C // 0x3C or 0x3D
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// APIキー
char APIKey[] = "2aaa6df02d319ee7e041582e4bd87234";

// OpenWeatherMap APIのエンドポイント
char server[] = "api.openweathermap.org";
char path[] = "/data/2.5/weather";
char cityId[] = "Nagoya";
char units[] = "metric";

EthernetClient client;

int RecvStart = 0;

void setup() {
//  Serial.begin(9600);
  // Ethernet初期化
  delay(1000);
  byte mac[] = { 0xA8, 0x61, 0x0A, 0xAE, 0x94, 0x77 };
  byte ip[] = { 192, 168, 0, 85 };
  Ethernet.begin(mac,ip);
  //画面表示
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();

  delay(1000);

  // APIリクエストの送信
  if (client.connect(server, 80)) {
    RecvStart = 1;
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
    // Serial.println("Connection failed");
  }
}

char Text[16];
char TextPt = 0;
char TextMode = 0;

void loop() {

  if(RecvStart == 1){
    if (client.available()) {
      char c = client.read();
      //Serial.print(c);
      if(TextMode < 3){
        if(TextPt < 15){
          Text[TextPt++] = c;
        }
      }
      if(c == '\"'){
        switch(TextMode){
        case 0:
          TextPt = 0;
          if((Text[0] == 'm') && (Text[1] == 'a') && (Text[2] == 'i') && (Text[3] == 'n')) TextMode = 1;
          break;
        case 1:
          TextPt = 0;
          TextMode = 2;
          break;
        case 2:
          Text[--TextPt] = '\0';
          TextMode = 3;
          break;
        }
      } 
    }
    if (!client.connected()) {
      // Serial.println();
      // Serial.println("Disconnecting");
      client.stop();
      display.clearDisplay();
      display.setCursor(0,0);
      display.setTextSize(2);
      display.println(Text);
      display.display();
      RecvStart = 0;      
    }
  }

}
