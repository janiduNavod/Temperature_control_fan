#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <PIDController.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHT11PIN 18
#define FAN_PIN 2

DHT dht(DHT11PIN, DHT11);
PIDController pid;

void setup() {
  Serial.begin(115200);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

  pinMode(FAN_PIN, OUTPUT);

  pid.begin();
  pid.setpoint(25); // Desired temperature setpoint
  pid.tune(8, 55, 41); // PID constants (Kp, Ki, Kd)
  pid.limit(0, 255); // Limit output to match PWM range
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  // Print temperature and humidity for Serial Plotter
  Serial.print(temp);
  Serial.print(",");
  Serial.println(humi);

  // Compute PID output
  int fanSpeed = pid.compute(temp);

  // Control the fan based on PID output
  analogWrite(FAN_PIN, fanSpeed);

  // Display temperature on OLED
  display.setTextColor(WHITE);
  display.setCursor(0, 24);
  display.setTextSize(3);
  display.print(temp);
  display.println("C");
  display.display();
  delay(100);
  display.clearDisplay();

  delay(1000);
}
