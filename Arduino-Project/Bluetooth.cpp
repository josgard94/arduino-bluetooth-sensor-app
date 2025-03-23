#include "Bluetooth.h"

BluetoothManager::BluetoothManager(uint8_t rxPin, uint8_t txPin, long baudRate)
    : btSerial(rxPin, txPin), baud(baudRate) {}

void BluetoothManager::begin() {
    btSerial.begin(baud);
}

bool BluetoothManager::available() {
    return btSerial.available();
}

String BluetoothManager::readData() {
    String received = "";
    while (btSerial.available()) {
        char c = btSerial.read();
        received += c;
        delay(2);
    }
    return received;
}

void BluetoothManager::sendData(const String& data) {
    btSerial.print(data);
}

void BluetoothManager::handleCommunication(const String& data) {
    sendData(data);
} 
