/*
* GY-521 MPU 6050 
* Measures Temperature and Rotation Speed
* Vin - 5V or 3.3V
* GND - Ground
* SCK - SCL or A5
* SDI - SDA or A4
* I2C address of normally 0x68(interfere with RTC DS3221)
* set AD0 on MPU to set new I2C address to 0x69
*/

float RPM; 

void setupMPU(){
// initialize MPU6050
  delay(100);
  while (sensor.wakeup() == false)
  {
    Serial.print(millis());
    Serial.println("\tCould not connect to GY521");
    delay(1000);
  }
  
  sensor.setAccelSensitivity(0);  // 2g
  sensor.setGyroSensitivity(2);   // 2 = 1000 degrees/s
  sensor.setThrottle();

   // set callibration values from calibration sketch.
  sensor.axe = 0;
  sensor.aye = 0;
  sensor.aze = 0;
  sensor.gxe = 0;
  sensor.gye = 0;
  sensor.gze = 0;
}

float getRotation(){ // orignally in degrees per second
  sensor.read();
  return (float)(sensor.getGyroZ()/6);// divide by 6 to convert to RPM
}
