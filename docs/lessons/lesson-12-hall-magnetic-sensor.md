# Lección 12: Sensor magnético Hall

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 12: Ilustración del sensor magnético Hall](../media/c3d4d513b72ac04fad7e4f3015bfb1ed.png)

## Descripción

Este es un sensor de inducción magnética. Puede detectar materiales magnéticos dentro de un rango de detección de hasta 3 cm. El rango de detección y la intensidad del campo magnético son proporcionales. La salida es digital (encendido/apagado).

Este sensor utiliza el SFE Reed Switch - Magnetic Field Sensor.

## Especificación

- Detección de materiales magnéticos

- Rango de detección: hasta 3 cm

- Salida: digital encendido/apagado

- Tamaño: 30*20mm

- Peso: 3g

## Diagrama de conexión

Primero, necesitas preparar las siguientes piezas antes de la conexión:

- V4.0 Placa\*1

- Sensor Hall \*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/db4db0c53435ceb1d6caaaf40502247a.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Conéctalo y sube correctamente el código a la placa; verás que el indicador D13 en la placa V4.0 está apagado y el LED del módulo también está apagado.

![Ilustración del resultado de ejemplo](../media/102f67e289b5834de7fa80b6e6d99c20.png)

Pero si acercas una esfera magnética al módulo Hall, verás que el indicador D13 en la placa V4.0 se enciende y el LED del módulo también se enciende.

![Ilustración del resultado de ejemplo](../media/c3c4044f2205dd1ff162ef7e211d2b2c.png)

---
