# Lesson 06: Passive Buzzer

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 6: Passive Buzzer illustration](../media/1bd2e3afebf5a0d3712fe42092b0a1b4.png)

## Description

We can use Arduino to make many interactive works of which the most commonly used is acoustic-optic display. The circuit in this experiment can produce sound.

Normally, the experiment can be done with a buzzer or a speaker, while buzzer is simpler and easier to use.

The buzzer we introduced here is a passive buzzer. It cannot be actuated by itself, but by external pulse frequencies. Different frequencies produce different sounds. You can use Arduino to code the melody of a song, quite fun and simple.

## Specification

- Working voltage: 3.3-5v

- Interface type: digital

- Size: 30\*20mm

- Weight: 4g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board*1

- Passive buzzer module*1

- USB Cable*1

- Jumper Wire*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/e9e7ba383738c3b6be85a1f3c97e5385.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
int buzzer=3;//set digital IO pin of the buzzer
void setup()
{
pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
}
void loop()
{ unsigned char i,j;//define variable
while(1)
{ for(i=0;i<80;i++)// output a frequency sound
{ digitalWrite(buzzer,HIGH);// sound
delay(1);//delay1ms
digitalWrite(buzzer,LOW);//not sound
delay(1);//ms delay
}
for(i=0;i<100;i++)// output a frequency sound
{
digitalWrite(buzzer,HIGH);// sound
digitalWrite(buzzer,LOW);//not sound
delay(2);//2ms delay
}
}
}
////////////////////////////////////////////////////////////////////
```

## Example Result

Done uploading the code to board, the buzzer will make a sound.

![Example Result illustration](../media/9b29eccd437694e479a836b7da66d500.png)

---
