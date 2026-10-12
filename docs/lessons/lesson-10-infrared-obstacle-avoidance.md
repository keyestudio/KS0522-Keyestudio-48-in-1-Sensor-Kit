# Lección 10: Evitación de obstáculos por infrarrojos

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Placa Keyestudio V4.0 / Placa compatible con Arduino Uno ATmega328P

![Proyecto 10: Evitación de obstáculos por infrarrojos (ilustración)](../media/54ab9db703340471fd9c3151934b85e7.png)

## Descripción

El sensor detector de obstáculos por infrarrojos está equipado con función de ajuste de distancia y está especialmente diseñado para robots con ruedas.

Este sensor tiene una fuerte adaptabilidad a la luz ambiental y es de alta precisión.

Tiene un par de tubos emisor y receptor de infrarrojos. Cuando el rayo infrarrojo emitido por el tubo emisor encuentra un obstáculo (su reflector), el rayo infrarrojo se reflejará hacia el tubo receptor, de modo que el indicador se encenderá y la interfaz de salida de señal emitirá una señal digital.

Además, puedes girar la perilla del potenciómetro para ajustar la distancia de detección (distancia efectiva: 2～40cm, Voltaje de trabajo: 3.3V-5V).

Gracias a su amplio rango de voltaje, este sensor puede funcionar de forma estable incluso con voltajes de alimentación fluctuantes, y es adecuado para diversos microcontroladores, controladores Arduino y controladores BS2.

Un robot equipado con este sensor puede detectar obstáculos en el entorno.

## Especificaciones

- Voltaje de trabajo: DC 3.3V-5V

- Corriente de trabajo: ≥20mA

- Temperatura de trabajo: －10℃ a＋50℃

- Distancia de detección: 2-40cm

- Interfaz IO: 4 pines (-/+/S/EN)

- Señal de salida: Voltaje TTL

- Modo de ajuste: Potenciómetro de múltiples vueltas

- Ángulo efectivo: 35°

## Diagrama de conexión

Primero, debes preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Módulo detector de obstáculos \*1

- Cable USB\*1

- Cables de puente\*3

Conecta el pin Out del módulo al Digital 2 de la placa V4.0, conecta el pin V+ al puerto 5V, y el pin GND al puerto GND.

![Diagrama de conexión (ilustración)](../media/48f60a482d777df19bc43a3203479b0c.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
const uint8_t sensorPin = 2;
const uint8_t ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  const int sensorState = digitalRead(sensorPin);
  digitalWrite(ledPin, sensorState == HIGH ? HIGH : LOW);
}
```

## Resultado de ejemplo

Una vez subido el código a la placa, puedes ver que el LED tanto de la placa V4.0 como del sensor detector de obstáculos está encendido.

![Resultado de ejemplo (ilustración)](../media/44d035dfe09b4c803becd84c95b05956.png)

Si colocamos un bloque de espuma frente al sensor, esta vez, cuando el sensor detecte el obstáculo, el LED del sensor se encenderá.

![Resultado de ejemplo (ilustración)](../media/da4468fead816d42b2ac43b29716b91f.png)

---
