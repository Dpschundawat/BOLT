#include <DHT.h>
#include<SoftwareSerial.h>

SoftwareSerial mySerial(8,9);

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  dht.begin();
  Serial.setTimeout(50);
}

String dataToUpload;
uint8_t dataRead = 0;

void loop()
{
  //Read data and store it to variables hum and temp
  if ( dataRead == 0) {
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();
    dataToUpload = String(hum) + "," + String(temp) ;
    dataRead = 1;
    Serial.print(dataToUpload);
  }
  if ( mySerial.available() > 0 && dataRead == 1) {
    delay(50);
    while(mySerial.available() > 0){
      char garbage = mySerial.read();
      Serial.print(garbage);
    }
    mySerial.print(dataToUpload);
    dataRead = 0;
    dataToUpload = "";
    Serial.println("data sent ");
  }
}

