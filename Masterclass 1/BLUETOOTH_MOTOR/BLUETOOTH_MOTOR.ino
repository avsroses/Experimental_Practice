/*
  MOTOR

  This example creates a Bluetooth® Low Energy peripheral with service that contains a
  characteristic to control a motor.

  The circuit:
  - Arduino MKR WiFi 1010, Arduino Uno WiFi Rev2 board, Arduino Nano 33 IoT,
    Arduino Nano 33 BLE, or Arduino Nano 33 BLE Sense board.

  You can use a generic Bluetooth® Low Energy central app, like LightBlue (iOS and Android) or
  nRF Connect (Android), to interact with the services and characteristics
  created in this sketch.

  This example code is in the public domain.
*/


#include <ArduinoBLE.h>

BLEService motorService("bcd83f84-3f46-41df-b9f9-0d4e6365de5d"); // Bluetooth® Low Energy LED Service

BLEByteCharacteristic switchCharacteristic("bcd83f84-3f46-41df-b9f9-0d4e6365de5d", BLERead | BLEWrite);

const int motorPin = 13; // pin to use for the MOTOR

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // set motor pin to output mode
  pinMode(motorPin, OUTPUT);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("MOTOR");
  BLE.setAdvertisedService(motorService);

  // add the characteristic to the service
  motorService.addCharacteristic(switchCharacteristic);

  // add service
  BLE.addService(motorService);

  // set the initial value for the characteristic:
  switchCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("BLE MOTOR Peripheral");
}

void loop() {
  // listen for Bluetooth® Low Energy peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());


    // while the central is still connected to peripheral:
    while (central.connected()) {

      // For a button press - on or off
      /*
      if(switchCharacteristic.written()){
        if(switchCharacteristic.value()){
          analogWrite(motorPin, 255);
        } else {
          analogWrite(motorPin, 0);
        }
      }
      */

      if (switchCharacteristic.written()) {  
        Serial.println("MOTOR on");
        analogWrite(motorPin, switchCharacteristic.value());   
      } 
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
