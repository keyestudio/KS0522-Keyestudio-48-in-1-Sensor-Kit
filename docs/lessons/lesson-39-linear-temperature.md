# Lesson 39: Linear Temperature

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-38-single-relay.md) | [Course index](../README.md) | [Next lesson →](lesson-40-temperature-and-humidity-display.md) |
| --- | --- | --- |

![Project 39: Linear Temperature illustration](../media/9a9b328cb85401dce3932f047f0979e0.png)

## Introduction

LM35 Linear Temperature Sensor is based on semiconductor LM35 temperature sensor. It can be used to detect ambient air temperature.

This sensor offers a functional range among 0 degree Celsius to 100 degree Celsius. Sensitivity is 10mV per degree Celsius. The output voltage is proportional to the temperature.

This sensor is commonly used as a temperature measurement sensor. It includes thermocouples, platinum resistance, thermal resistance and temperature semiconductor chips.

The chip is commonly used in high temperature measurement thermocouples.

Platinum resistance temperature sensor is used in the measurement of 800 degrees Celsius, while the thermal resistance and semiconductor temperature sensor is suitable for measuring the temperature of 100-200 degrees or below, in which the application of a simple semiconductor temperature sensor is good in linearity and high in sensitivity.

The LM35 linear temperature sensor can be easily connected to Arduino shield.

## Specification

- Sensitivity: 10mV per degree Celsius

- Functional range: 0 degree Celsius to 100 degree Celsius

- Size: 30*20mm

- Weight: 3g

## Connection Diagram

Firstly you need to prepare the following parts before testing.

- V4.0 Board\*1

- LM35 temperature sensor\*1

- USB Cable\*1

- Jumper Wire\*3

Then follow the wiring diagram, connect the signal pin of sensor to A0 port of V4.0 board, negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/e2f1fc77bb6b54c35bc3d1a8834cbf6b.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 void loop()
{  int val;
    int dat;
    val=analogRead(0);//Connect LM35 on Analog 0
    dat=(500 * val) /1024;;
    Serial.print("Temp:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
///////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/95d0d43a93fd2bf1e9c7248e80edcedc.png)

Wire it up as the above diagram and upload well the code to the board, then open the serial monitor and set the baud rate as 9600.

You will see the current temperature value shown below. The value may be slight difference due to different place and weather.

![Example Result illustration](../media/8331a0416c8006161b3227e170a3b033.jpeg)

---

| [← Previous lesson](lesson-38-single-relay.md) | [Course index](../README.md) | [Next lesson →](lesson-40-temperature-and-humidity-display.md) |
| --- | --- | --- |
