# Lección 25: Gas analógico

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Placa Keyestudio V4.0 / placa ATmega328P compatible con Arduino Uno

![Proyecto 25: Gas analógico ilustración](../media/36f00d2a934c497f390b49c4113c7c04.png)

## Descripción

Este sensor de gas analógico MQ2 se utiliza en equipos detectores de fugas de gas tanto en electrónica de consumo como en mercados industriales. Este sensor es adecuado para detectar GLP, isobutano, propano, metano, alcohol, hidrógeno y humo.

El rango de detección de este sensor es muy amplio y tiene alta sensibilidad y respuesta rápida.

Además, la sensibilidad puede ajustarse girando el potenciómetro en el sensor.

## Especificaciones

- Alimentación: 5V

- Tipo de interfaz: Analógica

- Circuito de conducción simple

- Estable y de larga vida útil

## Diagrama de conexión

Conecta el pin A0 del módulo al A0 analógico de la placa V4.0, conecta el pin GND al puerto GND y el pin VCC al puerto 5V.

![Diagrama de conexión ilustración](../media/7b2cdff9418f79b2e9e566ce61a7966a.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}

////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Resultado de ejemplo ilustración](../media/d440553d52e043d7a91928882d877dd1.png)

Una vez cableado y con alimentación, sube correctamente el código, luego abre el monitor serie y ajusta la tasa de baudios a 9600; verás el valor analógico. Al detectar gas, el valor cambiará.

![Resultado de ejemplo ilustración](../media/cbf777feb6231d76347bc632f87d0e8e.jpeg)

---
