# Arduino and Bluetooth

## Hardware

- Arduino UNO R4 Board
- DFRobot Gravity: 130 DC Motor Module
- Button component for Arduino
- Potentiometer component for Arduino
  
## Software

- Arduino IDE
- LightBlue app on mobile phone

## Explanation

The value of the motor speed can be written from an app on a phone, or another Arduino, over Bluetooth.   
**ArduinoBLE_LED_example** contains the code for turning an LED on or off from a mobile device connected over Bluetooth. It takes in any value and if that isn't zero turns the light on.    

**BLUETOOTH_MOTOR** contains the code for making a motor spin at different speeds, controlled from a mobile device over Bluetooth.    

**Bluetooth_motor_Button_press** contains the code for making a motor spin when a button is pressed. The button is connected to another Arduino and the two are linked by Bluetooth to interact.   

**Bluetooth_motor_Potentiometer** contains the code for making a motor spin at different speeds based on a potentiometer connected to another Arduino and the two are linked by Bluetooth.
