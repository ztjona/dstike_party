#include <Arduino.h>
#include <definitions.h> // Core graphics library by Adafruit

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ----------------
  pinMode(LED_HIGHLIGHT, OUTPUT);

  pinMode(BUTTON_PRESS, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  // ----
  tft.init(240, 240); // initialize a ST7789 chip, 240x240 pixels

  tft.fillScreen(MAGENTA);
  delay(200);

  tft.invertDisplay(true);

  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(RED);
  tft.setTextSize(6);
  tft.println("Jona!");
  
  // pixel
  pixel.begin();
  pixel.setBrightness(10);
  pixel.show(); // Initialize all pixels to 'off'
}

bool toogleLed = false;
void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("hola, JonaXD");

  if (toogleLed)
    digitalWrite(LED_HIGHLIGHT, HIGH);
  else
    digitalWrite(LED_HIGHLIGHT, LOW);

  toogleLed = !toogleLed;

  if (!digitalRead(BUTTON_LEFT))
  {
    pixel.setPixelColor(0, pixel.Color(0, 0, 127));
    buzzer.beep(Buzzer::ToneType::middle);
  }

  if (!digitalRead(BUTTON_RIGHT))
  {
    buzzer.beep(Buzzer::ToneType::wrong);
    pixel.setPixelColor(0, pixel.Color(127, 0, 0));
  }

  if (!digitalRead(BUTTON_PRESS))
  {
    pixel.setPixelColor(0, pixel.Color(255, 0, 0));
    buzzer.beep(Buzzer::ToneType::ok);
  }

  pixel.show();
  delay(500);
}
