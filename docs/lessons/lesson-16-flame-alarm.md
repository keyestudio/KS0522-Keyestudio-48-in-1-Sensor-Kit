# Lesson 16: Flame Alarm

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-15-capacitive-touch.md) | [Course index](../README.md) | [Next lesson →](lesson-17-reed-switch.md) |
| --- | --- | --- |

![Project 16: Flame Alarm illustration](../media/35c5a2593df5d4e76865158e790feada.png)

## Description

This flame sensor can be used to detect fire or other lights with wavelength stands at 760nm \~ 1100nm.

In the fire-fighting robot game, the flame plays an important role in the probing, which can be used as the robot's eyes to find fire source.

## Specification

1. Supply Voltage: 3.3V to 5V

2. Detection range: 20cm (4.8V) \~ 100cm (1V)

3. Rang of Spectral Bandwidth: 760nm to 1100nm

4. Operating temperature: -25℃to 85℃

5. Interface: digital

6. Size: 44*16.7mm

7. Weight: 4g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board*1

- Flame sensor*1

- USB Cable*1

- Jumper Wire*3

Connect the D0 pin of module to Digital 2 of V4.0 board, connect the GND pin to GND port, VCC pin to 5V port.

![Connection Diagram illustration](../media/a1ee506fc9921c7616349500c258b733.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
const int flamePin = 2;     // the number of the flame pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int State = 0;         // variable for reading status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flamePin, INPUT);
}
void loop(){
  // read the state of the value:
State = digitalRead(flamePin);
  if (State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done wiring and powered up, upload well the code to the board.

![Example Result illustration](../media/c769453bbd0e1c5fcf6c80cf697030b3.png)

Then if you put a lighter close to the sensor, when the sensor detects the flame, another led on the sensor is turned on.

![Example Result illustration](../media/2ee5a36673d2cbeb934ca2af29dab607.png)

---

| [← Previous lesson](lesson-15-capacitive-touch.md) | [Course index](../README.md) | [Next lesson →](lesson-17-reed-switch.md) |
| --- | --- | --- |
