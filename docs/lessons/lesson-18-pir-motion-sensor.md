# Lesson 18: PIR Motion Sensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 18: PIR Motion Sensor illustration](../media/ce608db25742f19fdf6eceda756a59d9.png)

## Description

Pyroelectric infrared motion sensor can detect infrared signals from a moving person or moving animal, and output switching signals.

It can be applied to a variety of occasions to detect the movement of human body.

Conventional pyroelectric infrared sensors require body pyroelectric infrared detector, professional chip and complex peripheral circuit, so the size is much more bigger, with complex circuit and lower reliability.

Now we launch this new pyroelectric infrared motion sensor, specially designed for Arduino.

It uses an integrated digital body pyroelectric infrared sensor, with smaller size, higher reliability, lower power consumption and simpler peripheral circuit.

## Specification

- Input Voltage: 3.3 \~ 5V, Maximum for 6V

- Working Current: 15uA

- Working Temperature: -20 \~ 85 ℃

- Output Voltage: High 3V, Low 0V

- Output Delay Time (High Level): About 2.3 to 3 Seconds

- Detection Angle: 100 °

- Detection Distance: 7 meters

- Output Indicator LED (if output HIGH, it will be ON)

- Limit Current for Pin: 100mA

- Size: 30*20mm

- Weight: 4g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board*1

- PIR motion sensor*1

- USB Cable*1

- Jumper Wire*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/01970d510c03a8c7aa3ef0c13ea70cff.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
byte sensorPin = 3;
byte indicator = 13;
void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  if(state == 1)Serial.println("Somebody is in this area!");
  else if(state == 0)Serial.println("No one!");
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done wiring and powered up, upload well the code, if the sensor detects someone moving nearby, D13 indicator on V4.0 board will light up, and "Somebody is in this area!" is displayed on the serial monitor of Arduino software.

If no detecting the movement, D13 indicator on V4.0 board will be off, and "No one!" is displayed on the serial monitor.

![Example Result illustration](../media/e25d28654311fa7820a1886a285353e5.png)

![Example Result illustration](../media/9b6209c8ce5b4be73f8378d21b639d28.jpeg)

---
