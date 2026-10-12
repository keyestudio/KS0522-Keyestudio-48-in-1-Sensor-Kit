# Lección 28: Vibración cerámica analógica

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Módulo sensor de vibración cerámica analógica](../media/2cf5c2793157816a2346a730ad064955.jpeg)

## Descripción

Este sensor de vibración se basa en un chip cerámico piezoeléctrico de vibración analógica. Aprovecha el proceso de piezoelectricidad por el que la vibración del chip cerámico genera señales eléctricas. Al vibrar el chip cerámico piezoeléctrico, el terminal de señal del sensor generará señales eléctricas.

El sensor puede usarse con el shield dedicado de sensores para Arduino, y el puerto analógico del Arduino puede percibir señales de vibración débiles, de modo que puede realizar proyectos interactivos relacionados con la vibración, como una batería electrónica.

Conecta el sensor de vibración al puerto analógico A0 del Arduino UNO. Al vibrar el sensor con distinta intensidad, verás diferentes valores de salida mostrados en el monitor serie del software de Arduino.

## Especificación

- Tensión de alimentación: 3.3V a 5V

- Corriente de trabajo：\<1mA

- Rango de temperatura de trabajo：－10℃～＋70℃

- Señal de salida：señal analógica

## Diagrama de conexión

Primero, prepara las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- sensor de vibración\*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin S del módulo al analógico A0 de la placa V4.0, conecta el pin negativo al puerto GND, y el pin NC al puerto 5V.

![Ilustración del diagrama de conexión](../media/92fce2d45b05876a7928070bd2b137da.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
///////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //Open the serial to set the baud rate as 9600bps
}
void loop()
{
int val;
val=analogRead(0); //Connect the sensor to analog interface A0
Serial.print("Vibration is ");
Serial.println(val,DEC);//Print the analog value read on serial port
delay(100);
}
///////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/e21152ca9f30274fcc658091f76f7044.png)

Cablea según el diagrama anterior y carga correctamente el código; luego abre el monitor serie y ajusta la velocidad en baudios a 9600.

Al vibrar la pastilla cerámica, verás que los datos cambian como se muestra en la figura siguiente.

![Ilustración del resultado de ejemplo](../media/4be72e831696d59b36082aa45d77a04d.jpeg)

---
