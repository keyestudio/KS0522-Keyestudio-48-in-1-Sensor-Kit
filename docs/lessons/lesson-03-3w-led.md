# Lección 03: LED de 3W

> **Kit:** Keyestudio Kit de sensores 48 en 1  
> **Placa:** Keyestudio V4.0 / placa ATmega328P compatible con Arduino Uno

![Ilustración del Proyecto 3: LED de 3W](../media/0b1110577bfde7df3b6aec41d5b21b28.png)

## Descripción

Este módulo LED es de alta luminosidad porque las cuentas de la lámpara que incorpora son de 3W.  
Puedes aplicar este módulo a proyectos con Arduino; es ideal para robots o plataformas de búsqueda y rescate.

Por ejemplo, robots inteligentes pueden usar este módulo para fines de iluminación.  
Tenga en cuenta que la luz del LED no debe exponerse directamente a los ojos humanos por motivos de seguridad.

## Especificación

- Temperatura de color: 6000\~7000K

- Flujo luminoso: 180\~210lm

- Corriente: 700\~750mA

- Potencia: 3W

- Ángulo de luz: 140 grados

- Temperatura de trabajo: -50\~80℃

- Temperatura de almacenamiento: -50\~100℃

- Módulo LED de alta potencia, controlado por microcontrolador mediante puerto IO

- Tipo de IO: Digital

- Voltaje de alimentación: 3.3V a 5V

- Tamaño: 40x28mm

- Peso: 6g

## Diagrama de conexión

Primero, necesitas preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Módulo LED 3W \*1

- Cable USB\*1

- Cable de puente\*3

Conecta el pin S del módulo al Digital 13 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/7ca6e53405c422f3ae9b04ac572b40ef.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
///////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
///////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Una vez realizado el cableado y alimentado, y subido correctamente el código, tanto el LED D13 como el LED del módulo parpadean durante un segundo y luego se apagan, de forma cíclica.

![Ilustración del resultado de ejemplo](../media/edeb5b089be0300c719652badfd269e7.png)

---
