/******************************************************************************
* + Project: temp-alert                                                       *
* + Version: 0.1.0                                                            *
* + Description: A MCU that alerts when temperature meets a threshold         *
* + Board: Feather M0 Basic Proto                                             *
* + Sensor: DHT22/AM2302                                                      *
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
*                RX--> [ ]-|D0  o o o o o  D5|-[ ] ~                          * 
*                TX <--[ ]-|D1  o o o o o SCL|-[ ] = Ar.21                    * 
*                      [ ]-|GND o o o o o SDA|-[ ] = Ar.20                    * 
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
#include <Arduino.h>                  // Arduino library
#include <Adafruit_GFX.h>             // OLED display graphics library
#include <Adafruit_SH110X.h>          // OLED driver library
#include <DHT.h>                      // library for interacting with sensor
#include <Adafruit_Sensor.h>          // Unified sensor interface 

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}