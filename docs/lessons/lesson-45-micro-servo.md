# Lesson 45: Micro Servo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 45: Micro Servo illustration](../media/12c59bd3ab0733beb6ff7802305d4384.jpeg)

## Introduction

Servomotor is a position control rotary actuator. It mainly consists of housing, circuit board, core-less motor, gear and position sensor.

Included with your servo motor you will find a variety of white motor mounts that connect to the shaft of your servo. You may choose to attach any mount you wish for the circuit. It will serve as a visual aid, making it easier to see the servo spin.

The servo has three interfaces,distinguished by brown, red and orange line (different brand may have different color). Brown line is for GND, red one for power 5V, orange one for signal terminal (PWM signal).

![Introduction illustration](../media/e7eb9914318b92eff98a4a84a8d1a557.png)

The rotation angle of servo is controlled by regulating the duty cycle of the PWM(Pulse-Width Modulation) signal. The standard cycle of the PWM signal is fixed at 20ms (50 Hz), and the pulse width is distributed between 1ms-2ms. The pulse width corresponds to the rotation angle ( 0°～90°) of servo.

![Introduction illustration](../media/723671941df8a57cf9246c9916e7b279.png)

Next, let's learn how to control a servomotor.

In this experiment, you only need a servomotor and several jumper wires.

## Connection Diagram

Connection for V4.0 :

![Connection Diagram illustration](../media/da1e3590f86a5a8ed27b333742ae49c9.jpeg)

Connection for 2560 R3:

![Connection Diagram illustration](../media/1c8bd09408be60254883b910ef4fc9bf.png)

Connect the motor to digital pin 9.

Compile a program to control the motor rotate to the commanded angle, and display the angle on the screen.

## Sample Program

There are two ways to control a servomotor with Arduino.

One is to use a common digital sensor port of Arduino to produce square wave with different duty cycle to simulate PWM signal and use that signal to control the positioning of the motor.

Another way is to directly use the Servo function of the Arduino to control the motor.

In this way, the program will be easier but it can only control two-contact motor for the servo function, only digital pin 9 and 10 can be used. The Arduino drive capacity is limited. So if you need to control more than one motor, you will need external power.

## Method 1

## Sample Program A

```c
//////////////////////////////////////////////////////////
int servopin=9;// select digital pin 9 for servomotor signal line
int myangle;// initialize angle variable
int pulsewidth;// initialize width variable
int val;
void servopulse(int servopin,int myangle)// define a servo pulse function
{
pulsewidth=(myangle*11)+500;// convert angle to 500-2480 pulse width
digitalWrite(servopin,HIGH);// set the level of servo pin as “high”
delayMicroseconds(pulsewidth);// delay microsecond of pulse width
digitalWrite(servopin,LOW);// set the level of servo pin as “low”
delay(20-pulsewidth/1000);
}
void setup()
{
pinMode(servopin, OUTPUT);
Serial.begin(9600);
Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()// convert number 0 to 9 to corresponding 0-180 degree angle, LED blinks corresponding number of time
{
val=Serial.read();// read serial port value
if(val>='0'&&val<='9')
{
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin,val);// use the pulse function
}
}
}
//////////////////////////////////////////////////////////
```

## Method 2

Let's first take a look at the Arduino built-in servo function and some common statements.

1\. **attach（interface**）——select pin for servo, can only use pin 9 or 10.

2\. **write（angle）**——used to control the rotate angle of the servo, can set the angle among 0 degree to 180 degree.

3\. **read（）**——used to read the angle of the servo, consider it a function to read the value in the write() function.

4\. **attached（）**——determine whether the parameter of the servo is sent to the servo pin.

5\. **detach（）**—— disconnect the servo and the pin, and the pin(digital pin 9 or 10) can be used for PWM port.

**Note:** the written form of the above statements are " servo variable name. specific statement ()", e.g. myservo. Attach (9).

Still, connect the servo to pin 9.

## Sample Program B

```c
#include <Servo.h>// define a header file. Special attention here, you can call the servo function directly from Arduino's software menu

Servo myservo;// define servo variable name
void setup()
{
myservo.attach(9);// select servo pin(9 or 10)
}
void loop()
{
myservo.write(90);// set rotating angle of the motor
}
```

## Example Result

![Example Result illustration](../media/f02556e0631fb206c114ced29e643016.png)

Wire it up well, upload the Program A to the board, then click to open the serial monitor of Arduino software, set the baud rate to 9600, and on the upper bar enter a number and click “Send”, you will see the servo rotate to the corresponding angle, and moving angle will be displayed on the monitor. Shown below.

Powered up, upload well the Program B to the board, first servo will turn to the angle of 90 degree.

![Example Result illustration](../media/de50d502cb8ed1feb5935d16584cfd63.png)

---
