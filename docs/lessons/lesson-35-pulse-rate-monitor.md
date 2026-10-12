# Lección 35: Monitor de pulso

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Ilustración del proyecto 35: Monitor de pulso](../media/0ec440cd93e00e956357ece654ce2a9c.png)

## Descripción

Este módulo utiliza un LED infrarrojo ultraclaro y un fototransistor para detectar el pulso en tu dedo. El LED rojo parpadeará al ritmo de tu pulso.

Principio de funcionamiento

Ilumina con el LED brillante un lado de tu dedo mientras el fototransistor en el otro lado detecta la cantidad de luz transmitida. La resistencia del fototransistor variará ligeramente a medida que la sangre pulsa a través de tu dedo.

## Diagrama de conexión

Primero necesitas preparar las siguientes piezas antes de realizar la prueba.

- Placa V4.0\*1

- Módulo de pulso\*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin Signal del módulo al Analog A0 de la placa V4.0, el pin positivo al puerto 5V y el pin negativo al puerto GND.

![Ilustración del diagrama de conexión](../media/fa86e3930b83753af7ad87d0418cd350.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
///////////////////////////////////////////////////////////////
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
}
void loop()
{
static double oldValue = 0;
static double oldChange = 0;
int rawValue = analogRead(sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
Serial.print(rawValue);
Serial.print(",");
Serial.println(value);
oldValue = value;
delay(period);
}
///////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Conéctalo correctamente según el diagrama anterior, sube el código a la placa y haz clic en el icono del Monitor Serie en la esquina superior derecha del software de Arduino. Ajusta la velocidad a 115200 baudios; verás los datos mostrados en el monitor.

Puedes copiar y pegar los datos en Excel; finalmente se generará la imagen correspondiente que se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/3c3a1a0d120f1c68c95095a0fd98fa47.png)

![Ilustración del resultado de ejemplo](../media/215ab9a6174f9798a291bacb907eaf89.jpeg)

---
