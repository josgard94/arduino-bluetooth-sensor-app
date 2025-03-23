#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothManager {
public:
    BluetoothManager(uint8_t rxPin, uint8_t txPin, long baudRate = 9600);

    void begin();
    bool available();
    String readData();
    void sendData(const String& data);
    void handleCommunication(const String& data);

private:
    SoftwareSerial btSerial;
    long baud;
};

#endif
