#include "SensorDHT.h"
#include "Bluetooth.h"

BluetoothManager btManager(2, 3); // RX, TX

#define DHT_PIN 5
#define DHT_TYPE DHT11

SensorDHT dht(DHT_PIN, DHT_TYPE);

void setup(){
    Serial.begin(9600);
    dht.begin();
    btManager.begin();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){

    String data = "";

    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();
    
    if (isnan(temperature) || isnan(humidity)) {
        data = "Error reading DHT sensor!";
        delay_(2);
        return;
    }
    else{
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" Humidity: ");
        Serial.println(humidity);
        data = "Temperature:" + String(temperature) + " Humidity:" + String(humidity) + "\n";
        btManager.handleCommunication(data);
        delay_(2);
    }
}

void delay_(int seg){
    delay(seg * 1000);
}