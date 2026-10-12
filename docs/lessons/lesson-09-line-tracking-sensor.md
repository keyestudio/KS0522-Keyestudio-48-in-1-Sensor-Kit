# Lección 09: Sensor de seguimiento de línea

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 9: Ilustración del sensor de seguimiento de línea](../media/c476ef922ab6a8d31cb68f3ab3fa2ced.png)

## Descripción

Este sensor de seguimiento de línea puede detectar línea blanca sobre negro o línea negra sobre blanco.

La señal de seguimiento de línea de un solo canal proporciona una salida TTL estable para un seguimiento de línea más preciso y estable. La opción multicanal se puede lograr fácilmente instalando los sensores de seguimiento de línea necesarios.

## Especificación

1. Alimentación: +5V

2. Corriente de funcionamiento: \<10mA

3. Rango de temperatura de funcionamiento: 0°C \~ + 50°C

4. Interfaz de salida: interfaz de 3 hilos (1 - señal, 2 - alimentación, 3 - negativo de la alimentación)

5. Nivel de salida: nivel TTL

## Diagrama de conexión

Primero, necesita preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Módulo de seguimiento de línea \*1

- Cable USB\*1

- Cable jumper\*3

Conecte el pin S del módulo al Digital 3 de la placa V4.0, conecte el pin GND al puerto GND y el pin V+ al puerto 5V.

![Ilustración del diagrama de conexión](../media/6727a1d7d92c3878fc51b8db0502fd14.jpeg)

## Código de ejemplo

Copie y pegue el código siguiente en el software Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(3)); // print the data from the sensor
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/af115c59987fee06447790f1740e3203.jpeg)

Una vez cargado el código en la placa, abra el monitor serial y ajuste la velocidad de baudios a 9600; entonces podrá ver los datos del sensor.

---
