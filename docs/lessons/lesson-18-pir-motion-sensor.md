# Lección 18: Sensor de movimiento PIR

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 18: ilustración del sensor de movimiento PIR](../media/ce608db25742f19fdf6eceda756a59d9.png)

## Descripción

El sensor de movimiento por infrarrojos piroeléctrico puede detectar señales infrarrojas de una persona o animal en movimiento y emitir señales de conmutación.

Puede aplicarse en diversas situaciones para detectar el movimiento del cuerpo humano.

Los sensores infrarrojos piroeléctricos convencionales requieren un detector piroeléctrico corporal, un chip profesional y un circuito periférico complejo, por lo que su tamaño es mucho mayor, con circuitos complicados y menor fiabilidad.

Ahora presentamos este nuevo sensor de movimiento piroeléctrico por infrarrojos, diseñado especialmente para Arduino.

Emplea un sensor piroeléctrico corporal infrarrojo digital integrado, con tamaño más reducido, mayor fiabilidad, menor consumo y circuito periférico más simple.

## Especificaciones

- Voltaje de entrada: 3.3 \~ 5V, máximo 6V

- Corriente de trabajo: 15uA

- Temperatura de funcionamiento: -20 \~ 85 ℃

- Voltaje de salida: Alto 3V, Bajo 0V

- Tiempo de retardo de salida (nivel alto): Aproximadamente 2.3 a 3 segundos

- Ángulo de detección: 100 °

- Distancia de detección: 7 metros

- LED indicador de salida (si la salida está HIGH, se encenderá)

- Corriente límite por pin: 100mA

- Tamaño: 30*20mm

- Peso: 4g

## Diagrama de conexión

Primero, necesita preparar los siguientes componentes antes de la conexión:

- Placa V4.0*1

- Sensor de movimiento PIR*1

- Cable USB*1

- Cables jumper*3

Conecte el pin S del módulo al Digital 3 de la placa V4.0, conecte el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/01970d510c03a8c7aa3ef0c13ea70cff.jpeg)

## Código de ejemplo

Copie y pegue el código siguiente en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
byte sensorPin = 3;
byte indicator = 13;
void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  if(state == 1)Serial.println("Somebody is in this area!");
  else if(state == 0)Serial.println("No one!");
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Después de hacer el cableado y alimentar la placa, subir bien el código, si el sensor detecta a alguien moviéndose cerca, el indicador D13 en la placa V4.0 se encenderá, y "¡Alguien está en esta área!" se mostrará en el monitor serial del software Arduino.

Si no detecta movimiento, el indicador D13 en la placa V4.0 estará apagado, y "¡Nadie!" se mostrará en el monitor serial.

![Ilustración del resultado de ejemplo](../media/e25d28654311fa7820a1886a285353e5.png)

![Ilustración del resultado de ejemplo](../media/9b6209c8ce5b4be73f8378d21b639d28.jpeg)

---
