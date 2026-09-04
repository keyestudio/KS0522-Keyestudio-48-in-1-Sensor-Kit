# Lesson 32: Ultraviolet Light

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 32: Ultraviolet Light illustration](../media/15613ff0e8f059a9034e923ab5c2be24.jpeg)

## Description

Keyestudio GUVA-S12SD ultraviolet sensor is used to detect ultraviolet light. It includes GUVA-S12SD applied to measure ultraviolet index of intelligent wearable device, such as watches, smart phone and outdoor device with UV index detecting.

It can be also used to monitor the intensity of ultraviolet light or used as a
UV flame detector when disinfecting things by ultraviolet light.

## Parameters

- Size: 15mm×30mm×0.7mm

- Supply Voltage: 2.5V～5V

- Output Signal: Analog Signal

- Detecting Range of Spectrum: 240-370nm

- Active Region: 0.076mm2

- Responsivity: 0.14A/W

- Dark Current: 1nA

- Light Current: 101\~125nA UVA Light, 1mW/cm2

## Connection Diagram

Firstly you need to prepare the following parts before connection.

- V4.0 Board\*1

- GUVA-S12SD 3528 Ultraviolet Sensor \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 3V3 port.

![Connection Diagram illustration](../media/092ebb11142cfe83507989a5b2de0526.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
///////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/e81338e1f55ff6b55fbfe369f92b54da.png)

Wire it up well and upload the program code, then open serial monitor, it will display the data.

If shine UV light to the sensor, the data on serial monitor is changing shown as the following picture.

![Example Result illustration](../media/3a7f2a608faa9c72aee76d2820f78845.png)

![Example Result illustration](../media/610d2325395cd3b44ce3c18e05595518.jpeg)

---
