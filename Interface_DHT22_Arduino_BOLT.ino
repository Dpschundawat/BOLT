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
//  mySerial.setTimeout(50);
}

String dataToUpload;
uint8_t dataRead = 0;

void loop()
{
  //Read data and store it to variables hum and temp

  //Print temp and humidity values to serial monitor
  //Serial.print(dataToUpload);
  /*Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");*/
  //delay(2000); //Delay 1 sec.
  if ( dataRead == 0) {
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();
    dataToUpload = String(hum) + "," + String(temp) ;
    dataRead = 1;
    Serial.print(dataToUpload);
  }
  if ( mySerial.available() > 0 && dataRead == 1) {
    //Serial.print(dataToUpload); //send last read hum and temp values to bolt
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

