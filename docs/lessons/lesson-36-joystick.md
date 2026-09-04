# Lesson 36: Joystick

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 36: Joystick illustration](../media/310a620a28ae6ebeeee7294bdc7a2bb0.png)

## Description

Lots of robot projects need joystick. This module provides an affordable solution. By simply connecting to two analog inputs, the robot is at your commands with X, Y control. It also has a switch that is connected to a digital pin.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Analog x2, Digital x1

- Size: 40*28mm

- Weight: 12g

## Connection Diagram

Firstly you need to prepare the following parts before connection.

- V4.0 Board\*1

- Joystick module\*1

- USB Cable\*1

- Jumper Wire\*5

Connect the Y pin of module to Analog A1 of V4.0 board, connect the X pin to Analog A0, B pin to Digital 3; Connect negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/3c0d2f553f6e76565171dae78a440568.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
int JoyStick_X = 0; //x
int JoyStick_Y = 1; //y
int JoyStick_Z = 3; //key
  void setup()
{
  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600); // 9600 bps
}
void loop()
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  Serial.print(x ,DEC);
  Serial.print(",");
  Serial.print(y ,DEC);
  Serial.print(",");
  Serial.println(z ,DEC);
  delay(100);
}
///////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/5e6809517dd961c3740b04c7774c3e75.png)

Wiring well and uploading the code, open the serial monitor on Arduino software, and set the baud rate as 9600, you will see the value shown below. If push the joystick downward /upward /leftward /rightward, the data will change.

![Example Result illustration](../media/6b3a1bd089cafce0f1db02f405ab5035.jpeg)

---
