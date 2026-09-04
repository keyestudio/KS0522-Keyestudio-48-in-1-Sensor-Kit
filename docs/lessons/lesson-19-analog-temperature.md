# Lesson 19: Analog Temperature

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-18-pir-motion-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-20-analog-rotation.md) |
| --- | --- | --- |

![Project 19: Analog Temperature illustration](../media/8269d6536e383bcc592da1ae98bc3661.png)

## Description

This module is based on the working principle of a thermistor (resistance varies with temperature change in the environment).

It can sense temperature changes in the surrounding and send the data to the analog IO of Arduino board.

All we need to do is to convert the sensor’s output data into degrees Celsius temperature via simple programming, finally displaying it on the monitor.

It's both convenient and effective, thus it is widely applied to gardening, home alarm system and other devices.

## Specification

- Interface type: analog

- Working voltage: 5V

- Temperature range: -55℃～315℃

- Size: 30\*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Analog temperature sensor\*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/330d37f05ac235a850d06726284243a5.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop()
{int sensorValue = analogRead(A0);
Serial.println(sensorValue);
  delay(1); }
////////////////////////////////////////////////////////////////////
```

The above code is only for analog value.

You can see that the analog value is changing according to the temperature change in the environment. But it’s not very obvious.

Let’s solve this by using the following equation. Then upload the code below to the Arduino board. The value read from the serial port is similar to normal temperature. eg. The temperature right now is 30°C.

```c
////////////////////////////////////////////////////////////////////
#include <math.h>
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  double val=analogRead(0);
  double fenya=(val/1023)*5;
  double r=(5-fenya)/fenya*4700;
  Serial.println( 1/(  log(r/10000) /3950 + 1/(25+273.15))-273.15);
  delay(1000);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/9ae4e8962bf9d46ceeb3ca0c2e560f43.png)

Done wiring and powered up as the above figure, upload well the code to the board, then open the serial monitor of Arduino IDE, you will see the current temperature value.

![Example Result illustration](../media/005b4c639460eba8158f99637f03686b.jpeg)

---

| [← Previous lesson](lesson-18-pir-motion-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-20-analog-rotation.md) |
| --- | --- | --- |
