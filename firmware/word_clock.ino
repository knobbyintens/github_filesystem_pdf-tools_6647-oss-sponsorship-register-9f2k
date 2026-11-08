// Word Clock No. 7 - ESP32-S2 display firmware
#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_NeoPixel.h>
#include <RTClib.h>

#define LED_PIN 18
#define LED_COUNT 96

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
RTC_DS3231 rtc;
WebServer server(80);

const char *kWords[][5] = {
  {"IT", "IS", "HALF", "TEN", "OCLOCK"},
  {"QUARTER", "TWENTY", "FIVE", "MINUTES", "PAST"},
};

uint8_t brightness = 90;

void renderMinute(uint8_t minute) {
  strip.clear();
  uint8_t slot = minute / 5;
  if (slot < LED_COUNT / 4) {
    strip.setPixelColor(slot * 3 + 1, strip.Color(brightness, brightness, brightness));
  }
  strip.show();
}

void handleRoot() {
  String page = "<html><body><h1>Word Clock No. 7</h1>";
  page += "<form action=\"/bright\"><input name=\"v\" value=\"";
  page += String(brightness);
  page += "\"><input type=\"submit\"></form></body></html>";
  server.send(200, "text/html", page);
}

void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("RTC not found");
  }
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
  DateTime now = rtc.now();
  renderMinute(now.minute());
  delay(500);
}
