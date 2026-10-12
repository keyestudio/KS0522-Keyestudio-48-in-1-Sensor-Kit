# Lección 14: Interruptor de inclinación digital

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno (ATmega328P)

![Proyecto 14: ilustración del interruptor de inclinación digital](../media/45a40bdcc098c1c4e0efb8246447173c.png)

## Descripción

El sensor de inclinación es un interruptor de inclinación digital. Puede usarse como un interruptor de inclinación simple.

Conéctalo simplemente a nuestro shield de E/S y sensores; la conexión de cables es sencilla. Con un shield de sensores dedicado y un Arduino, puedes crear muchos proyectos interesantes e interactivos.

## Especificaciones

- Tensión de alimentación: 3.3V a 5V

- Interfaz: Digital

- Tamaño: 30*20mm

- Peso: 3g

## Diagrama de conexión

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND, el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/b909cdd6f697779371498723dc1407ab.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
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
```

## Resultado de ejemplo

Una vez cableado y alimentado, sube correctamente el código a la placa V4.0.

![Ilustración del resultado de ejemplo](../media/d6a0aa9af1e43265114eec8570ac0f3c.png)

Entonces inclina el sensor; verás que el LED del sensor se enciende. Se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/6c4a144c26675a100bffa806c532736c.png)

---
