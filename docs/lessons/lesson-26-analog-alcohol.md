# Lesson 26: Analog Alcohol

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-25-analog-gas.md) | [Course index](../README.md) | [Next lesson →](lesson-27-steam-sensor.md) |
| --- | --- | --- |

![Project 26: Analog Alcohol illustration](../media/288162cf02f2968eda57b437292a42dd.png)

## Description

This analog MQ-3 sensor is suitable for detecting alcohol. It can be used in a breath-analyzer project.

It has good selectivity because it has higher sensitivity to alcohol and lower sensitivity to Benzine.

The sensitivity can be adjusted by rotating the potentiometer on the sensor.

## Specification

- Power supply: 5V

- Interface type: Analog

- Simple drive circuit

- Stable and long service life

- Quick response and High sensitivity

## Connection Diagram

Connect the A0 pin of module to Analog A0 of V4.0 board, connect the GND pin to GND port, VCC pin to 5V port.

![Connection Diagram illustration](../media/61632f44731176aaf95d313f2843c9de.jpeg)

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

![Example Result illustration](../media/a21d5b8c686e46a59128ab48b96d177c.png)

Done wiring and powered up, upload well the code, then open the serial monitor and set the baud rate as 9600, you will see the analog value. When detecting the alcohol gas, the value will make a change.

![Example Result illustration](../media/97565d8ba7691b30a7aa96efc6c7728b.jpeg)

---

| [← Previous lesson](lesson-25-analog-gas.md) | [Course index](../README.md) | [Next lesson →](lesson-27-steam-sensor.md) |
| --- | --- | --- |
