# Lección 48: Matriz de puntos

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / Placa compatible Arduino Uno ATmega328P

![Ilustración del proyecto 48: Matriz de puntos](../media/10e87958bbef207075643ae4f5481457.jpeg)

## Introducción

¿Qué es mejor que un solo LED? ¡Muchos LEDs! Una forma divertida de crear una pequeña pantalla es usar una matriz de 8x8. Este módulo utiliza el chip HT16K33 para controlar una matriz de puntos 8x8.

Solo es necesario usar el puerto de comunicación I2C del microcontrolador para controlar la matriz de puntos, lo que puede ahorrar más recursos de pines del microcontrolador. El módulo de la matriz viene con un cabezal de 4 pines con paso de 2.54 mm.

Puedes conectar el módulo a la placa de control para la comunicación usando cables dupont.

Además, viene con tres interruptores DIP. Puedes alternar aleatoriamente el interruptor para seleccionar la dirección de comunicación I2C.

## Los ajustes de dirección son los siguientes

|   0x70   |          |          |      |   0x71   |          |          |      |   0x72   |          |          |
| :------: | :------: | :------: | ---- | :------: | :------: | :------: | ---- | :------: | :------: | :------: |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 0（APAGADO） | 0（APAGADO） | 0（APAGADO） |      | 1（ENCENDIDO）  | 0（APAGADO） | 0（APAGADO） |      | 0（APAGADO） | 1（ENCENDIDO）  | 0（APAGADO） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x73** |          |          |      | **0x74** |          |          |      | **0x75** |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 1（ENCENDIDO）  | 1（ENCENDIDO）  | 0（APAGADO） |      | 0（APAGADO） | 0（APAGADO） | 1（ENCENDIDO）  |      | 1（ENCENDIDO）  | 0（APAGADO） | 1（ENCENDIDO）  |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x76** |          |          |      | **0x77** |          |          |      |          |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      |          |          |          |
| 0（APAGADO） | 1（ENCENDIDO）  | 1（ENCENDIDO）  |      | 1（ENCENDIDO）  | 1（ENCENDIDO）  | 1（ENCENDIDO）  |      |          |          |          |

## Detalles técnicos

- Interfaz: conector de 4 pines

- Voltaje de funcionamiento: DC 4.5V-5.5V

- Incluye tres interruptores DIP para la selección de dirección

- Dimensiones：52mm\*34mm\*11mm

- Peso：13.2g

## Guía de conexiones

Conecta el pin SCL al puerto Analógico A5, el pin SDA al puerto Analógico A4; conecta el pin VCC al puerto 5V, GND al puerto GND.

![Ilustración de la guía de conexiones](../media/e2c09c1a7851f64ad03a027c1aa25a14.jpeg)

## Código de prueba

Descarga la biblioteca:

```C
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif
Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
uint8_t counter = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 test");
  matrix.begin(0x70);  // pass in the address
}
void loop() {
  // paint one LED per row. The HT16K33 internal memory looks like
  // a 8x16 bit matrix (8 rows, 16 columns)
  for (uint8_t i=0; i<8; i++) {
// draw a diagonal row of pixels

    matrix.displaybuffer[i] = _BV((counter+i) % 16) | _BV((counter+i+8) % 16)  ;
  }
  // write the changes we just made to the display
  matrix.writeDisplay();
  delay(100);
 counter++;
  if (counter >= 16) counter = 0;
}
```

**Nota:** antes de compilar el código, recuerda colocar la carpeta de la biblioteca Matrix en el directorio \\Arduino\\libraries. De lo contrario, la compilación fallará.

Por ejemplo: **C:\\Program Files\\Arduino\\libraries**

## Resultado de la prueba

Una vez subido el código a la placa y encendida la alimentación, deberías ver la matriz 8\*8 mostrando una imagen de corazón. Mostrado abajo.

![Ilustración del resultado de la prueba](../media/4a53bb681a3299be450726255f4d56a2.jpeg)

## Método de configuración

1. Ajusta la dirección de comunicación. Consulta la tabla de direcciones.

El código está configurado como sigue.

![Ilustración del método de configuración](../media/187557b09de67c1236bfd6536b0b95ee.png)

![Ilustración del método de configuración](../media/910472d4662d0c1f463f9bedfe4cef74.png)

![Ilustración del método de configuración](../media/165615f73e4c9a49c861f5e17eb333e3.png)

1. Ajusta la imagen mostrada

Puedes definir la imagen que se muestra en el código que se muestra a continuación.

![Ilustración del método de configuración](../media/4a709cb4583c82f469c179dd6b1cfa71.png)

Coloca el módulo de la matriz de puntos como sigue:

![Ilustración del método de configuración](../media/10e87958bbef207075643ae4f5481457.jpeg)

Luego convierte 0x00,0x18,0x24,0x42,0x81,0x99,0x66,0x00 en números binarios:

- `0x00` corresponde a `0 0 0 0 0 0 0 0`.

- `0x18` corresponde a `0 0 0 1 1 0 0 0`.

- `0x24` corresponde a `0 0 1 0 0 1 0 0`.

- `0x42` corresponde a `0 1 0 0 0 0 1 0`.

- `0x81` corresponde a `1 0 0 0 0 0 0 1`.

- `0x99` corresponde a `1 0 0 1 1 0 0 1`.

- `0x66` corresponde a `0 1 1 0 0 1 1 0`.

- `0x00` corresponde a `0 0 0 0 0 0 0 0`.

El primer número hexadecimal controla la primera columna de LEDs.

El segundo valor controla la segunda columna, y así sucesivamente.

Estos ajustes convierten cada valor hexadecimal de 8 bits en su representación binaria.

El número 0 significa LED apagado, y el número 1 significa LED encendido.

El primer número convertido controla el encendido/apagado de la primera fila de LEDs, y así sucesivamente.

![Ilustración del método de configuración](../media/3ba4bb34ddf3ef182c5aa5bc7a309605.png)

---
