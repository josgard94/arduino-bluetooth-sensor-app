#include "SensorDHT.h"

SensorDHT::SensorDHT(int pin, int type) : dht(pin, type) {}

void SensorDHT::begin() {
    dht.begin();
}

float SensorDHT::getTemperature() {
    return dht.readTemperature();
}

float SensorDHT::getHumidity() {
    return dht.readHumidity();
}
