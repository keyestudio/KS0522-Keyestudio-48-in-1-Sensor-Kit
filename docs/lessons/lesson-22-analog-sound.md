# Lesson 22: Analog Sound

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 22: Analog Sound illustration](../media/a494bbec73f7c8ff91b3133c9d2798a7.jpeg)

## Description

Analog sound sensor is typically used in detecting the volume of ambient sounds. The sensor comes with a potentiometer, so that you can turn it to adjust the signal gain.

You can use it to make some interesting and interactive works, such as a voice operated switch.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Analog

- Size: 30*20mm

- Weight: 4g

## Connection Diagram

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/22e1124550d57015a6d2d5782b8febda.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
int sensorPin =A0 ;
int value = 0;
void setup()
{
 Serial.begin(9600); }
void loop()
{
 value = analogRead(sensorPin);

Serial.println(value, DEC);

delay(50);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done wiring and powered up, upload well the code, then open the serial monitor and set the baud rate as 9600, you will see the analog value. When talking toward the micro head, the value will increase. Shown below.

![Example Result illustration](../media/4d753036151413a1bdda3c0b283b8551.png)

---
