/*
* Date and time functions using a DS1307 RTC connected via I2C and Wire lib
* I2C address of 0x68
* DS3231 Model
* 5V
* SDA - A4
* SCL - A5
*/ 

void setupRTC(){
  rtc.begin();
  if (hasReset == false){
      rtc.adjust(DateTime(2019, 1, 5, 1, 59, 50));
  }
}

//int getSeconds(){
//  DateTime now = rtc.now();
//  return ((int)now.second() + 60*(int)now.minute() + 3600*(int)now.hour());
//}

int getSecond(){
  DateTime now = rtc.now();
  return now.second(); 
}

int getMinute(){
  DateTime now = rtc.now();
  return now.minute(); 
}

int getHour(){
  DateTime now = rtc.now();
  return now.hour(); 
}

//void setupRTC(){
//  Clock.setClockMode(false);  // set to 24h
//  
//  Clock.setHour(0);  // set Hour
//  Clock.setMinute(0);// set Minute
//  Clock.setSecond(25);// set Second
//  
//}
//
//int getHours(){
//  Clock.getHour(h12, PM);
//}
//
//int getMinutes(){
//  Clock.getMinute();
//}
//
//int getSeconds(){
//  Clock.getSecond();
//}
