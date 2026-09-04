# Lesson 03: 3W LED

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-02-rgb-led.md) | [Course index](../README.md) | [Next lesson →](lesson-04-traffic-light.md) |
| --- | --- | --- |

![Project 3: 3W LED illustration](../media/0b1110577bfde7df3b6aec41d5b21b28.png)

## Description

This LED module is of high brightness because the lamp beads it carries is 3w.
You can apply this module to Arduino projects, ideal for Robot or search and
rescue platform application.

For example, intelligent robots can use this module for illumination purpose.
Please note that the LED light can't be exposed directly to human eyes for
safety concerns.

## Specification

- Color temperature: 6000\~7000K

- Luminous flux: 180\~210lm

- Current: 700\~750mA

- Power: 3W

- Light angle: 140 degree

- Working temperature: -50\~80℃

- Storage temperature: -50\~100℃

- High power LED module, controlled by IO port microcontroller

- IO Type: Digital

- Supply Voltage: 3.3V to 5V

- Size: 40x28mm

- Weight: 6g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- 3W LED module \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Digital 13 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/7ca6e53405c422f3ae9b04ac572b40ef.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
///////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
///////////////////////////////////////////////////////////
```

## Example Result

Done wiring and powered up, upload well the code, both D13 led and the led on the module blink for one second then off, circularly.

![Example Result illustration](../media/edeb5b089be0300c719652badfd269e7.png)

---

| [← Previous lesson](lesson-02-rgb-led.md) | [Course index](../README.md) | [Next lesson →](lesson-04-traffic-light.md) |
| --- | --- | --- |
