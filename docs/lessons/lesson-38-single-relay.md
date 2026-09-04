# Lesson 38: Single Relay

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-37-rotary-encoder.md) | [Course index](../README.md) | [Next lesson →](lesson-39-linear-temperature.md) |
| --- | --- | --- |

![Project 38: Single Relay illustration](../media/e0b4485cfd4ccebd974d81f19239dde3.png)

## Introduction

This single relay module can be used in interactive projects. This module uses SONGLE 5v high-quality relay. It can also be used to control lighting, electrical and other equipment.

The modular design makes it easy to use with Arduino board. It can be controlled through digital IO port, such as solenoid valves, lamps, motors and other high current or high voltage devices.

## Specification

- Type: Digital

- Rated current: 10A (NO) 5A (NC)

- Maximum switching voltage: 150VAC 24VDC

- Digital interface

- Control signal: TTL level

- Rated load: 8A 150VAC (NO), 10A 24VDC (NO), 5A 250VAC (NO/NC), 5A 24VDC (NO/NC)

- Maximum switching power: AC1200VA DC240W (NO), AC625VA DC120W (NC)

- Contact action time: 10ms

## Connection Diagram

Firstly you need to prepare the following parts before connection.

- V4.0 Board\*1

- Relay module\*1

- LED module \*1

- Breadboard \*1

- USB Cable\*1

- Jumper Wire\*9

Here we use the single relay module to control an LED module on or off.

For relay module, connect the Signal pin to Digital port 8 of V4.0 board, then connect its positive pin to anode row of breadboard, lead off the row to 5V port of V4.0 board. Connect its negative pin to cathode row of breadboard, lead off the row to GND port of V4.0 board.

For LED module, connect its Signal pin to one terminal block of relay module, another terminal block on the relay is connected to Digital port 13 of V4.0 board. Connect its positive pin to anode row, negative pin to cathode row of breadboard.

![Connection Diagram illustration](../media/21cf9b1d5f0843230ee516a0a8be77e1.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
 int Relay = 8;
  void setup()
{
  pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop()
{
          digitalWrite(Relay, HIGH);   //Turn off relay
          delay(2000);
          digitalWrite(Relay, LOW);    //Turn on relay
          delay(2000);
}
///////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/c751be64bd8acd8c6114598b89586cfa.png)

This relay module is active at HIGH level.

Wire it up well, powered up, then upload the above code to the board, you will see the relay is turned on（ON connected, NC disconnected）for two seconds, then turned off for two seconds（NC closed,ON disconnected）, repeatedly and circularly.

When the relay is turned on, external LED is on. If relay is turned off, external LED is off.

---

| [← Previous lesson](lesson-37-rotary-encoder.md) | [Course index](../README.md) | [Next lesson →](lesson-39-linear-temperature.md) |
| --- | --- | --- |
