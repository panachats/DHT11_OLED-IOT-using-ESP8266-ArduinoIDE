#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


Adafruit_SSD1306 OLED = Adafruit_SSD1306(128, 32);

float temp;
float hum;
DHT dht11(D4,DHT11);

void setup() {
  temp = 0;
  hum = 0;
  Serial.begin(9600);
  dht11.begin();
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  OLED.clearDisplay();
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
  OLED.setCursor(5,0);
}

void loop() {
  temp = dht11.readTemperature();
  hum = dht11.readHumidity();
  
  OLED.clearDisplay(); 
  OLED.setCursor(0,0);
  OLED.print("Temp: ");
  OLED.print(temp);
  OLED.println(" C");
  OLED.print("Humidity: ");
  OLED.print(hum);
  OLED.println("%");
  OLED.display(); 
  delay(1000); 
}
