# Lección 22: Sonido analógico

> **Kit:** Kit de sensores 48 en 1 de Keyestudio  
> **Placa:** Placa Keyestudio V4.0 / compatible con Arduino Uno (ATmega328P)

![Ilustración del Proyecto 22: Sonido analógico](../media/a494bbec73f7c8ff91b3133c9d2798a7.jpeg)

## Descripción

El sensor de sonido analógico se utiliza normalmente para detectar el volumen de los sonidos ambientales. El sensor incluye un potenciómetro, con el que puedes girar para ajustar la ganancia de la señal.

Puedes usarlo para crear proyectos interesantes e interactivos, como un interruptor activado por voz.

## Especificación

- Tensión de alimentación: 3.3V a 5V

- Interfaz: Analógica

- Tamaño: 30*20mm

- Peso: 4g

## Diagrama de conexión

Conecta el pin S del módulo al pin analógico A0 de la placa V4.0, conecta el pin negativo a GND y el pin positivo a 5V.

![Ilustración del diagrama de conexión](../media/22e1124550d57015a6d2d5782b8febda.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
int sensorPin =A0 ;
int value = 0;
void setup()
{
 Serial.begin(9600); }
void loop()
{
 value = analogRead(sensorPin);

Serial.println(value, DEC);

delay(50);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Tras realizar las conexiones y alimentar la placa, sube correctamente el código, luego abre el Monitor Serie y ajusta la tasa de baudios a 9600; verás el valor analógico. Al hablar hacia el micrófono, el valor aumentará. Se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/4d753036151413a1bdda3c0b283b8551.png)

---
