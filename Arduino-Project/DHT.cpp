#include "DHT.h"

DHT::DHT(uint8_t pin, uint8_t type, uint8_t count) 
    : _pin(pin), _type(type), _count(count), firstReading(true), _lastReadTime(0) {}

void DHT::begin() {
    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH);
}

float DHT::readTemperature(bool isFahrenheit) {
    if (!read()) {
        Serial.print("Read fail");
        return NAN;
    }

    float temperature = (_type == DHT11) ? data[2] : ((data[2] & 0x7F) * 256 + data[3]) / 10.0;
    if (_type != DHT11 && (data[2] & 0x80)) temperature *= -1;
    
    return isFahrenheit ? convertCtoF(temperature) : temperature;
}

float DHT::readHumidity() {
    if (!read()) {
        Serial.print("Read fail");
        return NAN;
    }

    return (_type == DHT11) ? data[0] : (data[0] * 256 + data[1]) / 10.0;
}

float DHT::convertCtoF(float celsius) {
    return celsius * 9 / 5 + 32;
}

bool DHT::read() {
    uint8_t lastState = HIGH, counter = 0, j = 0;
    unsigned long currentTime = millis();

    if (currentTime < _lastReadTime) _lastReadTime = 0;
    if (!firstReading && (currentTime - _lastReadTime < 2000)) return true;

    firstReading = false;
    _lastReadTime = millis();

    memset(data, 0, sizeof(data));

    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delay(20);
    cli();
    digitalWrite(_pin, HIGH);
    delayMicroseconds(40);
    pinMode(_pin, INPUT);

    for (uint8_t i = 0; i < MAXTIMINGS; i++) {
        counter = 0;
        while (digitalRead(_pin) == lastState) {
            if (++counter == 255) break;
            delayMicroseconds(1);
        }
        lastState = digitalRead(_pin);
        if (counter == 255) break;
        
        if (i >= 4 && (i % 2 == 0)) {
            data[j / 8] <<= 1;
            if (counter > _count) data[j / 8] |= 1;
            j++;
        }
    }
    sei();

    return (j >= 40 && data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF));
}
