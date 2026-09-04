# Lesson 23: Water Level

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 23: Water Level illustration](../media/23f40997b8634be91aed7311eca2dfbb.jpeg)

## Description

Keyestudio water sensor is easy- to-use, portable and cost-effective, designed to identify and detect water level and water drop.

This small sensor can measure the volume of water drop or water quantity through an array of traces of exposed parallel wires.

## Features

- smooth conversion between water quantity and analog quantity;

- strong flexibility, outputting basic analog value;

- low power consumption and high sensitivity;

- directly connect to microprocessor or other logic circuits, suitable for a variety of development boards and controllers such as Arduino controller, STC single-chip microcomputer, AVR single-chip microcomputer and more.

## Specifications

- Operating voltage: DC5V

- Operating current: ﹤20mA

- Sensor type: Analog

- Detection area: 40mm x16mm

- Production process: FR4 double-side tinned

- Shape design: Anti-skid semi-lunar recess

- Working Temperature: 10℃-30℃

- Working Humidity: 10%-90% without condensation

- Weight: 3g

- Dimensions: 65mm x 20mm x 8mm

## Connection Diagram

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/92810e41aea313a15735eecb3a168e2f.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
    int analogPin = 0; //connect water sensor to analog interface 0
int led = 13; //LED to digital interface 13
int val = 0; //define the initial value of variable ‘val’ as 0
int data = 0; //define the initial value of variable ‘data’ as 0
void setup()
{
pinMode(led, OUTPUT); //define led as output pin
Serial.begin(9600); //set baud rate at 9600
}
void loop()
{
val = analogRead(analogPin); //read and assign analog value to variable ’val’
if(val>700){ //decide whether variable ‘val’ is over 700
digitalWrite(led,HIGH); //turn on LED when variable ‘val’ is over 700
}
else{
digitalWrite(led,LOW); //turn off LED when variable ‘val’ is under 700
}
data = val; //variable ’val’ assigns value to variable ‘data’
Serial.println(data); //print variable ‘data’ by Serial.print
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/ca727c75f4d4e454c95258d77afdf10e.png)

After the above steps are done, let’s do a test on lower water level and check what happens?

Upload well the code to V4.0 board, then open the serial monitor and set the baud rate as 9600.

When place the sensor into the water at different level, you will see the value change correspondingly.

![Example Result illustration](../media/8070cf2260fef39e5ec5e18b7a1849cf.jpeg)

Furthermore, you can set an alarm value and connect a buzzer to make an alarm.

The LED can’t light up when water level haven’t reach alarm value. If water level reaches the alarm value, LED will be turned on and buzzer will sound to make an alarm.

---
