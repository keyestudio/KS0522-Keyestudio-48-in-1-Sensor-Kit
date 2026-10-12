# Lección 40: Visualización de temperatura y humedad

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 40: ilustración de visualización de temperatura y humedad](../media/e164737761b08de30da9358b47511d62.png)

## Introducción

Este sensor DHT11 presenta salida de señal digital calibrada con el sensor combinado de temperatura y humedad. Su tecnología garantiza alta fiabilidad y una excelente estabilidad a largo plazo.

Un microcontrolador de 8 bits de alto rendimiento está integrado en el sensor. Este sensor incluye un elemento resistivo y un dispositivo de medición de temperatura NTC sensible a la humedad.

Tiene ventajas de excelente calidad, respuesta rápida, capacidad antiinterferencias y alta relación rendimiento-precio.

Cada sensor DHT11 cuenta con datos de calibración extremadamente precisos de la cámara de calibración de humedad. Los coeficientes de calibración están almacenados en la memoria OTP del programa; los sensores internos detectan señales durante el proceso, y debemos emplear estos coeficientes de calibración.

El sistema integra una interfaz serial de un solo cable para que sea rápido y fácil. Sus cualidades de tamaño reducido, bajo consumo y una distancia de transmisión de señal de 20 metros lo hacen aplicable en una amplia gama de usos, incluso en los más exigentes.

## Especificaciones

- Voltaje de alimentación: +5 V

- Rango de temperatura: 0-50 °C con un error de ±2 °C

- Humedad: 20-90% RH con un error de ±5% RH

- Interfaz: Digital

## Diagrama de conexión

Primero debes preparar los siguientes componentes antes de la prueba.

- Placa V4.0\*1

- Sensor DHT11\*1

- Cable USB\*1

- Cables jumper\*3

Luego, sigue el diagrama de conexiones: conecta el pin de señal (Signal) del sensor al puerto Digital 4 de la placa V4.0, el pin negativo a GND y el pin positivo a 5V.

![Ilustración del diagrama de conexión](../media/d10a0556ea9e4a8314ee21f8f58ff236.jpeg)

## Código de ejemplo

Por favor descarga primero la biblioteca [DHT11Lib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib). O [visita el sitio web](http://playground.arduino.cc/Main/DHTLib)

Copia y pega el código siguiente en el software de Arduino.

```c
#include <dht.h>

dht DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test"));
  Serial.print(F("DHTlib version: "));
  Serial.println(DHT_LIB_VERSION);
  Serial.println(F("Status,Humidity (%),Temperature (C)"));
}

void loop() {
  const int status = DHT.read11(DHT11_PIN);

  switch (status) {
    case DHTLIB_OK:
      Serial.print(F("OK, "));
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print(F("Checksum error, "));
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print(F("Timeout error, "));
      break;
    default:
      Serial.print(F("Unknown error, "));
      break;
  }

  Serial.print(DHT.humidity, 1);
  Serial.print(F(", "));
  Serial.println(DHT.temperature, 1);
  delay(2000);
}
```

## Resultado de ejemplo

Conéctalo correctamente y sube el código anterior a la placa V4.0.

![Ilustración del resultado de ejemplo](../media/cdbb75de748e3e2eb6f709b8f469193d.png)

Luego abre el monitor serial y ajusta la velocidad a 9600 baudios; finalmente verás los valores actuales de temperatura y humedad.

![Ilustración del resultado de ejemplo](../media/dffe8c9a0b348f7f4f12cbfe95c090f3.jpeg)

---
