# Lesson 05: Buzzer Beeps

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-04-traffic-light.md) | [Course index](../README.md) | [Next lesson →](lesson-06-passive-buzzer.md) |
| --- | --- | --- |

![Project 5: Buzzer Beeps illustration](../media/88c349b0602dfa2e166faabc13cb2f20.png)

## Description

Here is the simplest sound making module. You can use high/low level to drive it. Changing the frequency it buzzes can produce different sounds.

This module is widely used on our daily appliances like PC, refrigerator, phones, etc.

In addition, you can create many interesting interactive projects with this small but useful module. Just try it!! You will find the electronic sound it creates so fascinating.

## Specification

- Working voltage: 3.3-5v

- Interface type: digital

- Size: 30*20mm

- Weight: 4g

## Connection Diagram

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/173f2e9a828b0b20d76dc07de57892c1.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
int buzzPin =3;    //Connect Buzzer on Digital Pin3
 void setup()
 {
  pinMode(buzzPin, OUTPUT);
}
 void loop()
{
  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);
  delay(1);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done uploading the code to board, the buzzer will make a sound.

![Example Result illustration](../media/109e3287bff29d1d1fb88369d6705ad3.png)

---

| [← Previous lesson](lesson-04-traffic-light.md) | [Course index](../README.md) | [Next lesson →](lesson-06-passive-buzzer.md) |
| --- | --- | --- |
