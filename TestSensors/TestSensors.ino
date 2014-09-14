// OSA BASE

#include <dht11.h>
dht11 DHT;

#define DHT11_PIN 4       // define a pin for DHT sensor
int lightPin= 0;          // define a pin for Photo resistor

void setup(){
  
Serial.begin(9600);
Serial.println("OSNF - Open Sensors Network Framework 0.1 ");
Serial.print("DHT LIBRARY VERSION:");
Serial.println(DHT11LIB_VERSION);
Serial.print("SENSOR NAME:");
Serial.println("OSA1");
Serial.println();
}

void loop(){

int chktemp;
int light;   
int temp;
int hum;

chktemp = DHT.read(DHT11_PIN);   // READ DATA TEMP & HUM SENSOR FOR CHECK

// CHECK DHT LIBRARY STATUS

/*
Serial.print("DHT11 SENSOR,\t");

switch (chktemp){
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
*/

light = analogRead(lightPin);    // READ DATA PHOTORESITOR
temp = DHT.temperature;          // READ DATA TEMPERATURE
hum = DHT.humidity;              // READ DATA HUMIDITY

// DISPLAT DATA

Serial.print("TEMP:");
Serial.print(temp);
Serial.print(",");
Serial.print("HUM:");
Serial.print(hum);
Serial.print(",");
Serial.print("LIGHT:");
Serial.print(light);
Serial.print("\n");

delay(2000);
}
