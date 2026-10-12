# Lección 13: Sensor de golpes

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Ilustración del Proyecto 13: Sensor de golpes](../media/cef729e5b57059bc14518b0e2fdd2817.png)

## Descripción

Este módulo es un sensor de golpes. Cuando lo golpeas, puede enviar una señal momentánea.

Puedes combinarlo con Arduino para realizar experimentos interesantes, por ejemplo, un tambor electrónico.

## Especificaciones

- Voltaje de funcionamiento: 5V

- Tamaño: 30\*20mm

- Peso: 3g

## Diagrama de conexión

Primero, necesitas preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Sensor de golpe \*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/1b9c27f145275e7a38d06763114f1847.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
////////////////////////////////////////////////////////////////////
```

![Ilustración del código de ejemplo](../media/c3fc14de7267b517a739268ed5b88674.png)

## Resultado de ejemplo

Tras realizar el cableado y alimentar como se indicó arriba, sube correctamente el código; al golpear el sensor verás que tanto el LED D13 en la placa V4.0 como el LED D1 en el sensor se encienden.

---
