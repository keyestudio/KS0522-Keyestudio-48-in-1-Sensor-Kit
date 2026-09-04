# Lesson 14: Digital Tilt Switch

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-13-knock-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-15-capacitive-touch.md) |
| --- | --- | --- |

![Project 14: Digital Tilt Switch illustration](../media/45a40bdcc098c1c4e0efb8246447173c.png)

## Description

Tilt Sensor is a digital tilt switch. It can be used as a simple tilt switch.

Simply plug it to our IO/Sensor shield, easy for wire connection. With dedicated sensor shield and Arduino, you can make lots of interesting and interactive works.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Digital

- Size: 30*20mm

- Weight: 3g

## Connection Diagram

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/b909cdd6f697779371498723dc1407ab.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
```

## Example Result

Done wiring and powered up, then upload well the code to V4.0 board.

![Example Result illustration](../media/d6a0aa9af1e43265114eec8570ac0f3c.png)

Then tilt the sensor, you will see the led on the sensor is turned on. Shown as below.

![Example Result illustration](../media/6c4a144c26675a100bffa806c532736c.png)

---

| [← Previous lesson](lesson-13-knock-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-15-capacitive-touch.md) |
| --- | --- | --- |
