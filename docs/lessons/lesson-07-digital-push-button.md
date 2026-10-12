# Lección 07: Pulsador digital

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / compatible con Arduino Uno (ATmega328P) board

![Proyecto 7: Ilustración del pulsador digital](../media/a8707354e54ea51bb92584f791ae79e5.png)

## Descripción

Este es un módulo de botón básico. Puedes conectarlo fácilmente a un shield de E/S para tu primer intento con Arduino.

## Características

- Amplio rango de voltaje de 3.3V a 5V

- Interfaces de sensores fácilmente reconocibles ("A" para Analógico y "D" para Digital)

- Orificio de montaje estándar

- Ilustraciones de iconos claras

- Conector de alta calidad

- Fácil de conectar y usar

- Botón grande y tapa de alta calidad

- Para lograr proyectos interesantes e interactivos

## Especificación

- Tensión de alimentación: 3.3V a 5V

- Interfaz: Digital

- Dimensiones: 30*20mm

- Peso: 4g

## Diagrama de conexión

Primero, debes preparar las siguientes piezas antes de la conexión:

- Placa V4.0*1

- Módulo de pulsador*1

- Cable USB*1

- Cables de puente*3

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/6ec73b961481bf0794572a842c5231fa.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
/* # When you push the digital button, the Led 13 on the board will be turned on. Otherwise,the led is turned off.
*/
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
void setup() {
  pinMode(ledPin, OUTPUT);      // set LED as output
  pinMode(inputPin, INPUT);     // set pushbutton as input
}
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Conecta los cables correctamente como se muestra en la figura siguiente y luego sube el código a la placa.

Cuando pulses el botón digital, el Led 13 en la placa V4.0 se encenderá. Al soltar el botón, el led se apagará. Se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/ac03d3fa1c0f5de7dae18c6e64406e60.png)

---
