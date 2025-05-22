#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Button pins
#define BUTTON1 PA0
#define BUTTON2 PA1
#define BUTTON3 PA2
#define BUTTON4 PA3

void setup() {
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (1);
  }

  showStartScreen();

  // Set buttons as input with pull-up
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON1) == LOW) {
    showMessage("Starting", "Voice Chat");
    delay(300);
  }

  if (digitalRead(BUTTON2) == LOW) {
    showMessage("Scrolling", "Down!");
    delay(300);
  }

  if (digitalRead(BUTTON3) == LOW) {
    showMessage("Scrolling", "Up");
    delay(300);
  }

  if (digitalRead(BUTTON4) == LOW) {
    showMessage("Restarting", "...");
    delay(800);
    showStartScreen();
    delay(300);
  }
}

void showMessage(String line1, String line2) {
  display.clearDisplay();
  display.setTextSize(2);  // Bigger text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(line1);
  display.setCursor(0, 24);  // move down for second line
  display.println(line2);
  display.display();
}

void showStartScreen() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Navigate");
  display.setCursor(0, 20);
  display.println("Via");
  display.setCursor(0, 40);
  display.println("Buttons");
  display.display();
}
