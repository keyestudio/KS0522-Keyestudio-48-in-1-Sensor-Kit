# Lesson 12: Hall Magnetic Sensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 12: Hall Magnetic Sensor illustration](../media/c3d4d513b72ac04fad7e4f3015bfb1ed.png)

## Description

This is a magnetic induction sensor. It can sense the magnetic materials within a detection range up to 3cm. The detection range and the strength of magnetic field are proportional. The output is digital on/off.

This sensor uses the SFE Reed Switch - Magnetic Field Sensor.

## Specification

- Sensing magnetic materials

- Detection range: up to 3cm

- Output: digital on/off

- Size: 30*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Hall sensor \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/db4db0c53435ceb1d6caaaf40502247a.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Wire it up and upload well the code to board, you will see that D13 indicator on V4.0 board is off, and led on the module is also off.

![Example Result illustration](../media/102f67e289b5834de7fa80b6e6d99c20.png)

But if put a magnetic ball close to the hall module, you will see the D13 indicator on V4.0 board is turned on, and led on the module is also turned on.

![Example Result illustration](../media/c3c4044f2205dd1ff162ef7e211d2b2c.png)

---
