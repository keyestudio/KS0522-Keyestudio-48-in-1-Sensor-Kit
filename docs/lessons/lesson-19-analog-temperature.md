# Lección 19: Temperatura analógica

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno (ATmega328P)

![Proyecto 19: ilustración de Temperatura analógica](../media/8269d6536e383bcc592da1ae98bc3661.png)

## Descripción

Este módulo se basa en el principio de funcionamiento de un termistor (la resistencia varía con el cambio de temperatura en el entorno).

Puede detectar cambios de temperatura en el entorno y enviar los datos al IO analógico de la placa Arduino.

Solo necesitamos convertir los datos de salida del sensor a grados Celsius mediante una programación sencilla, y finalmente mostrarlos en el monitor.

Es tanto conveniente como eficaz, por lo que se aplica ampliamente en jardinería, sistemas de alarma domésticos y otros dispositivos.

## Especificaciones

- Tipo de interfaz: analógica

- Voltaje de funcionamiento: 5V

- Rango de temperatura: -55℃～315℃

- Tamaño: 30\*20mm

- Peso: 3g

## Diagrama de conexión

Primero, prepara las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Sensor de temperatura analógico\*1

- Cable USB\*1

- Cables de puente\*3

Conecta el pin S del módulo a Analog A0 de la placa V4.0, conecta el pin negativo al puerto GND, y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/330d37f05ac235a850d06726284243a5.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop()
{int sensorValue = analogRead(A0);
Serial.println(sensorValue);
  delay(1); }
////////////////////////////////////////////////////////////////////
```

El código anterior es solo para el valor analógico.

Puedes ver que el valor analógico cambia según la variación de temperatura en el entorno. Pero no es muy evidente.

Resolvamos esto usando la siguiente ecuación. Después, sube el código a la placa Arduino. El valor leído por el puerto serie será similar a la temperatura real. Ejemplo: la temperatura ahora es 30°C.

```c
////////////////////////////////////////////////////////////////////
#include <math.h>
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  double val=analogRead(0);
  double fenya=(val/1023)*5;
  double r=(5-fenya)/fenya*4700;
  Serial.println( 1/(  log(r/10000) /3950 + 1/(25+273.15))-273.15);
  delay(1000);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/9ae4e8962bf9d46ceeb3ca0c2e560f43.png)

Tras realizar las conexiones y alimentar como en la figura anterior, subir correctamente el código a la placa y abrir el monitor serie del IDE de Arduino, verás el valor de la temperatura actual.

![Ilustración del resultado de ejemplo](../media/005b4c639460eba8158f99637f03686b.jpeg)

---
