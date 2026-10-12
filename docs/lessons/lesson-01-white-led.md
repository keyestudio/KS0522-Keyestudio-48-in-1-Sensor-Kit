# Lección 01: LED blanco

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Proyecto 1: ilustración del LED blanco](../media/6819f1c2047a7bb2b58e9cf0d7d3a617.jpeg)

## Descripción

Este módulo de LED blanco es ideal para principiantes en Arduino. Se puede conectar fácilmente al shield de E/S o al shield de sensores. Permite la interacción con proyectos relacionados con la luz.

Nota: Puedes elegir otros módulos LED para emitir colores diferentes, como amarillo, rojo, verde y azul.

## Especificaciones

- Módulo LED blanco

- Tipo: Digital

- Conector PH2.54

- Tamaño: 30\*20mm

- Peso: 3g

## Diagrama de conexión

Primero, debes preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Módulo LED blanco \*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/cb67155c3b3cf25025edea5ae31d6c5f.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
const uint8_t ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

## Resultado de ejemplo

Con el cableado realizado y la alimentación conectada, y al subir correctamente el código, verás que el módulo LED emite luz blanca.

![Ilustración del resultado de ejemplo](../media/40448f38601a6312bfb1e3764be22158.png)

---
