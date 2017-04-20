#include <SoftwareSerial.h>

SoftwareSerial mySerial(8,9);

void setup () {
    Serial.begin (9600);
    mySerial.begin(9600);
    Serial.setTimeout(100);
}

String data;
uint8_t dataRead = 0;

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


String sensor_data_to_push() {
  String data;
  int value = analogRead(A0);
  //Serial.print (value);
  //Serial.print("   ");
  data = String(value);
  return data;
}



