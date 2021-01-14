//Libaries 
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>
#include "GY521.h"
#include <SPI.h>


//TeleArray Position
#define TeleID 0
#define TeleMissionTimeHour 1 //RTC Time set to UTC in format hh:mm:ss
#define TeleMissionTimeMin 2
#define TeleMissionTimeSec 3
#define TelePacket 4 //Number of times the telemetry has been transmitted
//#define TelePacketType 5 //ASVII character C for container S1 for science payload 1 and S2 for science payload 2
                         // since array is using float values (hard code the payload type). Skip TeleArray[5]
#define TeleAlt 6 //BMP Altitude
#define TelePressure 7 //BMP Pressure
#define TeleTemp 8 //BMP Temperature
#define TeleRotationRate 9 //Gyro Rotation Rate

#define TeleArrayLength 10 //Array Length
#define TeamID 1210 //Team ID


// Pin Declarations
#define deployPinA 7// release mechanism
#define deployPinB 8// release mechanism
#define buzzerPin 9 // check is payload needs buzzer

// Sensor Declarations
Adafruit_BMP280 bmp; 
RTC_DS3231 rtc;
GY521 sensor(0x69);


//Global Variables
int packetCount = 0;

// seperate the array in to 2 different arrays 
//(one integer and the second one is a float)
int TeleArray1[5];
float TeleArray2[TeleArrayLength];

long teleTime;
long teleTime2 = 0;
boolean hasReset = false;

// main loop
void setup() {
  Serial.begin(9600);
  setupFunctions(); 
  TeleArray1[TeleID] = TeamID;
  teleTime = millis();
  teleTime2 = millis();
}

void loop() {
  if (teleTime - teleTime2 > 1000){
    packetCount++;
    getData();
    transmitData();
    teleTime2 = millis();
  }
  teleTime = millis();
}
