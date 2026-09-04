# Lesson 11: Photo Interrupter

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 11: Photo Interrupter illustration](../media/8b0f7b3ba3e139eeaeba9bb7f86a946a.png)

## Description

Upright part of this sensor is an infrared emitter and on the other side, it’s a shielded infrared detector. By emitting a beam of infrared light from one end to other end, the sensor can detect an object when an object passes through the beam.

It is used for many applications including optical limit switches, pellet dispensing, general object detection, etc.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Digital

- Size: 30*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Photo interrupter module \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/669fa42ef7fb576047d6849940a305ba.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
// photo interrupter module
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface
int val ;// define numeric variables val
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done uploading the code to board, you can see both led on V4.0 board and on module are turned on. Shown as below.

![Example Result illustration](../media/fa4d06ebf82ec572b7eccf6b706942cb.png)

When pick up a paper on groove joint of module, the signal is interrupted, and led1 on the module will be turned off.

![Example Result illustration](../media/3ecb941fafc71843148e0e19b6ceda57.png)

---
