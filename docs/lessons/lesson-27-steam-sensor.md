# Lección 27: Sensor de vapor

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno (ATmega328P)

![Proyecto 27: ilustración del sensor de vapor](../media/d19ac9430f793cdbedde891ee92671e7.jpeg)

## Descripción

El sensor de vapor es un sensor analógico y puede usarse como un detector de lluvia sencillo y como interruptor de nivel de líquido. Cuando la humedad en la superficie de este sensor aumenta, el voltaje de salida incrementará.

Precaución: las partes de conexión no son impermeables, por favor no las sumerjas en agua.

## Parámetros

- Voltaje de funcionamiento: 3.3V o 5V

- Corriente de funcionamiento: \<20mA

- Rango de temperatura de funcionamiento: －10℃～＋70℃

- Tipo de interfaz: Salida de señal analógica

## Definición de pines

- Pin S: salida de señal

- Pin positivo (+): alimentación (VCC)

- Pin negativo (-): tierra (GND)

## Diagrama de conexión

Primero, debes preparar las siguientes piezas antes de la conexión:

- Placa V4.0*1

- Sensor de vapor*1

- Cable USB*1

- Cables jumper*3

Conecta el pin S del módulo al pin analógico A0 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/8fa51466dbc9650dcaa740bce4dd654e.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //open serial port, and set baud rate at 9600bps
}
void loop()
{
int val;
val=analogRead(0); //plug vapor sensor into analog port 0
Serial.print("Moisture is ");
Serial.println(val,DEC); //read analog value through serial port printed
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/c4633c5911c042224d187645db4d0588.png)

Al detectar distintos grados de humedad, el sensor obtendrá la retroalimentación de diferentes valores de corriente. Se muestra en la imagen siguiente.

Debido a las condiciones limitadas, puedes poner una gota de agua sobre el sensor; el valor de humedad cambiará en el monitor serial del software de Arduino.

![Ilustración del resultado de ejemplo](../media/80e9b3e19db4bec337f3254545a58e9e.jpeg)

---
