void setupFunctions(){
  Wire.begin();
  setupBMP();
  setupRTC();
  setupMPU();
}

/*
 * Obtains data from sensors
 * Used in FlightSoftware.ino
 * Different from getData2() since this data only needs to be updated
 * once per second or whenever it is needed
 */
void getData(){
  TeleArray1[TeleMissionTimeHour] = getHour();
  TeleArray1[TeleMissionTimeMin] = getMinute();
  TeleArray1[TeleMissionTimeSec] = getSecond();
  TeleArray2[TeleTemp] = getTemp();
  TeleArray2[TelePressure] = getPressure();
  TeleArray2[TeleAlt] = getAlt();
  TeleArray2[TeleRotationRate] = getRotation();
  TeleArray1[TelePacket] = packetCount;
}


void transmitData()
{
  Serial.print(TeleArray1[TeleID]);
  Serial.print(", ");
  if(TeleArray1[TeleMissionTimeHour] < 10)      // ----------
    Serial.print("0");                          // |  
  Serial.print(TeleArray1[TeleMissionTimeHour]);// |
  Serial.print(":");                            // |  Simple if statements to pad 
  if(TeleArray1[TeleMissionTimeMin] < 10)       // |  zeros for the time values to 
    Serial.print("0");                          // |  fit the format hh:mm:ss
  Serial.print(TeleArray1[TeleMissionTimeMin]); // |
  Serial.print(":");                            // |
  if(TeleArray1[TeleMissionTimeSec] < 10)       // |
    Serial.print("0");                          // |
  Serial.print(TeleArray1[TeleMissionTimeSec]); // ----------
  Serial.print(", ");
  Serial.print(TeleArray1[TelePacket]);
  Serial.print(", ");
  Serial.print("S1"); // Hard code the Packet count (S1 or S2 or C)
  Serial.print(", ");
  Serial.print(TeleArray2[TeleAlt]);
  Serial.print(", ");
  Serial.print(TeleArray2[TelePressure]);
  Serial.print(", ");
  Serial.print(TeleArray2[TeleTemp]);
  Serial.print(", ");
  Serial.print(TeleArray2[TeleRotationRate]);
  Serial.print("\n");
}

/*
 * Checks if any commands have been received through the Serial Monitor
 * This would be done through the XBee and the groundstation
 */
//void receiveRadioData() {
//  if (Serial.available()) {
//    String RadioReceive = Serial.readString();
//    if (RadioReceive == "A")
//    {
//      digitalWrite(deployPinA, HIGH);
//    }
//    if (RadioReceive == "B"){
//      digitalWrite(deployPinB, HIGH);
//    }
//  }
//}
