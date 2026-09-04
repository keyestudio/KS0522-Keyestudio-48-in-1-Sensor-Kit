# Lesson 02: RGB LED

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-01-white-led.md) | [Course index](../README.md) | [Next lesson →](lesson-03-3w-led.md) |
| --- | --- | --- |

![Project 2: RGB LED illustration](../media/de14ae0679267cf87837b7c09934c52e.png)

## Description

This is a full-color LED module, which contains 3 basic colors－red, green and blue. They can be seen as separate LED lights.

After programming, you can turn them on and off by sequence or can also use PWM analog output to mix three colors to generate different colors.

## Specification

- Color: red, green and blue

- Brightness: High

- Voltage: 5V

- Input: digital level

- Size: 30 \*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- RGB LED module \*1

- USB Cable\*1

- Jumper Wire\*4

Connect the V pin of module to 5V port of V4.0 board, connect the B pin to Digital 11, R pin to Digital 10, G pin to Digital 9.

![Connection Diagram illustration](../media/2c0a9305cd7c7b0c28c51bc2bc24eb39.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
const uint8_t redPin = 11;
const uint8_t bluePin = 10;
const uint8_t greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for (int value = 255; value >= 0; --value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
  for (int value = 0; value < 255; ++value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
}
```

## Example Result

Done wiring and powered up, upload well the code, you will see the RGB LED module emit shiny colors.

![Example Result illustration](../media/0872e5256edf443efcb68218505096ba.png)

---

| [← Previous lesson](lesson-01-white-led.md) | [Course index](../README.md) | [Next lesson →](lesson-03-3w-led.md) |
| --- | --- | --- |
