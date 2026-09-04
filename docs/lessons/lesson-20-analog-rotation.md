# Lesson 20: Analog Rotation

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-19-analog-temperature.md) | [Course index](../README.md) | [Next lesson →](lesson-21-photocell.md) |
| --- | --- | --- |

![Project 20: Analog Rotation illustration](../media/7a7fffa705c4a50e87455e6d378eb837.png)

## Description

This analog rotation sensor is Arduino compatible. It is based on a potentiometer. Its voltage can be subdivided into 1024, easy to be connected to Arduino with our sensor shield.

Combined with other sensors, you can use it to make interesting projects by reading the analog value from the IO port.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Analog

- Size: 30*20mm

- Weight: 8g

## Connection Diagram

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/f8a0c2cca0f3d0935ce0c9a0c4dbe59e.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/bae047449c10c99449c35a14b22d759c.png)

Done wiring and powered up, upload well the code, then open the serial monitor and set the baud rate as 9600, finally you will see the analog value. If rotate the knob on the rotation sensor, the value will be changed within 0-1023. Shown below.

![Example Result illustration](../media/bc7b15c3245b7cfd91b0ef4b0aeb8e7e.jpeg)

---

| [← Previous lesson](lesson-19-analog-temperature.md) | [Course index](../README.md) | [Next lesson →](lesson-21-photocell.md) |
| --- | --- | --- |
