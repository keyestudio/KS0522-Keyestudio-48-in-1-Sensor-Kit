# Lesson 17: Reed Switch

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-16-flame-alarm.md) | [Course index](../README.md) | [Next lesson →](lesson-18-pir-motion-sensor.md) |
| --- | --- | --- |

![Project 17: Reed Switch illustration](../media/e580999515f6522eb603ea723bf62173.png)

## Description

Reed Switch is a special switch and a main component for reed relay and proximity switch.

Reed switch is usually comprised of two soft magnetic materials and metal reed contacts which will disconnect itself when there is no magnetic.

In addition, some reed switches are also equipped with another reed acting as the third normally-closed contact. These reed contacts are encapsulated in a glass tube full of inert gases(such as nitrogen and helium) or in a vacuum glass tube.

The reeds encapsulated in the glass tube are placed in parallel with ends overlapped. Certain amount of space or mutual contact will be reserved to constitute the normally-open or normally-closed contacts of the switch.

Reed switch can be used as for count, limit or other purposes.

For instance, a kind of bike-kilometer is constituted by sticking magnetic to the tire and mounting reed switch aside.

You can also mount reed switch on the door for alarming purpose or as switches.

Reed switch has been widely applied in household appliances, cars, communication, industry, healthcare and security areas.

Furthermore, it can also be applied to other sensors and electric devices such as liquidometer, door magnet, reed relay, oil level sensor and proximity sensor(magnetic sensor). It can be used under high-risk environment.

## Specification

1. Working voltage: DC 3.3V-5V

2. Working current: ≥20mA

3. Working temperature: －10℃ to ＋50℃

4. Detection distance: ≤10mm

5. IO Interface: 3 wire interfaces (-/+/S)

6. Size: 30\*20mm

7. Weight: 3g

## Connection Diagram

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/ad39b511b42657baed492704a9c84b13.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int buttonpin=3; //define magnetic ring sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED as output interface
pinMode(buttonpin,INPUT);//define magnetic ring sensor as output interface
 }
void loop()
{

val=digitalRead(buttonpin);// read and assign the value of digital interface 3 to val

if(val==HIGH)//When a signal is detected by magnetic ring sensor, LED will flash
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done wiring and powered up, upload well the code to the board. You can see the D13 led on V4.0 board is on.

![Example Result illustration](../media/a2f983d5a5b324f55e3c0994458d4cbc.png)

Then we put some magnetic balls close to the sensor. When the sensor detects the magnetic field signal, the led on the sensor will be turned on but D13 led will be turned off.

![Example Result illustration](../media/ecbec914abc799076513f5c61149b004.png)

---

| [← Previous lesson](lesson-16-flame-alarm.md) | [Course index](../README.md) | [Next lesson →](lesson-18-pir-motion-sensor.md) |
| --- | --- | --- |
