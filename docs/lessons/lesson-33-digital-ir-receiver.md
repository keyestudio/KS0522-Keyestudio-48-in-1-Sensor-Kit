# Lección 33: Receptor IR digital

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Proyecto 33: Ilustración del receptor IR digital](../media/f64f21b6ca681f928c3318bd2d33a017.png)

## Descripción

El IR se utiliza ampliamente en controles remotos. Con este receptor IR, un proyecto Arduino puede recibir comandos de cualquier control remoto IR si cuentas con el decodificador adecuado. Además, también será fácil crear tu propio controlador IR usando un transmisor IR.

## Especificaciones

- Alimentación: 5V

- Interfaz: Digital

- Frecuencia de modulación: 38Khz

- Conector de interfaz del módulo: JST PH2.0

- Tamaño: 30*20mm

- Peso: 4g

## Diagrama de conexión

En primer lugar debes preparar las siguientes piezas antes de la conexión.

- Placa V4.0\*1

- Módulo receptor IR\*1

- Cable USB\*1

- Cables jumper\*3

Conecta el pin S del módulo al pin Digital 11 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

En el código de ejemplo siguiente se utiliza el pin Digital 11; puedes cambiar el cableado o modificar el código de ejemplo para que coincidan.

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
///////////////////////////////////////////////////////////////
#include <IRremote.h>
 int RECV_PIN = 11;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

///////////////////////////////////////////////////////////////
```

**Nota:** antes de compilar el código, recuerda colocar la librería en el directorio 'libraries' del IDE de Arduino. De lo contrario, la compilación fallará.

IR Remote Library incluye algunos ejemplos de código para enviar y recibir.

<https://github.com/shirriff/Arduino-IRremote>

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/2692333113be48ffa11c27649d18dcb8.png)

Una vez realizado el cableado y subido el código, controla el módulo receptor IR con un control remoto infrarrojo; el LED D1 parpadeará.

![Ilustración del resultado de ejemplo](../media/4bb52e2957e3aaeace252021e7084c95.png)

---
