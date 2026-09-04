# Lesson 41: Magical Light Cup

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 41: Magical Light Cup illustration](../media/dc3acff676b2611f440643f1657b42e7.png)

## Introduction

Magic light cup module is able to interact with ARDUINO. The principle is based on PWM dimming.

The mercury switch on the module can provide a digital signal and trigger PWM regulation. The brightness of two modules will be changed together through the program design, finally you can see the changing effect that two set of cups are pouring the light.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Digital

## Connection Diagram

![Connection Diagram illustration](../media/9d8d534c60a81608741f85c08d4d0bbe.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
int LedPinA = 5;
int LedPinB = 6;
int ButtonPinA = 7;
int ButtonPinB = 4;
int buttonStateA = 0;
int buttonStateB = 0;
int brightnessA = 0;
int brightnessB= 255;
void setup()
{
Serial.begin(9600);
pinMode(LedPinA, OUTPUT);
pinMode(LedPinB, OUTPUT);

pinMode(ButtonPinA, INPUT);
pinMode(ButtonPinB, INPUT);
}
void loop()
{
buttonStateA = digitalRead(ButtonPinA);
if (buttonStateA == HIGH && brightnessA != 255)
{
brightnessA ++;
}
if (buttonStateA == LOW && brightnessA != 0)
{
brightnessA --;
}
analogWrite(LedPinB, brightnessA);
Serial.print(brightnessA);

Serial.print("   ");
buttonStateB = digitalRead(ButtonPinB);
if (buttonStateB == HIGH && brightnessB != 0)
{
brightnessB --;
}
if (buttonStateB == LOW && brightnessB != 255)
{
brightnessB++;
}
analogWrite(LedPinA, brightnessB);
Serial.println(brightnessB);
delay(5);
}
///////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/f629888f2fedea9442ba74dc8761fcb3.png)

Wire it up as the above diagram and upload well the code to the board, then you can see one cap lights up while the other one is off. When tilt these two caps towards the same side, one cap is gradually become bright, another bright cap is gradually off.

![Example Result illustration](../media/cfc57515b967d19fcda65ea50bda76f1.png)

---
