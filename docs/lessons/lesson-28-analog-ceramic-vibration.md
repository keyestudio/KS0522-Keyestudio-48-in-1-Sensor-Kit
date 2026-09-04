# Lesson 28: Analog Ceramic Vibration

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-27-steam-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-29-voltage-detection.md) |
| --- | --- | --- |

![Project 28: Analog Ceramic Vibration illustration](../media/2cf5c2793157816a2346a730ad064955.jpeg)

## Description

This vibration sensor is based on piezoelectric ceramic chip analog vibration. It makes use of the anti-conversion process that piezoelectric ceramic vibration will generate the electric signals. When vibrating the piezoelectric ceramic chip, the sensor’s signal terminal will generate electrical signals.

The sensor can be used with Arduino dedicated sensor shield, and Arduino analog port can perceive weak vibration signals, so that it can make interactive works related to vibration, such as electronic drum.

Connect the vibration sensor to the analog port A0 of Arduino UNO. When vibrating the sensor in different degrees, you will see the different output value displayed on serial monitor of Arduino software.

## Specification

- Supply Voltage: 3.3V to 5V

- Working Current：\<1mA

- Working Temperature Range：－10℃～＋70℃

- Output Signal：analog signal

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 board\*1

- vibration sensor\*1

- USB Cable\*1

- Jumper wire\*3

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, NC pin to 5V port.

![Connection Diagram illustration](../media/92fce2d45b05876a7928070bd2b137da.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
///////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //Open the serial to set the baud rate as 9600bps
}
void loop()
{
int val;
val=analogRead(0); //Connect the sensor to analog interface A0
Serial.print("Vibration is ");
Serial.println(val,DEC);//Print the analog value read on serial port
delay(100);
}
///////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/e21152ca9f30274fcc658091f76f7044.png)

Wiring as the above diagram and upload well the code, then open the serial monitor and set the baud rate as 9600.

When vibrating the ceramic chip, you will see the data change as the figure shown below.

![Example Result illustration](../media/4be72e831696d59b36082aa45d77a04d.jpeg)

---

| [← Previous lesson](lesson-27-steam-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-29-voltage-detection.md) |
| --- | --- | --- |
