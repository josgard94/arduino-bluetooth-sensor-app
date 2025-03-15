#ifndef SENSORDHT_H
#define SENSORDHT_H

#include "DHT.h"

class SensorDHT {
public:
    SensorDHT(int pin, int type);
    void begin();
    float getTemperature();
    float getHumidity();

private:
    DHT dht;
};

#endif
