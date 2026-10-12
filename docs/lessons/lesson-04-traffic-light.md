# Lección 04: Semáforo

> **Kit:** Kit de sensores Keyestudio 48-en-1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno (ATmega328P)

![Proyecto 4: Ilustración del semáforo](../media/a20653cffac8985dc4919614540ac367.jpeg)

## Descripción

Al aprender sobre microcontroladores, normalmente se usan tres LEDs —rojo, verde y amarillo— para simular el parpadeo de un semáforo mediante una conexión externa.

En esta ocasión hemos diseñado especialmente este módulo, que es muy conveniente para el cableado, y en el módulo se pueden ver los LED rojo, amarillo y verde.

Este módulo es totalmente compatible con el microcontrolador Arduino y con el sistema Raspberry Pi.

## Especificaciones

- Tensión de trabajo: 3.3-5v

- Tipo de interfaz: digital

- Conector PH2.54

## Diagrama de conexión

Primero, necesita preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Módulo de semáforo \*1

- Cable USB\*1

- Cables jumper\*4

Conecte el pin R del módulo al Digital 5 de la placa V4.0, conecte el pin Y al Digital 4, el pin G al Digital 3, y el pin GND al puerto de tierra.

![Ilustración del diagrama de conexión](../media/b6884692ce41d05d4afb167af5b2239d.jpeg)

## Código de ejemplo

Copie y pegue el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
int redled =5; // initialize digital pin 5.
int yellowled =4; // initialize digital pin 4.
int greenled =3; // initialize digital pin 3.
void setup()
{
pinMode(redled, OUTPUT);// set the pin with red LED as “output”
pinMode(yellowled, OUTPUT); // set the pin with yellow LED as “output”
pinMode(greenled, OUTPUT); // set the pin with green LED as “output”
}
void loop()
{
digitalWrite(greenled, HIGH);//// turn on green LED
delay(5000);// wait 5 seconds
digitalWrite(greenled, LOW); // turn off green LED
for(int i=0;i<3;i++)// blinks for 3 times
{
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, HIGH);// turn on yellow LED
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, LOW);// turn off yellow LED
}
delay(500);// wait 0.5 seconds
digitalWrite(redled, HIGH);// turn on red LED
delay(5000);// wait 5 seconds
digitalWrite(redled, LOW);// turn off red LED
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Una vez subido el código y alimentado, los tres LED del módulo simularán automáticamente el encendido y apagado del semáforo de forma cíclica.

![Ilustración del resultado de ejemplo](../media/6dd1ff8660b0a62795bd53fc6b6ff591.png)

---
