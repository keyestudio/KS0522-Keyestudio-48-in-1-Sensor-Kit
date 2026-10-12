# Lección 38: Relé simple

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa ATmega328P compatible con Arduino Uno

![Proyecto 38: Relé individual ilustración](../media/e0b4485cfd4ccebd974d81f19239dde3.png)

## Introducción

Este módulo de relé simple se puede usar en proyectos interactivos. Este módulo utiliza un relé SONGLE 5v de alta calidad. También puede utilizarse para controlar iluminación, equipos eléctricos y otros aparatos.

El diseño modular facilita su uso con la placa Arduino. Puede controlarse a través del puerto IO digital, como válvulas solenoides, lámparas, motores y otros dispositivos de alta corriente o alto voltaje.

## Especificación

- Tipo: Digital

- Corriente nominal: 10A (NO) 5A (NC)

- Voltaje máximo de conmutación: 150VAC 24VDC

- Interfaz digital

- Señal de control: nivel TTL

- Carga nominal: 8A 150VAC (NO), 10A 24VDC (NO), 5A 250VAC (NO/NC), 5A 24VDC (NO/NC)

- Potencia máxima de conmutación: AC1200VA DC240W (NO), AC625VA DC120W (NC)

- Tiempo de acción del contacto: 10ms

## Diagrama de conexión

Primero necesitas preparar las siguientes piezas antes de la conexión.

- Placa V4.0\*1

- Módulo relé\*1

- Módulo LED \*1

- Protoboard \*1

- Cable USB\*1

- Cables jumper\*9

Aquí usamos el módulo de relé simple para controlar un módulo LED para encenderlo o apagarlo.

Para el módulo relé, conecta el pin Señal al puerto digital 8 de la placa V4.0, luego conecta su pin positivo a la fila de ánodo del protoboard, conduce esa fila al puerto 5V de la placa V4.0. Conecta su pin negativo a la fila de cátodo del protoboard, conduce esa fila al puerto GND de la placa V4.0.

Para el módulo LED, conecta su pin Señal a un bloque terminal del módulo relé; el otro bloque terminal del relé se conecta al puerto digital 13 de la placa V4.0. Conecta su pin positivo a la fila de ánodo y su pin negativo a la fila de cátodo del protoboard.

![Diagrama de conexión (ilustración)](../media/21cf9b1d5f0843230ee516a0a8be77e1.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
///////////////////////////////////////////////////////////////
 int Relay = 8;
  void setup()
{
  pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop()
{
          digitalWrite(Relay, HIGH);   //Turn off relay
          delay(2000);
          digitalWrite(Relay, LOW);    //Turn on relay
          delay(2000);
}
///////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Resultado de ejemplo (ilustración)](../media/c751be64bd8acd8c6114598b89586cfa.png)

Este módulo relé se activa a nivel ALTO (HIGH).

Conéctalo correctamente y aliméntalo; luego sube el código anterior a la placa. Verás que el relé se activa (NO conectado, NC desconectado) durante dos segundos, luego se desactiva (NC conectado, NO desconectado) durante dos segundos, repitiéndose de forma cíclica.

Cuando el relé está activado, el LED externo está encendido. Si el relé está desactivado, el LED externo está apagado.

---
