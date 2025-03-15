#ifndef DHT_H
#define DHT_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define MAXTIMINGS 85

#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

class DHT {
private:
    uint8_t data[5];
    uint8_t _pin, _type, _count;
    bool firstReading;
    unsigned long _lastReadTime;
    bool read();

public:
    DHT(uint8_t pin, uint8_t type, uint8_t count = 6);
    void begin();
    float readTemperature(bool isFahrenheit = false);
    float readHumidity();
    float convertCtoF(float celsius);
};

#endif
