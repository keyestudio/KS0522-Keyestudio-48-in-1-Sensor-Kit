# Lección 39: Temperatura lineal

> **Kit:** Kit de sensores Keyestudio 48-in-1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 39: Ilustración de temperatura lineal](../media/9a9b328cb85401dce3932f047f0979e0.png)

## Introducción

El sensor de temperatura lineal LM35 está basado en el sensor de temperatura semiconductor LM35. Puede usarse para detectar la temperatura del aire ambiente.

Este sensor ofrece un rango operativo entre 0 grados Celsius y 100 grados Celsius. La sensibilidad es de 10 mV por grado Celsius. El voltaje de salida es proporcional a la temperatura.

Este sensor se utiliza comúnmente como sensor de medición de temperatura. Existen distintos tipos, como termopares, resistencia de platino, termistores y chips de semiconductores para temperatura.

El chip se usa comúnmente en termopares para mediciones de alta temperatura.

El sensor de temperatura de resistencia de platino se utiliza en mediciones hasta 800 grados Celsius, mientras que el termistor y el sensor de temperatura semiconductor son adecuados para medir temperaturas de 100–200 grados o inferiores; en estos casos, un sensor de temperatura semiconductor simple ofrece buena linealidad y alta sensibilidad.

El sensor de temperatura lineal LM35 puede conectarse fácilmente a una shield de Arduino.

## Especificaciones

- Sensibilidad: 10 mV por grado Celsius

- Rango operativo: 0 grados Celsius a 100 grados Celsius

- Tamaño: 30*20mm

- Peso: 3g

## Diagrama de conexiones

Primero necesitas preparar las siguientes piezas antes de la prueba.

- Placa V4.0\*1

- Sensor de temperatura LM35\*1

- Cable USB\*1

- Cable jumper\*3

Luego sigue el diagrama de cableado: conecta el pin de señal del sensor al puerto A0 de la placa V4.0, el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/e2f1fc77bb6b54c35bc3d1a8834cbf6b.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
///////////////////////////////////////////////////////////////
void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 void loop()
{  int val;
    int dat;
    val=analogRead(0);//Connect LM35 on Analog 0
    dat=(500 * val) /1024;;
    Serial.print("Temp:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
///////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/95d0d43a93fd2bf1e9c7248e80edcedc.png)

Conéctalo según el diagrama anterior y sube correctamente el código a la placa, luego abre el Monitor Serie y ajusta la velocidad a 9600 baudios.

Verás el valor de temperatura actual mostrado abajo. El valor puede variar ligeramente según el lugar y el clima.

![Ilustración del resultado de ejemplo](../media/8331a0416c8006161b3227e170a3b033.jpeg)

---
