# Lección 02: LED RGB

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Placa Keyestudio V4.0 / compatible con Arduino Uno ATmega328P

![Proyecto 2: ilustración LED RGB](../media/de14ae0679267cf87837b7c09934c52e.png)

## Descripción

Este es un módulo LED de color completo, que contiene 3 colores básicos－rojo, verde y azul. Pueden verse como LEDs separados.

Tras programar, puedes encenderlos y apagarlos por secuencia o también usar la salida analógica PWM para mezclar los tres colores y generar diferentes colores.

## Especificación

- Color: rojo, verde y azul

- Brillo: Alto

- Voltaje: 5V

- Entrada: nivel digital

- Tamaño: 30 \*20mm

- Peso: 3g

## Diagrama de conexión

Primero, necesitas preparar los siguientes componentes antes de la conexión:

- Placa V4.0\*1

- Módulo LED RGB \*1

- Cable USB\*1

- Cables de puente\*4

Conecta el pin V del módulo al puerto 5V de la placa V4.0, conecta el pin B al Digital 11, el pin R al Digital 10 y el pin G al Digital 9.

![Ilustración del diagrama de conexión](../media/2c0a9305cd7c7b0c28c51bc2bc24eb39.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
const uint8_t redPin = 11;
const uint8_t bluePin = 10;
const uint8_t greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for (int value = 255; value >= 0; --value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
  for (int value = 0; value < 255; ++value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
}
```

## Resultado de ejemplo

Con el cableado realizado y alimentado, y tras subir correctamente el código, verás que el módulo LED RGB emite colores brillantes.

![Ilustración del resultado de ejemplo](../media/0872e5256edf443efcb68218505096ba.png)

---
