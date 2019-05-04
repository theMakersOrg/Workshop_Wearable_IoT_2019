/***
 * 
 *  
 * 
 * 
 */

// Include the correct display library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

// Temp Humidity sensor
#include "DHT.h"

// OLED display 
// D3 -> SDA
// D5 -> SCL
// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, D3, D5);

#define DEMO_DURATION 2000  //how long between asking the sensor for the current temp and humidity

////////////////////////////////
// Temp Humidity sensor
#include "DHT.h"

#define DHTPIN 4     // Pin D2 on the Wemos D1

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

float h, t;

long timeSinceLastModeSwitch = 0;

void setup() {
  Serial.begin(9600);

  dht.begin();

  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void drawTemperature() {
    // Font Demo1
    // create more fonts at http://oleddisplay.squix.ch/
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "theMakers.org");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 20, "Temp:");
    display.drawString(80, 20, String(t));
    display.drawString(0, 36, "Humidity:");
    display.drawString(80, 36, String(h));
}


void loop() {
  // clear the display
  display.clear();
  // draw the current demo method
  drawTemperature();
  display.display();

  if (millis() - timeSinceLastModeSwitch > DEMO_DURATION) {
    h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    t = dht.readTemperature();
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
    timeSinceLastModeSwitch = millis();
  }
  delay(10);
}
