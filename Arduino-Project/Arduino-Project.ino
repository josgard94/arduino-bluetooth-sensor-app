#include "SensorDHT.h"


#define DHT_PIN 2
#define DHT_TYPE DHT11

SensorDHT dht(DHT_PIN, DHT_TYPE);

void setup(){
    Serial.begin(9600);
    dht.begin();
}

void loop(){
    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();
    
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Error reading DHT sensor!");
        return;
    }
    else{
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" Humidity: ");
        Serial.println(humidity);
    }

    delay(2000);
}