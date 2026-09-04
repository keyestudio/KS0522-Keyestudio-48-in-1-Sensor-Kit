# Lesson 25: Analog Gas

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-24-soil-moisture.md) | [Course index](../README.md) | [Next lesson →](lesson-26-analog-alcohol.md) |
| --- | --- | --- |

![Project 25: Analog Gas illustration](../media/36f00d2a934c497f390b49c4113c7c04.png)

## Description

This analog gas sensor MQ2 is used in gas leakage detecting equipment in both consumer electronics and industrial markets. This sensor is suitable for detecting LPG, I-butane, propane, methane, alcohol, Hydrogen and smoke.

The detecting scope of this sensor is very wide and it has high sensitivity and quick response.

In addition, the sensitivity can be adjusted by rotating the potentiometer on the sensor.

## Specification

- Power supply: 5V

- Interface type: Analog

- Simple drive circuit

- Stable and long lifespan

## Connection Diagram

Connect the A0 pin of module to Analog A0 of V4.0 board, connect the GND pin to GND port, VCC pin to 5V port.

![Connection Diagram illustration](../media/7b2cdff9418f79b2e9e566ce61a7966a.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}

////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/d440553d52e043d7a91928882d877dd1.png)

Done wiring and powered up, upload well the code, then open the serial monitor and set the baud rate as 9600, you will see the analog value. When detecting the gas, the value will make a change.

![Example Result illustration](../media/cbf777feb6231d76347bc632f87d0e8e.jpeg)

---

| [← Previous lesson](lesson-24-soil-moisture.md) | [Course index](../README.md) | [Next lesson →](lesson-26-analog-alcohol.md) |
| --- | --- | --- |
