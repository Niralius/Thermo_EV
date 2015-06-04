// Compliments of Michael
// May 2015

#include <SPI.h>
#include "Adafruit_MAX31855.h"

#define DO1 5
#define DO2 2
#define CS 4
#define CLK 3
Adafruit_MAX31855 thermocouple1(CLK, CS, DO1);
Adafruit_MAX31855 thermocouple2(CLK, CS, DO2);

void setup() {
  Serial.begin(9600);
  Serial.println("MAX31855 test");
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
//   Serial.print("Internal Temp = ");
//   Serial.println(thermocouple.readInternal());

   double c1 = thermocouple1.readCelsius();
   double c2 = thermocouple2.readCelsius();
   if (isnan(c1)) {
     Serial.println("Something wrong with thermocouple 1!");
   } else if (isnan(c2)){
     Serial.println("Something wrong with thermocouple 2!");
   } else {
     Serial.print("1: C = "); 
     Serial.println(c1);
     Serial.print("2: C = "); 
     Serial.println(c2);
   }
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFarenheit());
   
 
   delay(1000);
}
