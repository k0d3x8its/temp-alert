/******************************************************************************
* + Project: temp-alert                                                       *
* + Version: 0.6.0a                                                           *
* + Description: A MCU that alerts when temperature meets a threshold         *
* + Board: Feather M0 Basic Proto                                             *
* + Sensor: Generic DHT22/AM2302                                              *
* + Module: N/A                                                               *
* + Author: K0d3x 8its                                                        *
* + Date: September 26, 2024                                                  *
* + License: MIT                                                              *
*******************************************************************************
  + Inspired by: Duckman | https://busyducks.com/ascii-art-arduino-pinouts/
  + Designed by: K0d3x   | https://github.com/k0d3x8its
*******************************************************************************
* Arduino = Ar.Pin *       -----[      ]-----             * VUSB = VIN | 5VDC *
********************   [ ]-|RST          ____|            *********************
*   MAX output 400mA = [ ]-|3V3         | __ |                                *
*                      [ ]-|AREF        | __ |-[ ] = 3.7V Battery             *
*                      [ ]-|GND         |____|                                *
*              Ar.14 = [ ]-|A0            BAT|-[ ] = LiPo                     *
*              Ar.15 = [ ]-|A1             EN|-[ ]                            *
*              Ar.16 = [ ]-|A2           VUSB|-[ ] = VBUS                     *
*              Ar.17 = [ ]-|A3      *     D13|-[ ]                            * 
*              Ar.18 = [ ]-|A4   Feather  D12|-[ ]                            * 
*              Ar.19 = [ ]-|A5  M0 Proto  D11|-[ ] ~                          * 
*        SCK = Ar.24 = [ ]-|D24 o o o o o D10|-[ ] ~                          *
*       MOSI = Ar.23 = [ ]-|D23 o o o o o  D9|-[ ] ~                          * 
*       MISO = Ar.22 = [ ]-|D22 o o o o o  D6|-[ ]                            *
*                RX--> [ ]-|D0  o o o o o  D5|-[*] ~ ===> DHT22               * 
*                TX <--[ ]-|D1  o o o o o SCL|-[ ] = Ar.21                    * 
*                      [*]-|GND o o o o o SDA|-[ ] = Ar.20                    * 
*                           \_______________/                                 *                           
*                                                                             *                               
*******************************************************************************
    ******************     Feather Huzzah Overview      ******************  
*******************************************************************************
   ****** https://learn.adafruit.com/adafruit-feather-m0-basic-proto ******
*******************************************************************************
*******************************************************************************
      ******************      DHT22 Datasheet      ******************  
*******************************************************************************
 *** https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf ***
******************************************************************************/
#include <Arduino.h>                    // Arduino library
#include <Adafruit_GFX.h>               // OLED display graphics library
#include <Adafruit_SH110X.h>            // OLED driver library
#include <DHT.h>                        // library for interacting with sensor
#include <Adafruit_Sensor.h>            // Unified sensor interface 

#define DHTPIN 5                        // PWM connected to DHT data pin
#define DHTTYPE DHT22                   // Define sensor type as DHT22

DHT dht(DHTPIN, DHTTYPE);               // Initialize the DHT sensor object

// Initialize the OLED display
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire); 

const int dataSamples = 10;             // Number of samples to average
float tempSamplesC[dataSamples];        // Array to store temperature samples in Celsius
float tempSamplesF[dataSamples];        // Array to store temperature samples in Fahrenheit
float humiditySamples[dataSamples];     // Array to store humidity samples 

unsigned long lastSampleTime = 0;       // Time for Sampling
unsigned long samplingInterval = 5000;  // Five second intervals (adjustable)

void setup() {
  Serial.begin(115200);                 // Start serial comms for debugging

  dht.begin();                          // Intialize DHT sensor

// Intialize OLED display
  if (!display.begin(0x3C, true)) {
    Serial.println("OLED failed to initialize");
    while (1);                          // If the display fails to initialize, stop program
  }

  display.display();                    // Show the initial display screen
  delay(2000);                          // Pause for two second
  display.clearDisplay();               // Clear the display
  display.setTextSize(1);               // Set text size to smallest size
  display.setTextColor(SH110X_WHITE);   // Set the text color to white

  // Initialize sample arrays to zero
  for (int dataCollected = 0; dataCollected < dataSamples; dataCollected++) {
    tempSamplesC[dataCollected] = 0;
    tempSamplesF[dataCollected] = 0;
    humiditySamples[dataCollected] = 0;
  }
}

void loop() {
  // Check if specified time has elapsed
  if (millis() - lastSampleTime >= samplingInterval){ 
    lastSampleTime = millis();          // Update last sample time
      // Shift the previous samples - rolling window of samples
    for (int dataCollected = 1; dataCollected < dataSamples; dataCollected++) {
      tempSamplesC[dataCollected - 1] = tempSamplesC[dataCollected];
      tempSamplesF[dataCollected - 1] = tempSamplesF[dataCollected];
      humiditySamples[dataCollected - 1] = humiditySamples[dataCollected]; 
    }

    // Take temperature and humidity readings
    float newTempC = dht.readTemperature();     // Read temperature in Celsius
    float newTempF = dht.readTemperature(true); // Read temperature in Fahrenheit
    float newHumidity = dht.readHumidity();     // Read humidity in percentage   

    // Add the new samples to the arrays
    tempSamplesC[dataSamples - 1] = newTempC;
    tempSamplesF[dataSamples - 1] = newTempF;
    humiditySamples[dataSamples - 1] = newHumidity;

    // calculate the averages
    float avgTempC = 0;
    float avgTempF = 0;
    float avgHumidity = 0;
  }
}