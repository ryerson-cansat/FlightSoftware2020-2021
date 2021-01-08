// libraries 
#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();

// intialize variables
String incomingString = ""; // for incoming serial data


void setup() {

// intialize Serial port
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

// intialize BMP280

  if (!bmp.begin()) {
      Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
      while (1) delay(10);
  }
    
bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  bmp_temp->printSensorDetails();
  
}

void loop() {
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming string:
    incomingString = Serial.readString();
    // say what you got
    Serial.println(incomingString);
      

    if(incomingString == "CMD,1210,"){// check for command prompt and if team ID matches
      // command mode for Container
      Serial.println("you are in CMD mode: now printing BMP280 data");// temporary test 

      // if and else statements or case statements
      //  |                                    |
      //  |      implement here                |
      //  V                                    V
      
      // Test to toggle BMP280
      while( 1 == 1){
        // push sensor data (CMD,1210,)
        sensors_event_t temp_event, pressure_event;
        bmp_temp->getEvent(&temp_event);
        bmp_pressure->getEvent(&pressure_event);
        
        Serial.print(F("Temperature = "));
        Serial.print(temp_event.temperature);
        Serial.println(" *C");
      
        Serial.print(F("Pressure = "));
        Serial.print(pressure_event.pressure);
        Serial.println(" hPa");
      
        Serial.println();
        delay(2000);

        incomingString = Serial.readString(); // enalble serial reading for loop
        if(incomingString == "STOP") // if sting is STOP, break out of loop
          break;

        // add return fucntion
       
      }
      
      
      




      
    }  
  }


  
 
}
