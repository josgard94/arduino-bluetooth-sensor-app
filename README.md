# 📡 Arduino Bluetooth Sensor App

## 📌 Description
This project is a **React Native** application that connects to an **Arduino** microcontroller via **Bluetooth** to receive real-time **temperature and humidity** data from a **DHT11/DHT22** sensor. The app displays the collected data in a user-friendly interface, allowing users to monitor environmental conditions remotely.

## 🚀 Features
- ✅ **Bluetooth communication** using HC-05/HC-06 module
- ✅ **Real-time temperature and humidity monitoring**
- ✅ **User-friendly UI** for device selection and data display
- ✅ **JSON-based data exchange** between Arduino and the mobile app
- ✅ **Support for future sensor integration**

## 🛠️ Technologies Used
- 🔹 **React Native** - Mobile app development
- 🔹 **react-native-bluetooth-serial-next** - Bluetooth communication
- 🔹 **Arduino** - Microcontroller for sensor readings
- 🔹 **DHT11/DHT22** - Temperature & humidity sensor

## ⚙️ How It Works
1️⃣ The **Arduino** reads temperature and humidity data from the **DHT sensor**.  
2️⃣ The data is sent via **Bluetooth** in **JSON format**.  
3️⃣ The **React Native app** receives and parses the data.  
4️⃣ The values are **displayed on the mobile screen** in real time.

## 📲 Installation & Setup

### 🔹 Prerequisites
- Install **Node.js** and **React Native CLI**
- Setup **Android Studio** (for Android development)
- Install **Arduino IDE** (for microcontroller programming)
