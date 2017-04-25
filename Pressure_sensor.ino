#include <SoftwareSerial.h>

#include <Wire.h>

#include <Adafruit_BMP085.h>

SoftwareSerial mySerial(8,9);

Adafruit_BMP085 bmp;

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.setTimeout(100);
}

void loop()
{
  if (mySerial.available() > 0) {
    delay(50);
    String readData = "";
    Serial.print("cmd from bolt:");
    while (mySerial.available() > 0 ) {
      readData = readData + (char)mySerial.read();
    }
    Serial.println(readData);
    if (readData.indexOf("RD") != -1) {
      String data = sensor_data_to_push();
      mySerial.print(data);
      Serial.print("data sent to bolt:");
      Serial.print(data);
    }
  }
}

String sensor_data_to_push(){
   String data;
   String PRESSUREVALUE = String(bmp.readPressure());
   data = String(PRESSUREVALUE);
   return data;
  
}



